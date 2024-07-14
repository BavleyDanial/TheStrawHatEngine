#include "VertexArray.h"

namespace TSH {

    VertexArray::VertexArray()
    {
        glGenVertexArrays(1, &mRendererID);
        //glBindVertexArray(mRendererID);
    }

    VertexArray::~VertexArray()
    {
        glBindVertexArray(0);
        glDeleteVertexArrays(1, &mRendererID);
    }

    void VertexArray::Bind() const
    {
        glBindVertexArray(mRendererID);
    }

    void VertexArray::UnBind() const
    {
        glBindVertexArray(0);
    }


    void VertexArray::AddBuffer(const VertexBuffer& vb, const VertexBufferLayout& layout)
    {
        Bind();
        vb.Bind();
        const auto& elements = layout.GetElements();
        uint32_t offset = 0;
        for (size_t i = 0; i < elements.size(); i++)
        {
            const auto& element = elements[i];
            glEnableVertexAttribArray(static_cast<GLuint>(i));
            glVertexAttribPointer(static_cast<GLuint>(i), element.count, element.type, element.normalized,
                layout.GetStride(), (const void*) offset);
            offset += element.count * VertexBufferElement::GetSizeOfType(element.type);
        }   
    }

}