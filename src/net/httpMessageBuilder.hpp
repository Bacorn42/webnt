#ifndef HTTPMESSAGEBUILDER_HPP
#define HTTPMESSAGEBUILDER_HPP

#include "httpMessage.hpp"
#include "socketStream.hpp"

class HTTPMessageBuilder {
public:
  HTTPMessageBuilder(SocketStream& ss);
  HTTPMessage build();

private:
  void readMoreBytes();
  void readChunks();
  void readCurrentChunk();
  void readStartLine(HTTPMessage& message);
  void readHeaders(HTTPMessage& message);
  void readBody(HTTPMessage& message);
  std::pair<std::string, std::string> splitHeader(std::string header);
  std::string trim(std::string&& str);

  SocketStream& socketStream;
  std::string buffer;
};

#endif /* HTTPMESSAGEBUILDER_HPP */