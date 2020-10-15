#include "url.hpp"

URL::URL(std::string& url) {
  parseURL(url);
}

void URL::parseURL(std::string& url) {
  int index = 0;
  index = parseProtocol(url, index);
  index = parseHost(url, index);
  index = parsePort(url, index);
  parsePath(url, index);
}

int URL::parseProtocol(std::string& url, int startIndex) {
  int endIndex = url.find("://");
  if(endIndex != std::string::npos) {
    protocol = url.substr(0, endIndex);
    return endIndex + 3;
  }
  return 0;
}

int URL::parseHost(std::string& url, int startIndex) {
  int slashIndex = url.find("/", startIndex);
  int colonIndex = url.find(":", startIndex);

  int endIndex;
  if(slashIndex == std::string::npos) {
    endIndex = (colonIndex == std::string::npos) ? url.size() - 1 : colonIndex - 1;
  }
  else if(colonIndex == std::string::npos) {
    endIndex = slashIndex - 1;
  }
  else {
    endIndex = (colonIndex < slashIndex) ? colonIndex - 1 : slashIndex - 1;
  }

  host = url.substr(startIndex, endIndex - startIndex + 1);
  return endIndex + 1;
}

int URL::parsePort(std::string& url, int startIndex) {
  if(url.at(startIndex) == ':') {
    int slashIndex = url.find("/", startIndex);
    int endIndex = (slashIndex == std::string::npos) ? url.size() - 1 : slashIndex - 1;
    port = url.substr(startIndex + 1, endIndex - startIndex);
    return endIndex;
  }
  port = "80";
  return startIndex;
}

int URL::parsePath(std::string& url, int startIndex) {
  if(startIndex < url.size() && url.at(startIndex) == '/') {
    path = url.substr(startIndex, url.size() - startIndex - 1);
    return url.size();
  }
  path = "/";
  return startIndex;
}