#ifndef URL_HPP
#define URL_HPP

#include <string>

class URL {
public:
  URL(std::string& url);
  std::string& getProtocol() { return protocol; }
  std::string& getHost() { return host; }
  std::string& getPort() { return port; }
  std::string& getPath() { return path; }

private:
  void parseURL(std::string& url);
  int parseProtocol(std::string& url, int startIndex = 0);
  int parseHost(std::string& url, int startIndex = 0);
  int parsePort(std::string& url, int startIndex = 0);
  int parsePath(std::string& url, int startIndex = 0);

  std::string protocol;
  std::string host;
  std::string port;
  std::string path;

};

#endif /* URL_HPP */