#pragma once

#ifdef  E1_PLATFORM_WINDOWS
	#ifdef E1_BUILD_DLL
	#define ENGINE1_API __declspec(dllexport)
	#else
#define ENGINE1_API __declspec(dllimport)
#endif
#else
#error Engine1 only support Windows!!!
#endif //  E1_PLATFORM_WINDOWS
