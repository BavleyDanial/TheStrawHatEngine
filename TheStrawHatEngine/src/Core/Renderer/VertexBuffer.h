#pragma once

#include <glad/glad.h>

#include <cstdint>
#include <vector>

namespace TSH {

    class VertexBuffer
    {
    public:
        VertexBuffer() = default;
        VertexBuffer(const std::vector<float>& vertexData , uint32_t usage);
        ~VertexBuffer();

        void Bind() const;
        void UnBind() const;
    private:
        uint32_t mRendererID;
    };

}