#ifndef SHADER_H
#define SHADER_H
#include <string>
#include <glm/glm.hpp>
class Shader
{
private:
    int ID;
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void checkCompileErrors(int id, const char* type);
    void setFloat(const std::string &name, float value) const;
    void setMat4(const std::string &name, const glm::mat4 &mat) const;
    void setInt(const std::string &name, int value) const;
    ~Shader();
};


#endif // SHADER_H