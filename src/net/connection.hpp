#ifndef CONNECTION_HPP
#define CONNECTION_HPP

#ifndef _WIN32_WINNT
#define _WIN32_WINNT 0x501
#endif /* _WIN32_WINNT */

#include <string>
#include <winsock2.h>
#include <ws2tcpip.h>

#include "httpMessage.hpp"
#include "httpMessageBuilder.hpp"
#include "url.hpp"

class Connection {
public:
  Connection(std::string& url);
  HTTPMessage sendRequest();
  SOCKET& getSocket() { return conn; }
  bool hadError() { return errorCode != 0; }
  int getErrorCode() { return errorCode; }

private:
  void setError();

  addrinfo *ai;
  SOCKET conn;
  std::string request;
  int errorCode;
};

#endif /* CONNECTION_HPP */