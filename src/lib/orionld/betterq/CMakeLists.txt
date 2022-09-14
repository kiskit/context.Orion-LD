cmake_minimum_required(VERSION 2.6)

include_directories(/usr/include/antlr4-runtime)
find_library(ANTLR_LIBRARY antlr4-runtime)

SET(SOURCES
    QueryBaseListener.cpp
    QueryConcreteListener.cpp
    QueryLexer.cpp
    QueryListener.cpp
    QueryParser.cpp
        QPrint.cpp)

include_directories("${PROJECT_SOURCE_DIR}/src/lib")

ADD_LIBRARY(orionld_betterq STATIC ${SOURCES})

#add_executable(q QueryConcreteListener.cpp QueryParser.cpp QueryListener.cpp QueryLexer.cpp QueryBaseListener.cpp)
#target_link_libraries(q ${ANTLR_LIBRARY})
