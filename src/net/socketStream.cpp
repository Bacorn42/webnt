#include "socketStream.hpp"

SocketStream::SocketStream(SOCKET& conn) :
conn(conn) {
  
}

std::string SocketStream::nextString() {
  char buffer[BufferSize];
  int bytes = recv(conn, buffer, BufferSize, 0);
  if(bytes > 0) return std::string(buffer, bytes);
  else return "";
}