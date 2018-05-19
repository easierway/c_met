#include <cstdlib>
#include <iostream>

#include "cmet/cmet.h"
using cmet::Metric;

int main()
{
    log4cplus::Initializer initializer;
    log4cplus::PropertyConfigurator config(LOG4CPLUS_C_STR_TO_TSTRING("../../cmet/data/log.ini"));
    config.configure();

    if (log4cplus::Logger::exists(LOG4CPLUS_C_STR_TO_TSTRING("send"))) {
        log4cplus::Logger logger = log4cplus::Logger::getInstance(LOG4CPLUS_C_STR_TO_TSTRING("send"));
        cmet::CMet::init(logger);
    } else {
        std::cout << "no send logger found in log.ini" << std::endl;
        return EXIT_FAILURE;
    }

    CMET_SEND(Metric("Hello", "world"), Metric("Number1", 1), Metric("Number2", 2.3));
    return EXIT_SUCCESS;
}
