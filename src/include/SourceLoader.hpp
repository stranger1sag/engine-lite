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

    static GLuint loadTexture(const std::string& sourcePath);
    static void loadTextures(const std::vector<std::string>& sourcePaths);
private:
    inline static std::unordered_map<std::string, GLuint> m_textureCache;
};