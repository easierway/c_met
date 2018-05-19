#include <sstream>

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

class Metric {
public:
    friend std::ostream& operator<< (std::ostream& os, const Metric& metric){
        os << metric.data;
        return os;
    }

    Metric(std::string key, double value) {
        std::ostringstream oss;
        oss << "\"" << key << "\":" << value;
        data = oss.str();
    }

    Metric(std::string key, std::string value) {
        std::ostringstream oss;
        oss << "\"" << key << "\":\"" << value << "\"";
        data = oss.str();
    }

private:
    std::string data;
};

template <typename T>
std::ostringstream& metrics(std::ostringstream& oss, const T& t) {
    oss << t;
    return oss;
}

template <typename T, typename ... Args>
std::ostringstream& metrics(std::ostringstream& oss, const T& t, Args ... args) {
    oss << t << ",";
    return metrics(oss, args...);
};

#ifndef CMET_SEND
#define CMET_SEND(...)                  \
do {                                    \
    std::ostringstream oss;             \
    metrics(oss, __VA_ARGS__);          \
    LOG4CPLUS_INFO(logger, oss.str());  \
} while(0);
#endif

int main()
{
    log4cplus::Initializer initializer;
    log4cplus::BasicConfigurator config;
    config.configure();

    log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_TEXT("main"));
    LOG4CPLUS_WARN(logger, LOG4CPLUS_TEXT("Hello, World!"));

    CMET_SEND(Metric("Hello", "world"), Metric("Number", 1), Metric("Number", 2.3));

    return 0;
}

