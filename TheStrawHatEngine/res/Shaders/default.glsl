#shader vertex
#version 330 core

layout (location = 0) in vec3 vPos;
layout (location = 1) in vec3 vColor;

out vec3 oColor;

void main()
{
    gl_Position = vec4(vPos, 1.0);
    oColor = vColor;
}

#shader fragment
#version 330 core

in vec3 oColor;
layout(location = 0) out vec4 color;

void main()
{
    color = vec4(oColor, 1.0);
}