// Copyright 2021 NNTU-CS
#ifndef INCLUDE_TSTACK_H_
#define INCLUDE_TSTACK_H_

template<typename T, int size>
class TStack {
  private:
    int top;
    T arr[100];

  public:
    TStack() : top(-1) {}
    void push(T value) {
    if (isFull())
    throw std::string("Full!");
    else
    arr[++top] = value;
  }
  const T& pop() {
    if (isEmpty())
      throw std::string("Empty!");
    else
      return arr[top--];
  }
  bool isEmpty() {
    return top == -1;
  }
  bool isFull() {
    return top == 100;
  }
  const T& get() {
    return arr[top];
  }
};

#endif  // INCLUDE_TSTACK_H_
