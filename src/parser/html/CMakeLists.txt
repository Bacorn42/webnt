set(
  SOURCES
  htmlParser.cpp
  htmlElement.cpp
)

set(
  HEADERS
  htmlParser.hpp
  htmlElement.hpp
)

add_library(htmlParser ${SOURCES} ${HEADERS})
target_compile_features(htmlParser PRIVATE cxx_std_20)