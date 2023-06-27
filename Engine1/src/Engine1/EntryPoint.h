#pragma once


#ifdef E1_PLATFORM_WINDOWS

extern Engine1::Application* Engine1::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Engine1::CreateApplication();
	app->Run();
	delete app;
}

#endif // E1_PLATFORM_WINDOWS
