#pragma once

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