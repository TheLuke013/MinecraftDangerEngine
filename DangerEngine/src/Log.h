#ifndef LOG_CLASS_H
#define LOG_CLASS_H

#include <spdlog/spdlog.h>

namespace DE
{
	class Log
	{
	private:
		static std::shared_ptr<spdlog::logger> logger;

	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetLogger() { return logger; };

	};
}

//log macros

#define LOG_TRACE(...)		::DE::Log::GetLogger()->trace(__VA_ARGS__)
#define LOG_INFO(...)		::DE::Log::GetLogger()->info(__VA_ARGS__)
#define LOG_WARN(...)		::DE::Log::GetLogger()->warn(__VA_ARGS__)
#define LOG_ERROR(...)		::DE::Log::GetLogger()->error(__VA_ARGS__)
#define LOG_CRITICAL(...)	::DE::Log::GetLogger()->critical(__VA_ARGS__)

#endif
