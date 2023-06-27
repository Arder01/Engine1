#pragma once

#include "Core.h"

namespace Engine1 {
	class ENGINE1_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	//To be defined in CLIENT
	Application* CreateApplication();

}