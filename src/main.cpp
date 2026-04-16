#include <SDL2/SDL.h>
#include <glad/glad.h>
#include <iostream>
#include "Components/Components.hpp"
#include "Vertex.hpp"
#include <glm/glm.hpp>
#include <vector>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "include/Shader.hpp"
#include "include/SourceLoader.hpp"
#define WINDOW_WIDTH 800.f
#define WINDOW_HEIGHT 800.f


std::vector<Transform> transforms = {
    {Vector3f(100,100,0), Vector2f(600,600), Vector2f::ONE, 0}, 
    //{Vector3f(200,200,0), Vector2f(100,100), Vector2f::ONE, 0},
    //{Vector3f(400,400,0), Vector2f(100,100), Vector2f::ONE, 0},
    //{Vector3f(300,550,0), Vector2f(100,100), Vector2f::ONE, 0},
};

void basicRender(GLuint VAO, GLuint VBO, GLuint EBO,Shader shader)
{

    static Vector2f quad[4] = {
        {-0.5f, -0.5f},// left bottom
        { 0.5f, -0.5f},// right bottom
        { 0.5f,  0.5f},// right top
        {-0.5f,  0.5f}// left top
    };
    static Vector2f texcoords[4] = {
        {0.0f, 0.0f},
        {1.0f, 0.0f},
        {1.0f, 1.0f},
        {0.0f, 1.0f}
    };
    std::vector<Vertex> outVertices;
    std::vector<GLuint> indices;
    for (size_t index = 0; index < transforms.size(); index++)
    {
        GLuint base = index * 4;  // 当前quad的起始顶点索引
    
        // 第一个三角形: 左下 -> 右下 -> 右上
        indices.push_back(base + 0);
        indices.push_back(base + 1);
        indices.push_back(base + 2);
        
        // 第二个三角形: 左下 -> 右上 -> 左上
        indices.push_back(base + 0);
        indices.push_back(base + 2);
        indices.push_back(base + 3);

        Transform t = transforms[index];
        float cosR = cos(t.rotation);
        float sinR = sin(t.rotation);

        for (int i = 0; i < 4; i++) {
            
            Vector2f p = quad[i];

            p *= t.scale;

            Vector2f r;
            r.x = p.x * cosR - p.y * sinR;
            r.y = p.x * sinR + p.y * cosR;

            r += t.position.xy;
            r = Vector2f(r.x + texcoords[i].x * t.size.x, r.y + texcoords[i].y * t.size.y);

            outVertices.push_back({r.x , r.y, 0, texcoords[i].x, texcoords[i].y});
        }
    }

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    shader.use();
    glm::mat4 transform = glm::ortho(0.f, WINDOW_WIDTH, WINDOW_HEIGHT, 0.f, -1.f, 1.f);
    shader.setMat4("transform", transform);
    
    glBindVertexArray(VAO);

   // glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(Vertex)*outVertices.size(), outVertices.data(),GL_DYNAMIC_DRAW);

   // glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size()*sizeof(GLuint),indices.data(),GL_DYNAMIC_DRAW);

    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
}
int main(int argc, char *argv[])
{
    // 初始化 SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0)
    {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    // 设置 OpenGL 版本 (3.3 Core)
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // 创建窗口
    SDL_Window *window = SDL_CreateWindow(
        "SDL2 + OpenGL",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        WINDOW_WIDTH, WINDOW_HEIGHT,
        SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    if (!window)
    {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    // 创建 OpenGL 上下文
    SDL_GLContext glContext = SDL_GL_CreateContext(window);
    if (!glContext)
    {
        printf("SDL_GL_CreateContext Error: %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    // 初始化 GLAD
    if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress))
    {
        printf("GLAD 初始化失败!\n");
        return 1;
    }

    // 设置版本
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

    // 输出 OpenGL 版本
    printf("OpenGL 版本: %s\n", glGetString(GL_VERSION));
    glViewport(0, 0, WINDOW_WIDTH, WINDOW_HEIGHT);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    const char *vShaderPath = "shader_src/normal.vs";
    const char *fShaderPath = "shader_src/normal.fs";

    Shader *shader = new Shader(vShaderPath, fShaderPath);
    SourceLoader *sl = new SourceLoader();
    sl->loadTexture("texture/floor.png");
    sl->loadTexture("texture/smile.png");
    // glEnable(GL_CULL_FACE);
    // glCullFace(GL_FRONT);
    // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    GLuint VAO;
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    GLuint VBO;
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    GLuint EBO;
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);

    // vertex attributes
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)0);
    glEnableVertexAttribArray(0);
    // texture coordinates
    glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex), (void *)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);

    // main loop
    while (true)
    {
        SDL_Event event;
        SDL_PollEvent(&event);
        if (event.type == SDL_QUIT)
        {
            break;
        }
        //glrender
        basicRender(VAO, VBO, EBO, *shader);
        // glBindTexture(GL_TEXTURE_2D, texture);

        SDL_GL_SwapWindow(window);
    }

    // 清理资源
    SDL_GL_DeleteContext(glContext);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
