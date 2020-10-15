#include "connection.hpp"

Connection::Connection(std::string& url) :
errorCode(0) {
  URL connectionURL(url);
  if(getaddrinfo(connectionURL.getHost().c_str(), connectionURL.getPort().c_str(), NULL, &ai)) {
    setError();
  }

  conn = socket(ai->ai_family, SOCK_STREAM, ai->ai_protocol);
  if(connect(conn, ai->ai_addr, ai->ai_addrlen)) {
    setError();
  }

  request = "GET " + 
    connectionURL.getPath() + 
    " HTTP/1.1\r\nHost: " + 
    connectionURL.getHost() + 
    "\r\n\r\n";
}

HTTPMessage Connection::sendRequest() {
  if(send(conn, request.c_str(), request.size(), 0) == SOCKET_ERROR) {
    setError();
  }
  SocketStream ss(conn);
  HTTPMessageBuilder builder(ss);
  return builder.build();
}

void Connection::setError() {
  errorCode = WSAGetLastError();
}