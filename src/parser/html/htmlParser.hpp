#ifndef HTMLPARSER_HPP
#define HTMLPARSER_HPP

#include <stack>

#include "htmlElement.hpp"

class HTMLParser {
  public:
    HTMLParser();
    ~HTMLParser();
    void parse(std::string& html);
    HTMLElement* getElementTree() { return elementStack.top(); }

  private:
    void elementDeleter(HTMLElement* element);

    std::stack<HTMLElement*> elementStack;
};

#endif /* HTMLPARSER_HPP */