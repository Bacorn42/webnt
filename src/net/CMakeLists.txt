set(
  SOURCES
  connection.cpp
  httpMessage.cpp
  httpMessageBuilder.cpp
  socketStream.cpp
  url.cpp
)

set(
  HEADERS
  connection.hpp
  httpMessage.hpp
  httpMessageBuilder.hpp
  socketStream.hpp
  url.hpp
)

add_library(net ${SOURCES} ${HEADERS})
target_compile_features(net PRIVATE cxx_std_20)