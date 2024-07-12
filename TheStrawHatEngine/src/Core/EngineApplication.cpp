#include "EngineApplication.h"

#include <iostream>

namespace TSH {

	EngineApplication* EngineApplication::spEngineApplication = nullptr;

	EngineApplication::EngineApplication()
	{
		if (spEngineApplication)
		{
			std::cout << "There already exists an engine application instance!\n";
			return;
		}

		spEngineApplication = this;
	}

	void EngineApplication::Run()
	{
		std::cout << "Running..." << std::endl;
	}

}