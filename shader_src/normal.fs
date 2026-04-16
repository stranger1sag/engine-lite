#version 330 core

in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D Tex;

void main()
{
    FragColor = vec4(TexCoord, 0.0, 1.0);//UV
    FragColor = texture(Tex, TexCoord);
}