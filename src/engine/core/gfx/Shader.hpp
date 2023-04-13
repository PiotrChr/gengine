#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <GL/glew.h>

namespace Gengine {
    class Shader {
    public:
        Shader(const std::string vertexShaderPath, const std::string fragmentShaderPath);
        ~Shader();

        void init();
        void use() const;
        GLuint getProgram() const;

    private:
        GLuint compileShader(const std::string& shaderPath, GLenum shaderType) const;
        GLuint linkProgram(GLuint vertexShader, GLuint fragmentShader) const;

        const std::string _vertexShaderPath;
        const std::string _fragmentShaderPath;
        GLuint m_program;
    };
}
