set(
  SOURCES
  window.cpp
  inputBox.cpp
)

set(
  HEADERS
  window.hpp
  inputBox.hpp
)

add_library(gui ${SOURCES} ${HEADERS})
target_compile_features(gui PRIVATE cxx_std_20)