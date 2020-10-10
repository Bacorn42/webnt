#include "inputBox.hpp"

std::unordered_map<HWND, InputBox*> InputBox::inputBoxes;
std::unordered_map<HWND, WNDPROC> InputBox::inputProcedures;

InputBox::InputBox(HWND parent) {
  handle = CreateWindowW(
    L"EDIT",
    L"https://www.google.com/",
    WS_VISIBLE | WS_CHILD | WS_BORDER | ES_LEFT,
    0, 0, 800, 20,
    parent, NULL, GetModuleHandleW(NULL), NULL
  );
  inputBoxes[handle] = this;
  inputProcedures[handle] = (WNDPROC) SetWindowLongPtr(handle, GWL_WNDPROC, (LONG_PTR)inputProcedure);
}

void InputBox::addCallback(UINT msg, std::function<void(WPARAM, LPARAM)> func) {
  callbacks.insert({msg, func});
}

bool InputBox::callCallback(UINT msg, WPARAM wParam, LPARAM lParam) {
  auto found = callbacks.find(msg);
  if(found == callbacks.end()) {
    return false;
  }
  found->second(wParam, lParam);
  return true;
}

LRESULT CALLBACK InputBox::inputProcedure(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) {
  auto input = inputBoxes.find(hwnd);
  if(input != inputBoxes.end()) {
    input->second->callCallback(msg, wParam, lParam);
    auto proc = inputProcedures.find(hwnd);
    return CallWindowProc(proc->second, hwnd, msg, wParam, lParam);
  }
}