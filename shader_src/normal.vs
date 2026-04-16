#version 330 core
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoord;


uniform mat4 transform = mat4(1.0f);

out vec4 ourColor;
out vec2 TexCoord;

void main()
{
    gl_Position = transform * vec4(aPos,1.0f);
    TexCoord = aTexCoord;
}