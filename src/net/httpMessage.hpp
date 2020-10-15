#ifndef HTTPMESSAGE_HPP
#define HTTPMESSAGE_HPP

#include <string>
#include <unordered_map>

class HTTPMessage {
public:
  std::string getMessageString();
  void setStartLine(std::string sl) { startLine = sl; }
  void addHeader(std::string key, std::string value) { headers[key] = value; }
  void addHeader(std::pair<std::string, std::string> pair) { headers[pair.first] = pair.second; }
  void setBody(std::string b) { body = b; }
  bool hasHeader(std::string key) { return headers.contains(key); }
  std::string getHeader(std::string key) { return headers[key]; }

private:
  std::string startLine;
  std::unordered_map<std::string, std::string> headers;
  std::string body;
};

#endif /* HTTPMESSAGE_HPP */