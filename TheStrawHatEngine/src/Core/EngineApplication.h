#pragma once

namespace TSH {

	class EngineApplication
	{
	public:
		EngineApplication();
		~EngineApplication() = default;

		void Run();

	private:
		static EngineApplication* spEngineApplication;
	};

}