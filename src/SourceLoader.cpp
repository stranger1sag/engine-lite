#include "include/SourceLoader.hpp"
#include <glad/glad.h>
#include <iostream>
#define STB_IMAGE_IMPLEMENTATION
#include "include/stb_image.h"
#include "SourceLoader.hpp"

SourceLoader::SourceLoader() {
    
}

SourceLoader::~SourceLoader() {
    
}
GLuint SourceLoader::loadTexture(const std::string& sourcePath) {
    if (m_textureCache.find(sourcePath) != m_textureCache.end()) {
        return m_textureCache[sourcePath];
    }
    // load image texture
    GLuint texture;
    int width, height, nrChannels;
    // stbi_set_flip_vertically_on_load(true);
    unsigned char *data = stbi_load(sourcePath.c_str(), &width, &height, &nrChannels, 0);
    //printf("Loading texture: %s (width: %d, height: %d, channels: %d)\n", sourcePath.c_str(), width, height, nrChannels);
    
    if (data) // 加载成功
    {
        glGenTextures(1, &texture);//生成纹理对象
        glBindTexture(GL_TEXTURE_2D, texture);//绑定纹理对象
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//设置缩小过滤方式
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//设置放大过滤方式
        GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
        glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);//生成纹理
        glGenerateMipmap(GL_TEXTURE_2D);//生成多级渐远纹理
        stbi_image_free(data);
    }
    else
    {
        std::cout << "Failed to load texture" << std::endl;
    }
    m_textureCache[sourcePath] = texture;
    return texture;
}
void SourceLoader::loadTextures(const std::vector<std::string> &sourcePaths)
{
    // stbi_set_flip_vertically_on_load(true);
    // load image texture
    for (auto &sourcePath : sourcePaths){
        if (m_textureCache.find(sourcePath) != m_textureCache.end()) {
            continue;
        }
        GLuint texture;
        int width, height, nrChannels;
        unsigned char *data = stbi_load(sourcePath.c_str(), &width, &height, &nrChannels, 0);
    
        if (data) // 加载成功
        {
            glGenTextures(1, &texture);//生成纹理对象
            glBindTexture(GL_TEXTURE_2D, texture);//绑定纹理对象
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);//设置缩小过滤方式
            glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);//设置放大过滤方式
            GLenum format = (nrChannels == 4) ? GL_RGBA : GL_RGB;
            glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);//生成纹理
            glGenerateMipmap(GL_TEXTURE_2D);//生成多级渐远纹理
        }
        else
        {
            std::cout << "Failed to load texture" << std::endl;
        }
        stbi_image_free(data);
        m_textureCache[sourcePath] = texture;
    }
}