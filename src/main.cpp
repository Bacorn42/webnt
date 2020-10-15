#include <winsock2.h>

#include "webnt.hpp"

int main() {
  WSADATA wd;
  WSAStartup(MAKEWORD(2, 2), &wd);
  Webnt webnt;
  WSACleanup();
}