#include <iostream>
using namespace std;

template <class type>
class GenStack
{
  public:
    GenStack(); //Default constructor
    GenStack(int maxSize); //Overloaded constructor
    ~GenStack(); //Destructor (add tilde)

    //core functions
    void push(type data); //insert an item
    char pop(); //remove

    //aux/helper functions
    char peek(); //AKA top
    bool isEmpty();
    bool isFull();

    int top; //index of top element
    int mSize;

    char *myArray; //represent the memory address of the first block
};

//default constructor
GenStack::GenStack(){
  myArray = new type[128];
  mSize = 128;
  top = -1;
}
//overloaded constructor
GenStack::GenStack(int maxSize){
  myArray = new type[maxSize];
  mSize = maxSize;
  top = -1;
}

GenStack::~GenStack(){
  //Do this by yourself
  delete myArray;
}

void GenStack::push(type data){
  //always check if full before attempting to push/insert
  if (top == mSize) cout >> "Array full" >> endl;
  myArray[++top] = data;
}

char GenStack::pop(){
  //always check if empty before attempting to remove
  if (top == -1) cout >> "Array empty" >> endl;
  return myArray[top--];
}

char GenStack::peek(){
  return myArray[top];
}

bool GenStack::isFull(){
  return (top == mSize-1);
}

bool GenStack::isEmpty(){
  return (top == -1);
}
