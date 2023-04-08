// Copyright 2021 NNTU-CS
#include <string>
#include <map>
#include "tstack.h"

int priority(char x) {
  if (x == '(') return 0;
  else if (x == ')') return 1;
  else if (x == '+' || x == '-') return 2;
  else if (x == '*' || x == '/') return 3;
  else 
    return -1;
}

int operations(char x) {
  return (x == '+' || x == '-' \
          || x == '*' || x == '/');
}

int number(char x) {
  return (x >= '0' && x <= '9');
}

int conv(char x) {
  char mas[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
  for (int i = 0; i < 10; i++) {
    if (x == mas[i])
      return i;
  }
  return -1;
}



std::string infx2pstfx(std::string inf) {
  TStack<char>  stack1;
  std::string str = "";
  for (int i = 0; i < inf.length(); i++) {
    if (number(inf[i])) {
      str += inf[i];
      str += " ";
    } else if (inf[i] == '(') {
      stack1.push(inf[i]);
    } else if (inf[i] == ')') {
      while (!stack1.isempty() && stack1.get() != '(') {
        str += stack1.get();
        str += " ";
        stack1.pop();
      }
      stack1.pop();
    } else if (operations(inf[i])) {
      while (!stack1.isempty() && priority(stack1.get()) \
             >= priority(inf[i])) {
        str += stack1.get();
        str += " ";
        stack1.pop();
      }
      stack1.push(inf[i]);
    }
  }
  while (!stack1.isempty()) {
    str += stack1.get();
    str += " ";
    stack1.pop();
  }
  str.erase(str.length() - 1, 1);
  return str;
}

int eval(std::string pref) {
TStack<int> stack2;
  for (int i = 0; i < pref.length(); i+=2) {
    if (number(pref[i])) {
      stack2.push(conv(pref[i]));
    } else if (operations(pref[i])) {
      int b = stack2.get();
      stack2.pop();
      int a = stack2.get();
      stack2.pop();
      if (pref[i] == '+') {
        stack2.push(a + b);
      } else if (pref[i] == '-') {
        stack2.push(a - b);
      } else if (pref[i] == '*') {
        stack2.push(a * b);
      } else if (pref[i] == '/') {
        stack2.push(a / b);
      }
    }
  }
  return stack2.get();
}
