#ifndef _CMET_H_
#define _CMET_H_

#include <log4cplus/logger.h>
#include <log4cplus/loggingmacros.h>
#include <log4cplus/configurator.h>
#include <log4cplus/initializer.h>

#include <sstream>

#include "macros.h"

namespace cmet {

class CMet {
public:
    static int init(log4cplus::Logger sendLogger);
    static CMet& getInstance();
public:
    log4cplus::Logger sendLogger;
};

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

}

#endif /* _CMET_H_ */
