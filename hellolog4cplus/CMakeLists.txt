# apps
ADD_EXECUTABLE(loghelloworld app/loghelloworld.cpp)
TARGET_LINK_LIBRARIES(loghelloworld ${LOG4CPLUS_LIBRARIES})

ADD_EXECUTABLE(logmacros app/logmacros.cpp)
TARGET_LINK_LIBRARIES(logmacros ${LOG4CPLUS_LIBRARIES})

ADD_EXECUTABLE(loglevel app/loglevel.cpp)
TARGET_LINK_LIBRARIES(loglevel ${LOG4CPLUS_LIBRARIES})

#ADD_EXECUTABLE(timeformat app/timeformat.cpp)
#TARGET_LINK_LIBRARIES(timeformat ${LOG4CPLUS_LIBRARIES})

ADD_EXECUTABLE(logpatternlayout app/logpatternlayout.cpp)
TARGET_LINK_LIBRARIES(logpatternlayout ${LOG4CPLUS_LIBRARIES})

ADD_EXECUTABLE(logpropertyconfig app/logpropertyconfig.cpp)
TARGET_LINK_LIBRARIES(logpropertyconfig ${LOG4CPLUS_LIBRARIES})
