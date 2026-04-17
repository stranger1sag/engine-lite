#pragma once
#include <glad/glad.h>
struct Entity
{
    Entity(GLuint id):OBJid(id){};
    Entity() = default;
    GLuint OBJid;
};
