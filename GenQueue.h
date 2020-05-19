#include <iostream>
using namespace std;

class GenQueue
{
  public:
  GenQueue(); //default constructor
  GenQueue(int maxSize); //overloaded constructor
  ~GenQueue();

  void insert(char d); //enqueue
  char remove(); //dequeue

  //aux functions
  char peek();
  bool isFull();
  bool isEmpty();
  int getSize();

  //vars
  int front; //aka head
  int rear; //aka tail
  int mSize;
  int numElements;

  char *myQueue; //array
};


GenQueue::GenQueue(){
  //default constructor
  myQueue = new char[128];
  mSize = 128;
  front = 0;
  rear = -1;
  numElements = 0;
}
//overloaded constructor
GenQueue::GenQueue(int maxSize){
  myQueue = new char[maxSize];
  mSize = maxSize;
  front = 0;
  rear = -1;
  numElements = 0;
}

GenQueue::~GenQueue(){
  delete myQueue;
}

void GenQueue::insert(char d){
  //add error checking
  myQueue[++rear] = d;
  ++numElements;
}

char GenQueue::remove(){
  //error checking
  char c = '\0'; //null character
  c = myQueue[front];
  ++front;
  --numElements;
  return c;
}

char GenQueue::peek(){
  return myQueue[front];
}

bool GenQueue::isFull(){
  return (numElements == mSize);
}

bool GenQueue::isEmpty(){
  return (numElements == 0);
}

int GenQueue::getSize(){
  return numElements;
}
