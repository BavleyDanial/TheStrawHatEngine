#include "EngineApplication.h"

#include <iostream>
#include <GLFW/glfw3.h>

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

		/* Loop until the user closes the window */
		while (mIsRunning)
		{
			/* Render here */
			glClear(GL_COLOR_BUFFER_BIT);
			mWindow.UpdateWindow();
		}
	}

}