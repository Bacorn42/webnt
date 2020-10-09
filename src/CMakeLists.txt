add_subdirectory(gui)

add_executable(webnt main.cpp webnt.cpp webnt.hpp ${SOURCES} ${HEADERS})
target_compile_features(webnt PRIVATE cxx_std_20)

include_directories(gui)
link_directories(gui)
target_link_libraries(webnt gui)
