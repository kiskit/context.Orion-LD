cmake_minimum_required(VERSION 2.6)

include_directories(/usr/include/antlr4-runtime)
find_library(ANTLR_LIBRARY antlr4-runtime)

SET(SOURCES
        ScopesqBaseListener.cpp
        ScopesqConcreteListener.cpp
        ScopesqLexer.cpp
        ScopesqListener.cpp
        ScopesqParser.cpp
        ScopesQ.cpp
        )

include_directories("${PROJECT_SOURCE_DIR}/src/lib")

ADD_LIBRARY(orionld_scopeq STATIC ${SOURCES})

#add_executable(q ScopeConcreteListener.cpp ScopeParser.cpp ScopeListener.cpp ScopeLexer.cpp ScopeBaseListener.cpp)
#target_link_libraries(q ${ANTLR_LIBRARY})
