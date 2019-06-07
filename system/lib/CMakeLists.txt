ADD_LIBRARY(simulator_system STATIC
  system.cpp
)

target_link_libraries(simulator_system pthread)

install(TARGETS simulator_system DESTINATION ${CMAKE_INSTALL_PREFIX}/lib)
