#pragma once

#include <glad/glad.h>
#include <vector>

namespace TSH {

    struct VertexBufferElement
    {
        uint32_t type;
        uint32_t count;
        bool normalized;

        static uint32_t GetSizeOfType(uint32_t type)
        {
            switch (type)
            {
                case GL_FLOAT:              return sizeof(GLfloat);
                case GL_UNSIGNED_INT:       return sizeof(GLuint);
                case GL_UNSIGNED_BYTE:      return sizeof(GLubyte);
                default:                    return -1;
            }
        }
    };

    class VertexBufferLayout
    {
    public:
        VertexBufferLayout() = default;
        ~VertexBufferLayout() = default;

        template<typename T>
        void Push(uint32_t count, bool normalized=false)
        {
            static_assert(false, "This type is not supported by VertexBufferLayout");
        }

        template<>
        void Push<float>(uint32_t count, bool normalized)
        {
            mElements.push_back({ GL_FLOAT, count, normalized });
            mStride += sizeof(GLfloat) * count;
        }

        template<>
        void Push<uint32_t>(uint32_t count, bool normalized)
        {
            mElements.push_back({ GL_UNSIGNED_INT, count, normalized });
            mStride += sizeof(GLuint) * count;
        }

        template<>
        void Push<uint8_t>(uint32_t count, bool normalized)
        {
            mElements.push_back({ GL_UNSIGNED_BYTE, count, normalized });
            mStride += sizeof(GLbyte) * count;
        }

        inline const std::vector<VertexBufferElement>& GetElements() const { return mElements; }
        inline uint32_t GetStride() const { return mStride; }

    private:
        std::vector<VertexBufferElement> mElements;
        uint32_t mStride = 0;
    };

}