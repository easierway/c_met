#ifndef _C_MET_MACROS_H_
#define _C_MET_MACROS_H_

namespace cmet {

#ifndef CMET_SEND
#define CMET_SEND(...)                                                  \
do {                                                                    \
    std::ostringstream oss;                                             \
    cmet::metrics(oss, __VA_ARGS__);                                    \
    LOG4CPLUS_INFO(cmet::CMet::getInstance().sendLogger, oss.str());    \
} while(0);
#endif

template <typename T>
std::ostringstream& metrics(std::ostringstream& oss, const T& t) {
    oss << t;
    return oss;
}

template <typename T, typename ... Args>
std::ostringstream& metrics(std::ostringstream& oss, const T& t, Args ... args) {
    oss << t << ", ";
    return metrics(oss, args...);
};

}

#endif //_C_MET_MACROS_H_
