#pragma once

#include <glad/glad.h>
#include <vector>

namespace TSH {

    class IndexBuffer
    {
    public:
        IndexBuffer() = default;
        IndexBuffer(const std::vector<uint32_t>& vertexData , uint32_t usage);
        ~IndexBuffer();

        void Bind() const;
        void UnBind() const;
    private:
        uint32_t mRendererID;
    };

}