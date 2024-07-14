#include "Window.h"
#include "EngineApplication.h"

#include <iostream>
//#include <glad/glad.h>

namespace TSH {

	/*
		TODO:
		1. Set the window properties (like fullscreen and refreshrate)
		2. Create Setters for window properties
	*/

    void Window::CreateWindow(const WindowProperties& windowProps)
    {
        if (!glfwInit())
		{
			std::cout << "GLFW couldn't be intialized!" << std::endl;
			return;
		}

        mWindowProps = windowProps;

		 /* Create a windowed mode window and its OpenGL context */
		mpWindowHandle = glfwCreateWindow(mWindowProps.width, mWindowProps.height, "Hello World", NULL, NULL);
		if (!mpWindowHandle)
		{
            std::cout << "Couldn't create window" << std::endl;
			glfwTerminate();
			return;
		}

		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		if (mWindowProps.isVsync)
			glfwSwapInterval(1);

		/* Make the window's context current */
		glfwMakeContextCurrent(mpWindowHandle);

		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return;
		}    

        glfwSetWindowCloseCallback(mpWindowHandle, [](GLFWwindow* window){
            EngineApplication::Get().Shutdown();
        });
    }

    void Window::DestroyWindow()
    {
        glfwDestroyWindow(mpWindowHandle);
    }

	void Window::UpdateWindow()
	{
		glfwPollEvents();
		glfwSwapBuffers(mpWindowHandle);
	}

}