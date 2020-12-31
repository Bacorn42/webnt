#include "htmlElement.hpp"
#include <iostream>

HTMLElement::HTMLElement(std::string type) :
type(type) {
  
}

void HTMLElement::addChild(HTMLElement* child) {
  children.push_back(child);
}

void HTMLElement::print() {
  if(type == "text") {
    std::cout << text;
    return;
  }
  for(HTMLElement* child : children) {
    if(child->getType() == "head" || child->getType() == "!--") {
      continue;
    }
    std::cout << "[" << child->getType() << "]\n";
    child->print();
    std::cout << "[/" << child->getType() << "]\n";
  }
}

void HTMLElement::traverse(std::function<void(HTMLElement*)> func) {
  func(this);
}