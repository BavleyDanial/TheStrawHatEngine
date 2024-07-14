#include "IndexBuffer.h"

namespace TSH {

    IndexBuffer::IndexBuffer(const std::vector<uint32_t>& vertexData , uint32_t usage)
    {
        glGenBuffers(1, &mRendererID);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
        glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(uint32_t) * vertexData.size(), vertexData.data(), usage);
    }
    
    IndexBuffer::~IndexBuffer()
    {
        UnBind();
        glDeleteBuffers(1, &mRendererID);
    }

    void IndexBuffer::Bind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, mRendererID);
    }

    void IndexBuffer::UnBind() const
    {
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    }

}