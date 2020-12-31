#ifndef WEBNT_HPP
#define WEBNT_HPP

#include <functional>
#include <iostream>
#include <windows.h>

#include "gui/window.hpp"
#include "gui/inputBox.hpp"

#include "net/connection.hpp"
#include "net/httpMessage.hpp"

class Webnt {
public:
  Webnt();

private:
  Window window;
  InputBox inputBox;
};

#endif /* WEBNT_HPP */