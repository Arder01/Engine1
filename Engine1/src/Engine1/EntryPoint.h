#pragma once


#ifdef E1_PLATFORM_WINDOWS

extern Engine1::Application* Engine1::CreateApplication();

int main(int argc, char** argv)
{
	Engine1::Log::Init();
	E1_CORE_WARN("Initialized warning");
	int a = 5;
	E1_INFO("Hello! var =  {0}",a);
	auto app = Engine1::CreateApplication();

	

	app->Run();
	delete app;
}

#endif // E1_PLATFORM_WINDOWS
