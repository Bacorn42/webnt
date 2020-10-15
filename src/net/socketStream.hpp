#ifndef SOCKETSTREAM_HPP
#define SOCKETSTREAM_HPP

#include <string>
#include <winsock2.h>

class SocketStream {
public:
  SocketStream(SOCKET& conn);
  std::string nextString();

private:
  static const int BufferSize = 1024;
  SOCKET& conn;
};

#endif /* SOCKETSTREAM_HPP */