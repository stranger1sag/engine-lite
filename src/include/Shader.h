#ifndef SHADER_H
#define SHADER_H
#include <string>
class Shader
{
private:
    int ID;
public:
    Shader(const char* vertexPath, const char* fragmentPath);
    void use();
    void checkCompileErrors(int id, const char* type);
    void setFloat(const std::string &name, float value) const;
    ~Shader();
};


#endif // SHADER_H