#include "Cube.hpp"

namespace Gengine {
    Cube::Cube() : shader(TEMP_VERT_SHADER, TEMP_FRAG_SHADER) {
        
    }

    Cube::~Cube() {
        glDeleteVertexArrays(1, &VAO);
        glDeleteBuffers(1, &VBO);
        glDeleteBuffers(1, &EBO);
        glDeleteBuffers(1, &instanceVBO);
    }

    void Cube::init() {
        shader.init();

        initVertices();
        initBuffers();
    }

    void Cube::addInstance(const glm::mat4& modelMatrix) {
        instanceModelMatrices.push_back(modelMatrix);
    }

    void Cube::draw(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix) {
        shader.use();
        glBindVertexArray(VAO);

        // Pass view and projection matrices to the shader
        glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "view"), 1, GL_FALSE, glm::value_ptr(viewMatrix));
        glUniformMatrix4fv(glGetUniformLocation(shader.getProgram(), "projection"), 1, GL_FALSE, glm::value_ptr(projectionMatrix));

        // Update instance data
        glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
        glBufferData(GL_ARRAY_BUFFER, instanceModelMatrices.size() * sizeof(glm::mat4), instanceModelMatrices.data(), GL_DYNAMIC_DRAW);

        glDrawElementsInstanced(GL_TRIANGLES, 36, GL_UNSIGNED_INT, 0, instanceModelMatrices.size());
    }

    void Cube::initVertices() {
        // Cube vertices - interleaved: position (x, y, z), normal (x, y, z), texture coordinates (u, v)
        float cubeVertices[] = {
            // Front face
            -0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  1.0f, 1.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  0.0f,  1.0f,  0.0f, 1.0f,
            // Back face
            -0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 0.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  0.0f, 1.0f,
            -0.5f,  0.5f, -0.5f,  0.0f,  0.0f, -1.0f,  1.0f, 1.0f,
            // Left face
            -0.5f, -0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
            -0.5f, -0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f, -1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
            -0.5f,  0.5f, -0.5f, -1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            // Right face
            0.5f, -0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 0.0f,
            0.5f,  0.5f,  0.5f,  1.0f,  0.0f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  1.0f,  0.0f,  0.0f,  1.0f, 1.0f,
            // Bottom face
            -0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 0.0f,
            0.5f, -0.5f, -0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 0.0f,
            0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  1.0f, 1.0f,
            -0.5f, -0.5f,  0.5f,  0.0f, -1.0f,  0.0f,  0.0f, 1.0f,
            // Top face
            -0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 1.0f,
            0.5f,  0.5f, -0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 1.0f,
            0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  1.0f, 0.0f,
            -0.5f,  0.5f,  0.5f,  0.0f,  1.0f,  0.0f,  0.0f, 0.0f,
        };

        // Cube indices for indexed drawing
        unsigned int cubeIndices[] = {
            0,  1,  2,  2,  3,  0,   // Front face
            4,  5,  6,  6,  7,  4,   // Back face
            8,  9, 10, 10, 11,  8,   // Left face
           12, 13, 14, 14, 15, 12,   // Right face
           16, 17, 18, 18, 19, 16,   // Bottom face
           20, 21, 22, 22, 23, 20    // Top face
        };

        memcpy(vertices, cubeVertices, sizeof(cubeVertices));
        memcpy(indices, cubeIndices, sizeof(cubeIndices));
    }

    void Cube::initBuffers() {
        auto checkGLError = [](const std::string &message) {
            GLenum error = glGetError();
            if (error != GL_NO_ERROR) {
                std::cerr << "OpenGL Error (" << message << "): " << std::hex << error << std::endl;
            }
        };

        std::cout << "OpenGL Information" << std::endl;
        std::cout << "OpenGL version: " << glGetString(GL_VERSION) << std::endl;
        std::cout << "GLSL version: " << glGetString(GL_SHADING_LANGUAGE_VERSION) << std::endl;
        std::cout << "Vendor: " << glGetString(GL_VENDOR) << std::endl;
        std::cout << "Renderer: " << glGetString(GL_RENDERER) << std::endl;

        glGenVertexArrays(1, &VAO);
        checkGLError("glGenVertexArrays");

        glGenBuffers(1, &VBO);
        checkGLError("glGenBuffers VBO");

        glGenBuffers(1, &EBO);
        checkGLError("glGenBuffers EBO");

        glGenBuffers(1, &instanceVBO);
        checkGLError("glGenBuffers instanceVBO");


        glBindVertexArray(VAO);

        glBindBuffer(GL_ARRAY_BUFFER, VBO);
        glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

        // Vertex positions
        glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
        glEnableVertexAttribArray(0);
        // Vertex normals
        glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
        glEnableVertexAttribArray(1);
        // Vertex texture coordinates
        glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
        glEnableVertexAttribArray(2);

        // Instance model matrices
        glBindBuffer(GL_ARRAY_BUFFER, instanceVBO);
        for (int i = 0; i < 4; ++i) {
            glVertexAttribPointer(3 + i, 4, GL_FLOAT, GL_FALSE, 4 * sizeof(glm::vec4), (void*)(i * sizeof(glm::vec4)));
            glEnableVertexAttribArray(3 + i);
            glVertexAttribDivisor(3 + i, 1);
        }

        glBindVertexArray(0);
    }
}