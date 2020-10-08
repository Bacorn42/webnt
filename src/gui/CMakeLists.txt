set(
  SOURCES
  window.cpp
)

set(
  HEADERS
  window.hpp
)

add_library(gui ${SOURCES} ${HEADERS})
target_compile_features(gui PRIVATE cxx_std_20)