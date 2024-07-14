#include "EngineApplication.h"

#include "Renderer/VertexArray.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/IndexBuffer.h"
#include "Renderer/Shader.h"

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

		std::vector<float> vertices = {
			-0.5f, -0.5f, 0.0f,	-1.0f,	0.0f, 0.0f, // 0
			 0.5f, -0.5f, 0.0f,  1.0f,	0.0f, 0.0f, // 1
			 0.5f,  0.5f, 0.0f,  1.0f,  1.0f, 0.0f, // 2
			-0.5f,  0.5f, 0.0f,	-1.0f,  1.0f, 0.0f, // 3
		};

		std::vector<uint32_t> indices = {
			0, 1, 2,
			2, 3, 0,
		};

		VertexArray va;
		VertexBuffer vb(vertices, GL_STATIC_DRAW);
		IndexBuffer ib(indices, GL_STATIC_DRAW);
		VertexBufferLayout vbl;
		vbl.Push<float>(3);
		vbl.Push<float>(3);
		va.AddBuffer(vb, vbl);

		// TODO: Use a shader library and change location of res folder based on configuration?
		Shader programShader("res/Shaders/default.glsl");
		programShader.Bind();
		
		while (mIsRunning)
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glClearColor(0.2f, 0.2f, 0.2f, 1.0f);
			glViewport(0, 0, mWindow.GetWidth(), mWindow.GetHeight());
	
			programShader.Bind();
			va.Bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indices.data());
			
			mWindow.UpdateWindow();
		}
	}

}