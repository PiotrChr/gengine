#pragma once

#include <SFML/Graphics.hpp>
#include "../../DEFINITIONS.hpp"
#include "../world/BlockTypes.hpp"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Shader.hpp"

namespace Gengine {
    class Cube {
    public:
        Cube();
        ~Cube();

        void init();
        void addInstance(const glm::mat4& modelMatrix);
        void draw(const glm::mat4& viewMatrix, const glm::mat4& projectionMatrix);

    private:
        void initVertices();
        void initBuffers();

        Shader shader;
        unsigned int VAO, VBO, EBO, instanceVBO;
        float vertices[288];
        unsigned int indices[36];
        std::vector<glm::mat4> instanceModelMatrices;
    };
}