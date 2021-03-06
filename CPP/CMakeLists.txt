cmake_minimum_required(VERSION 3.2)
project(DesignPatterns)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(ABSTRACT_FACTORY_SRC_FILE AbstractFactory.cpp)
add_executable(abstract_factory ${ABSTRACT_FACTORY_SRC_FILE})

set(ADAPTER_SRC_FILE Adapter.cpp)
add_executable(adapter ${ADAPTER_SRC_FILE})

set(BRIDGE_SRC_FILE Bridge.cpp)
add_executable(bridge ${BRIDGE_SRC_FILE})

set(BUILDER_SRC_FILE Builder.cpp)
add_executable(builder ${BUILDER_SRC_FILE})

set(COF_SRC_FILE ChainofResponsibility.cpp)
add_executable(cof ${COF_SRC_FILE})

set(FACADE_SRC_FILE Facade.cpp)
add_executable(facade ${FACADE_SRC_FILE})

set(COMPOSITE_SRC_FILE Composite.cpp)
add_executable(composite ${COMPOSITE_SRC_FILE})

set(COMMAND_SRC_FILE Command.cpp)
add_executable(command ${COMMAND_SRC_FILE})

set(DECORATOR_SRC_FILE Decorator.cpp)
add_executable(decorator ${DECORATOR_SRC_FILE})

set(FACTORY_SRC_FILE Factory.cpp)
add_executable(factory ${FACTORY_SRC_FILE})

set(FLYWEIGHT_SRC_FILE Flyweight.cpp)
add_executable(flyweight ${FLYWEIGHT_SRC_FILE})

set(INTERPRETER_SRC_FILE Interpreter.cpp)
add_executable(interpreter ${INTERPRETER_SRC_FILE})

set(ITERATOR_SRC_FILE Iterator.cpp)
add_executable(iterator ${ITERATOR_SRC_FILE})

set(MEDIATOR_SRC_FILE Mediator.cpp)
add_executable(mediator ${MEDIATOR_SRC_FILE})

set(MEMENTO_SRC_FILE Memento.cpp)
add_executable(memento ${MEMENTO_SRC_FILE})

set(STRATEGY_SRC_FILE Strategy.cpp)
add_executable(strategy ${STRATEGY_SRC_FILE})

set(TEMPLATE_SRC_FILE Template.cpp)
add_executable(template ${TEMPLATE_SRC_FILE})

set(OBSERVER_SRC_FILE Observer.cpp)
add_executable(observer ${OBSERVER_SRC_FILE})

set(PROTOTYPE_SRC_FILE Prototype.cpp)
add_executable(prototype ${PROTOTYPE_SRC_FILE})

set(PROXY_SRC_FILE Proxy.cpp)
add_executable(proxy ${PROXY_SRC_FILE})

set(SINGLETON_SRC_FILE Singleton.cpp)
add_executable(singleton ${SINGLETON_SRC_FILE})

set(SIMPLE_FACTORY_SRC_FILE SimpleFactory.cpp)
add_executable(simple_factory ${SIMPLE_FACTORY_SRC_FILE})

set(STATE_SRC_FILE State.cpp)
add_executable(state ${STATE_SRC_FILE})

set(VISITOR_SRC_FILE Visitor.cpp)
add_executable(visitor ${VISITOR_SRC_FILE})
