#include "EngineApplication.h"

#include <GLFW/glfw3.h>
#include <glad/glad.h>

#include <iostream>
#include <vector>

namespace TSH {

	EngineApplication* EngineApplication::spEngineApplication = nullptr;

	EngineApplication::EngineApplication()
	{
		if (spEngineApplication)
		{
			// TODO: Add Asserts
			std::cout << "There already exists an engine application instance!\n";
			return;
		}

		spEngineApplication = this;

		WindowProperties windowProps{};
		mWindow.CreateWindow(windowProps);
	}

	void EngineApplication::Shutdown()
	{
		std::cout << "Shuting down" << std::endl;
		mIsRunning = false;
	}
	
	void EngineApplication::Run()
	{
		std::cout << "Running..." << std::endl;

		const char* vertex_shader_text =
			"#version 330\n"
			"laytout (location = 0) in vec3 vPos;\n"
			"void main()\n"
			"{\n"
			"    gl_Position = (vPos, 1.0);\n"
			"}\n";
		
		const char* fragment_shader_text =
			"#version 330\n"
			"out vec4 fragment;\n"
			"void main()\n"
			"{\n"
			"    fragment = vec4(1.0, 1.0, 1.0, 1.0);\n"
			"}\n";

		std::vector<float> vertices = {
			-0.5f, -0.5f, 0.0f,
			 0.5f, -0.5f, 0.0f,
			 0.0f,  0.5f, 0.0f,
		};

		GLuint vertex_buffer;
		glGenBuffers(1, &vertex_buffer);
		glBindBuffer(GL_ARRAY_BUFFER, vertex_buffer);
		glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices.data(), GL_STATIC_DRAW);
	
		const GLuint vertex_shader = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vertex_shader, 1, &vertex_shader_text, NULL);
		glCompileShader(vertex_shader);
	
		const GLuint fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fragment_shader, 1, &fragment_shader_text, NULL);
		glCompileShader(fragment_shader);
	
		const GLuint program = glCreateProgram();
		glAttachShader(program, vertex_shader);
		glAttachShader(program, fragment_shader);
		glLinkProgram(program);
	
		const GLint vpos_location = glGetAttribLocation(program, "vPos");
	
		GLuint vertex_array;
		glGenVertexArrays(1, &vertex_array);
		glBindVertexArray(vertex_array);
		glEnableVertexAttribArray(0);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), nullptr);
		
		while (mIsRunning)
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.2f, 0.2, 0.2, 1.0f);
			glViewport(0, 0, mWindow.GetWidth(), mWindow.GetHeight());
	
			glUseProgram(program);
			glBindVertexArray(vertex_array);
			glDrawArrays(GL_TRIANGLES, 0, 3);
			
			mWindow.UpdateWindow();
		}
	}

}