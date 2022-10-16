#pragma once
#include <string>

class Logger {
	public:
		void InitLogger(std::string name);
		void LogInfo(std::string to_log);
		void LogDebug(std::string to_log);
		void LogError(std::string to_log);
};