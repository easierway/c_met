# c_met
c plus version for g_met, see: https://github.com/easierway/g_met

## example
```c++
//The following example is to demonstrate how to use CMet.
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
```

## output
<pre>
{"timestamp":"2018-05-20 01:23:30", "fileline":"/home/zxliu/workspace/caichao/mobvista/c_met/cmet/app/cmet_test.cpp:21", "Hello":"world", "Number1":1, "Number2":2.3}
</pre>
