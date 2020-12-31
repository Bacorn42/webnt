#include "htmlParser.hpp"
#include <iostream>

HTMLParser::HTMLParser() {

}

HTMLParser::~HTMLParser() {
  elementDeleter(elementStack.top());
}

void HTMLParser::elementDeleter(HTMLElement* element) {
  for(HTMLElement* child : element->getChildren()) {
    elementDeleter(child);
  }
  delete element;
}

void HTMLParser::parse(std::string& html) {
  std::string type;
  bool inTag = false;
  bool closing = false;
  bool gettingType = false;
  int startIndex = 0;

  for(int i = 0; i < html.size(); i++) {
    char c = html[i];
    if(c == '<') {
      inTag = true;
      closing = false;
      gettingType = true;
      if(startIndex != i) {
        std::string text = html.substr(startIndex, i - startIndex);
        if(text.find_first_not_of(" \t\r\n") != std::string::npos) {
          HTMLElement* element = new HTMLElement("text");
          element->setText(text);
          elementStack.top()->addChild(element);
        }
      }
      startIndex = i + 1;
    } else if(c == '>') {
      if(gettingType) {
        type = html.substr(startIndex, i - startIndex);
      }
      HTMLElement* element = new HTMLElement(type);
      if(closing) {
        if(elementStack.size() > 1) {
          elementStack.pop();
        }
      } else {
        if(!elementStack.empty()) {
          elementStack.top()->addChild(element);
        }
        elementStack.push(element);
      }
      inTag = false;
      gettingType = false;
      closing = false;
      startIndex = i + 1;
    } else if(c == '/') {
      if(inTag) {
        closing = true;
        gettingType = false;
      }
    } else if(c == ' ') {
      if(gettingType) {
        type = html.substr(startIndex, i - startIndex);
        gettingType = false;
      }
    }
  }
}