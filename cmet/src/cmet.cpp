#include "cmet/cmet.h"

namespace cmet {

int CMet::init(log4cplus::Logger sendLogger) {
    getInstance().sendLogger = sendLogger;
    return 0;
}
CMet& CMet::getInstance() {
    static CMet instance;
    return instance;
}

}
