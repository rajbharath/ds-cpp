#include <iostream>

class Stack {
  private:
    int maxSize = 2;
    int* elements;
    int top = 0;
    void doubleSize();
    void copy(int* src, int* dest);
    int isFull();
    int isEmpty();

  public:
    void push(int el);
    void display();
    int pop();
    Stack();
};

Stack::Stack()
{
    elements = new int[2];
}

int Stack::isFull()
{
    return top == maxSize;
}
int Stack::isEmpty()
{
    return top == 0;
}

void Stack::copy(int* src, int* dest) {
    // copy
    std::cout << "\n";
    for (int i = 0; i < top; i++)
    {
      std::cout << "copying: " << *(src + i);
      dest[i] = *(src + i);
    }
}

void Stack::doubleSize()
{
    maxSize *= 2;
    int* doubledTemp = new int[maxSize];
    copy(elements, doubledTemp);
    elements = doubledTemp;
}

void Stack::push(int el) {
  if (isFull()) {
    doubleSize();
  }
  std::cout << "\n"
            << "size: " << top 
            << "element: " << el 
            << "\n";
  elements[top++] = el;
}

void Stack::display()  {
  std::cout << "\n";
  for(int i=0; i < top; i++) {
    std::cout << *(elements + i)  << "\n";
  }
}

int Stack::pop() {
  if (isEmpty()) {
    return -1;
  }
  return elements[top--];
}

int main() {
  Stack stack;
  stack.push(1);
  stack.push(12);
  stack.push(13);
  stack.push(22);
  stack.push(33);
  stack.display();
  std::cout << stack.pop();
  stack.display();
  std::cout << stack.pop();
  stack.display();
  std::cout << stack.pop();
  stack.display();
  std::cout << stack.pop();
  return 0;
}

