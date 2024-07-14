#pragma once

#define GLFW_INCLUDE_NONE
#include "Window.h"

namespace TSH {

	class EngineApplication
	{
	public:
		EngineApplication();
		~EngineApplication() = default;

		static EngineApplication& Get() { return *spEngineApplication; }

		void Run();
		void Shutdown();

	private:
		static EngineApplication* spEngineApplication;
		Window mWindow;

		bool mIsRunning = true;
	};

}