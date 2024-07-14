#pragma once

#include <glad/glad.h>

#include "VertexBuffer.h"
#include "VertexBufferLayout.h"

#include <cstdint>

namespace TSH {

    class VertexArray
    {
    public:
        VertexArray();
        ~VertexArray();

        void Bind() const;
        void UnBind() const;

        void AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout);
    private:
        uint32_t mRendererID;
    };

}