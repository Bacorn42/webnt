#include "webnt.hpp"

Webnt::Webnt() :
window(Window()),
inputBox(InputBox(window.getHandle())) {
  window.run();
}