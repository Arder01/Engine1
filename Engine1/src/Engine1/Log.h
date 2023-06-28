#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Engine1 {
	class ENGINE1_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;  
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};

}
//core log macros
#define E1_CORE_ERROR(...)::Engine1::Log::GetCoreLogger()->error(__VA_ARGS__)
#define E1_CORE_WARN(...)::Engine1::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define E1_CORE_INFO(...)::Engine1::Log::GetCoreLogger()->info(__VA_ARGS__)
#define E1_CORE_TRACE(...)::Engine1::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define E1_CORE_FATAL(...)::Engine1::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log macros
#define E1_ERROR(...)::Engine1::Log::GetClientLogger()->error(__VA_ARGS__)
#define E1_WARN(...)::Engine1::Log::GetClientLogger()->warn(__VA_ARGS__)
#define E1_INFO(...)::Engine1::Log::GetClientLogger()->info(__VA_ARGS__)
#define E1_TRACE(...)::Engine1::Log::GetClientLogger()->trace(__VA_ARGS__)
#define E1_FATAL(...)::Engine1::Log::GetClientLogger()->fatal(__VA_ARGS__)