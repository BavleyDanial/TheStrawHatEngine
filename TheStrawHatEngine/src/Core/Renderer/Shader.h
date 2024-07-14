#pragma once

#include <glad/glad.h>

#include <string>
#include <optional>

namespace TSH {

    struct ShaderSource
    {
        std::optional<std::string> vertex;
        std::optional<std::string> fragment;
        std::optional<std::string> geometry;
        std::optional<std::string> compute;
    };

    enum class ShaderType
    {
        UNKNOWN = 0,
        VERTEX,
        FRAGMENT,
        GEOMETRY,
        COMPUTE
    };

    class Shader
    {
    public:
        Shader() = default;
        Shader(const std::string& filepath);
       ~Shader();

       void Bind();
       void UnBind();

       // TODO: Change to using glm instead
       void SetUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
    private:
        int GetUniformLocation(const std::string& name);
    private:
        const ShaderSource ParseShader();
        uint32_t CompileAndLinkShader(const std::string& source, uint32_t type);

    private:
        uint32_t mRendererID;
        std::string mFilePath;
    };

}