#include "webnt.hpp"
#include "parser/html/htmlParser.hpp"
#include "parser/html/htmlElement.hpp"

Webnt::Webnt() :
window(Window()),
inputBox(InputBox(window.getHandle())) {
  inputBox.addCallback(WM_KEYDOWN, [this](WPARAM wParam, LPARAM lParam){
    if(wParam == VK_RETURN) {
      std::string url = inputBox.getText();
      Connection conn(url);
      if(!conn.hadError()) {
        HTTPMessage message = conn.sendRequest();
        std::string html = message.getBody();
        HTMLParser parser;
        parser.parse(html);
        HTMLElement* elementTree = parser.getElementTree();
        int counter = 0;
        std::function<void(HTMLElement*)> traverseCallback = [this, &counter, &traverseCallback](HTMLElement* element) {
          if(element->getType() == "text") {
            TextOutA(GetDC(window.getHandle()), 8, 20 + 16*counter, element->getText().c_str(), element->getText().size());
            counter++;
          }
          for(HTMLElement* child : element->getChildren()) {
            if(child->getType() != "head" && child->getType() != "!--") {
              child->traverse(traverseCallback);
            }
          }
        };
        elementTree->traverse(traverseCallback);
      }
    }
  });
  window.run();
}