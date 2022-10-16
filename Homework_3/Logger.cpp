#include "Logger.h"
#include <boost/log/core.hpp>
#include <boost/log/trivial.hpp>
#include <boost/log/expressions.hpp>
#include <boost/log/utility/setup/file.hpp>
#include <boost/log/utility/setup/common_attributes.hpp>

void Logger::InitLogger(std::string name){
    boost::log::register_simple_formatter_factory<boost::log::trivial::severity_level, char>("Severity");

    boost::log::add_file_log(
        boost::log::keywords::file_name = name,
        boost::log::keywords::format = "[%TimeStamp%] [%ThreadID%] [%Severity%] %Message%"
    );

    boost::log::core::get()->set_filter(
        boost::log::trivial::severity >= boost::log::trivial::info
    );

    boost::log::add_common_attributes();
}

void Logger::LogInfo(std::string to_log) {
    BOOST_LOG_TRIVIAL(info) << to_log;
}

void Logger::LogDebug(std::string to_log) {
    BOOST_LOG_TRIVIAL(debug) << to_log;
}

void Logger::LogError(std::string to_log) {
    BOOST_LOG_TRIVIAL(error) << to_log;
}