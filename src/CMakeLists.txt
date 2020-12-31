add_subdirectory(gui)
add_subdirectory(net)
add_subdirectory(parser)

add_executable(webnt main.cpp webnt.cpp webnt.hpp ${SOURCES} ${HEADERS})
target_compile_features(webnt PRIVATE cxx_std_20)

include_directories(gui)
link_directories(gui)
target_link_libraries(webnt gui)

include_directories(net)
link_directories(net)
target_link_libraries(webnt net)

include_directories(parser)
link_directories(parser)
target_link_libraries(webnt htmlParser)

if(WIN32)
  target_link_libraries(webnt ws2_32)
endif()