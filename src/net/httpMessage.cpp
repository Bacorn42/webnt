#include "httpMessage.hpp"

std::string HTTPMessage::getMessageString() {
  std::string headersString;
  for(auto& header : headers) {
    headersString += header.first + ": " + header.second + "\n";
  }

  return startLine + "\n" +
    headersString + "\n" +
    body;
}