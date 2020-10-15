#include "httpMessageBuilder.hpp"

HTTPMessageBuilder::HTTPMessageBuilder(SocketStream& ss) :
socketStream(ss) {

}

HTTPMessage HTTPMessageBuilder::build() {
  HTTPMessage message;
  
  readStartLine(message);
  readHeaders(message);
  readBody(message);

  return message;
}

void HTTPMessageBuilder::readMoreBytes() {
  buffer += socketStream.nextString();
}

void HTTPMessageBuilder::readStartLine(HTTPMessage& message) {
  int index = buffer.find("\n");
  while(index == std::string::npos) {
    readMoreBytes();
    index = buffer.find("\n");
  }
  message.setStartLine(buffer.substr(0, index));
  buffer.erase(0, index + 1);
}

void HTTPMessageBuilder::readHeaders(HTTPMessage& message) {
  bool finished = false;
  while(!finished) {
    int index = buffer.find("\n");
    while(index == std::string::npos) {
      readMoreBytes();
      index = buffer.find("\n");
    }
    auto header = splitHeader(buffer.substr(0, index));
    if(header.second == "") {
      finished = true;
    } else {
      message.addHeader(header);
    }
    buffer.erase(0, index + 1);
  }
}

void HTTPMessageBuilder::readBody(HTTPMessage& message) {
  if(message.hasHeader("Content-Length")) {
    int contentLength = std::stoi(message.getHeader("Content-Length"));
    while(buffer.size() != contentLength) {
      readMoreBytes();
    }
    message.setBody(buffer);
  } else {
    message.setBody("");
  }
  buffer.clear();
}

std::pair<std::string, std::string> HTTPMessageBuilder::splitHeader(std::string header) {
  int colonIndex = header.find(":");
  if(colonIndex != std::string::npos) {
    return std::make_pair(
      trim(header.substr(0, colonIndex)),
      trim(header.substr(colonIndex + 1))
    );
  }
  return std::make_pair(header, "");
}

std::string HTTPMessageBuilder::trim(std::string&& str) {
  int startIndex = str.find_first_not_of(" \t");
  int endIndex = str.find_last_not_of(" \t\r\n");
  return str.substr(startIndex, endIndex - startIndex + 1);
}