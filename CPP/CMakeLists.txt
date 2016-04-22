cmake_minimum_required(VERSION 3.2)
project(DesignPatterns)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(ADAPTER_SRC_FILE Adapter.cpp)
add_executable(adapter ${ADAPTER_SRC_FILE})

set(BUILDER_SRC_FILE Builder.cpp)
add_executable(builder ${BUILDER_SRC_FILE})

set(FACADE_SRC_FILE Facade.cpp)
add_executable(facade ${FACADE_SRC_FILE})

set(COMPOSITE_SRC_FILE Composite.cpp)
add_executable(composite ${COMPOSITE_SRC_FILE})

set(COMMAND_SRC_FILE Command.cpp)
add_executable(command ${COMMAND_SRC_FILE})

set(DECORATOR_SRC_FILE Decorator.cpp)
add_executable(decorator ${DECORATOR_SRC_FILE})

set(FACTORY_SRC_FILE factory.cpp)
add_executable(factory ${FACTORY_SRC_FILE})

set(STRATEGY_SRC_FILE Strategy.cpp)
add_executable(strategy ${STRATEGY_SRC_FILE})

set(TEMPLATE_SRC_FILE Template.cpp)
add_executable(template ${TEMPLATE_SRC_FILE})

set(PROXY_SRC_FILE Proxy.cpp)
add_executable(proxy ${PROXY_SRC_FILE})