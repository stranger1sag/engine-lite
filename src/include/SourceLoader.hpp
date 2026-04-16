#pragma once
#include <string>
#include <vector>
#include <unordered_map>
#include <glad/glad.h>
class SourceLoader
{
public:
    SourceLoader();
    ~SourceLoader();

    GLuint loadTexture(const std::string& sourcePath);
    void loadTextures(const std::vector<std::string>& sourcePaths);
private:
    std::unordered_map<std::string, GLuint> m_textureCache;
};