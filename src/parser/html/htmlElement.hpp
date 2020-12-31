#ifndef HTMLELEMENT_HPP
#define HTMLELEMENT_HPP

#include <functional>
#include <string>
#include <vector>

class HTMLElement {
  public:
    HTMLElement(std::string type);
    void addChild(HTMLElement* child);
    void print();
    void traverse(std::function<void(HTMLElement*)> func);
    void setText(std::string text) { this->text = text; }
    std::string getText() { return text; }
    std::string getType() { return type; }
    std::vector<HTMLElement*>& getChildren() { return children; }

  private:
    std::string type;
    std::string text;
    std::vector<HTMLElement*> children;
};

#endif /* HTMLELEMENT_HPP */