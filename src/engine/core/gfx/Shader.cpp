#include "Shader.hpp"

namespace Gengine {
    Shader::Shader(const std::string vertexShaderPath, const std::string fragmentShaderPath): _vertexShaderPath(vertexShaderPath), _fragmentShaderPath(fragmentShaderPath) {
        
    }
    
    Shader::~Shader() {
        glDeleteProgram(m_program);
    }

    void Shader::init() {
        std::cout << "Compiling shader: " << _vertexShaderPath << std::endl;
        std::cout << "Compiling shader: " << _fragmentShaderPath << std::endl;
        GLuint vertexShader = compileShader(_vertexShaderPath, GL_VERTEX_SHADER);
        GLuint fragmentShader = compileShader(_fragmentShaderPath, GL_FRAGMENT_SHADER);

        m_program = linkProgram(vertexShader, fragmentShader);

        glDeleteShader(vertexShader);
        glDeleteShader(fragmentShader);
    }

    void Shader::use() const {
        glUseProgram(m_program);
    }

    GLuint Shader::getProgram() const {
        return m_program;
    }

    GLuint Shader::compileShader(const std::string& shaderPath, GLenum shaderType) const {
        std::ifstream shaderFile(shaderPath);
        if (!shaderFile.is_open()) {
            throw std::runtime_error("Failed to open shader file: " + shaderPath);
        }

        std::stringstream shaderStream;
        shaderStream << shaderFile.rdbuf();
        shaderFile.close();

        std::string shaderSource = shaderStream.str();
        const char* shaderSourceCStr = shaderSource.c_str();

        GLuint shader = glCreateShader(shaderType);
        glShaderSource(shader, 1, &shaderSourceCStr, nullptr);
        glCompileShader(shader);

        GLint success;
        glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetShaderInfoLog(shader, sizeof(infoLog), nullptr, infoLog);
            std::string shaderTypeName = (shaderType == GL_VERTEX_SHADER) ? "VERTEX" : "FRAGMENT";
            throw std::runtime_error("Failed to compile " + shaderTypeName + " shader: " + infoLog);
        }

        return shader;
    }

    GLuint Shader::linkProgram(GLuint vertexShader, GLuint fragmentShader) const {
        GLuint program = glCreateProgram();
        glAttachShader(program, vertexShader);
        glAttachShader(program, fragmentShader);
        glLinkProgram(program);

        GLint success;
        glGetProgramiv(program, GL_LINK_STATUS, &success);
        if (!success) {
            char infoLog[512];
            glGetProgramInfoLog(program, sizeof(infoLog), nullptr, infoLog);
            throw std::runtime_error("Failed to link shader program: " + std::string(infoLog));
        }

        return program;
    }
}

