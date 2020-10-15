#include "webnt.hpp"

Webnt::Webnt() :
window(Window()),
inputBox(InputBox(window.getHandle())) {
  inputBox.addCallback(WM_KEYDOWN, [this](WPARAM wParam, LPARAM lParam){
    if(wParam == VK_RETURN) {
      std::string url = inputBox.getText();
      Connection conn(url);
      if(!conn.hadError()) {
        HTTPMessage message = conn.sendRequest();
        std::cout << message.getMessageString();
      }
    }
  });
  window.run();
}