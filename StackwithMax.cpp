#include <bits/stdc++.h>

using namespace std;

/*
This code provide O(1) time complexity for retrieving Max variable inside the Stack
Stack works by linkedlist data structure

*/
struct Node{
   int value;
   Node * next;
};

// Standart Stack Api and Class
// with Max variable
class Stack{
  public:
    int max;
    Node* top;
    Stack(){
      top = 0;
      max = -1;
    };
    void push(int e);
    int pop();
    int getMax();
    bool isEmpty();
};

// if new "element" greater than "Max". (2 * element - Max = X)
// push this "X" variable into stack and also (Max = element) ;
void Stack::push(int e){

  if(e>this->max){
    int temp = e;
    e = 2 * e - this->max;
    this->max = temp;
  }
  Node *node = new Node;
  node->value = e;
  node->next = top;
  top = node;
}

int Stack::getMax(){
  return this->max;
}
// if pop "element" greater than "Max". It means we retrieve the max variable.
// we retrieve "X". ("X" = 2 * max - "element")
int Stack::pop(){
  int value = top->value;
  Node *top = this->top;
  this->top = top->next;
  if(value>this->max){
    int temp = 2 * this->max - value;
    value = this->max;
    this->max = temp;
  }
  return value;
}
bool Stack::isEmpty(){
  return this->top == 0;
}

int main()
{
  Stack stack;
  cout << "Max "<<stack.getMax()<<endl;
  stack.push(2);
  cout << "Max "<<stack.getMax()<<endl;
  stack.push(3);
  cout << "Max "<<stack.getMax()<<endl;
  stack.push(5);
  cout << "Max "<<stack.getMax()<<endl;
  stack.push(20);
  cout << "Max "<<stack.getMax()<<endl;
  stack.push(7);
  cout << "Max "<<stack.getMax()<<endl;
  stack.push(8);
  cout << "Max "<<stack.getMax()<<endl;
  cout << stack.pop()<<endl;
  cout << "Max "<<stack.getMax()<<endl;
  return 0;
}
