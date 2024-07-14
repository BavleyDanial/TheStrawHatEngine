#include "VertexBuffer.h"

namespace TSH {

    VertexBuffer::VertexBuffer(const std::vector<float>& vertexData , uint32_t usage)
    {
        glGenBuffers(1, &mRendererID);
        glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
        glBufferData(GL_ARRAY_BUFFER, sizeof(float) * vertexData.size(), vertexData.data(), usage);
    }
    
    VertexBuffer::~VertexBuffer()
    {
        UnBind();
        glDeleteBuffers(1, &mRendererID);
    }

    void VertexBuffer::Bind() const
    {
        glBindBuffer(GL_ARRAY_BUFFER, mRendererID);
    }

    void VertexBuffer::UnBind() const 
    {
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

}