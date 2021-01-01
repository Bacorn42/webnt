#include "socketStream.hpp"

SocketStream::SocketStream(SOCKET& conn) :
conn(conn) {
  
}

std::string SocketStream::nextString(int size) {
  char buffer[BufferSize];
  int bytes = recv(conn, buffer, std::min(BufferSize, size), 0);
  if(bytes > 0) return std::string(buffer, bytes);
  else return "";
}

std::string SocketStream::nextChunk() {
  int chunkLength = getChunkLength();
  std::string chunk;
  while(chunkLength > 0) {
    std::string chunkFragment = nextString(chunkLength);
    chunk += chunkFragment;
    chunkLength -= chunkFragment.size();
  }
  consumeNewline();
  
  return chunk;
}

int SocketStream::getChunkLength() {
  char buffer[BufferSize];
  int bufferPtr = 0;
  do {
    int bytes = recv(conn, buffer + bufferPtr, 1, 0);
    bufferPtr += bytes;
  } while(buffer[bufferPtr - 1] != '\n');

  int chunkLength = std::stoi(std::string(buffer, bufferPtr - 2), nullptr, 16);
  return chunkLength;
}

void SocketStream::consumeNewline() {
  nextString(2); // \r\n
}