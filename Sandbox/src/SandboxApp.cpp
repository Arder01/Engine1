
#include <Engine1.h>
  
class Sandbox : public Engine1::Application
{
public:
	Sandbox()
	{
	}
	~Sandbox()
	{
	}
};

Engine1::Application* Engine1::CreateApplication()
{
	return new Sandbox();
}