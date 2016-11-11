

/*********************************************************************
   PROGRAM:    Assignment 7
   PROGRAMMER: ISHAN MADHU
   LOGON ID:   z1763923
   DUE DATE:   April 14, 2015

   FUNCTION:   Class declaration/implementation of the Stack class
*********************************************************************/

#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>
using namespace std;

template<class T>
struct Node
{
  T data;
  Node <T>* next;
  Node(const T&);
};

/****************************************************************
   FUNCTION: Node(const T&)
   USE: It copy the argument into Node and sets the node's pointer
        to NULL value.
   ARGUMENTS: newData - a constant T object
*****************************************************************/

template<class T>
Node<T>::Node(const T& newData)
{
  data = newData;
  next = NULL;
}

template <class T>
class Stack;

template <class T>
ostream& operator<<(ostream&, const Stack<T>&);

template <class T>
class Stack
{
  friend ostream & operator<< <>(ostream&, const Stack<T>&);

  private:
  Node<T>* stkTop;
  Node<T>* copyList(const Stack<T>&);

  public:
  Stack();
  ~Stack();
  Stack(const Stack<T>&);
  const Stack<T>& operator=(const Stack<T>&);
  void clear();
  int size()const;
  bool empty()const;
  T top()const;
  void push(const T&);
  void pop();
};

/***************************************************************
   FUNCTION: Stack()

   USE: To Initialize the top of the stack to NULL.

   ARGUMENTS: None
***************************************************************/

template <class T>

Stack<T>::Stack()
{
  stkTop = NULL;
}

/***************************************************************
   FUNCTION: Stack()

   USE: Destructor

   ARGUMENTS: None
***************************************************************/

template <class T>

Stack<T>::~Stack()
{
  clear();
}

/********************************************************************
   FUNCTION: Stack(const Stack<T>)

   USE: Copy Constructor

   ARGUMENTS: stkToCopy - a constant Stack<T> object
*****************************************************************/

template <class T>
Stack<T>::Stack(const Stack<T>& stkToCopy)
{
  stkTop = copyList(stkToCopy);
}

/********************************************************************
   FUNCTION: Node<T>* copyList()

   USE: To makes a copy of a linked Stack list

   ARGUMENTS: stkToCopy - a constant Stack<T> object
*********************************************************************/

template <class T>
Node<T>* Stack <T>::copyList(const Stack<T>& stkToCopy)
{
  Node<T>* ptr,*newNode, *last, *top=NULL;
  for(ptr = stkToCopy.stkTop; ptr != NULL; ptr = ptr->next)
  {
     newNode = new Node<T>(ptr->data);
     if(top == NULL)
         top = newNode;
     else
         last->next = newNode;
     last = newNode;
  }
 return top;
}

/****************************************************************
   FUNCTION: ostream& operator<<(ostream&, const Stack<T>&)

   USE: Overloads stream insertion operator to send entire
        Stack to standard output

   ARGUMENTS: leftOp - an ostream object
	      rightOp - a const Stack<T> object
*****************************************************************/

template <class T>
ostream& operator<<(ostream& leftOp, const Stack<T>& rightOp)
{
  Node<T>* cur;
  for(cur = rightOp.stkTop; cur != NULL; cur = cur->next)
	leftOp << cur->data << " ";

  return leftOp;
}

/****************************************************************
   FUNCTION: const Stack<T>& operator=(const Stack<T>&)

   USE: Overloads the assignment operator

   ARGUMENTS: stkToCopy - a constant Stack<T> object
*****************************************************************/

template <class T>
const Stack<T>& Stack<T>::operator=(const Stack<T>& stkToCopy)
{
  if(this != &stkToCopy)
  {
    clear();
    stkTop = copyList(stkToCopy);
  }
  return *this;
}

/****************************************************************
   FUNCTION: void clear()

   USE: Sets the stack back to an empty state, deletes all nodes
        in the stack.

   ARGUMENTS: none
*****************************************************************/

template <class T>
void Stack<T>::clear()
{
  while(!empty())
      pop();
}


/****************************************************************
   FUNCTION: int size()const

   USE: stack's size

   ARGUMENTS: none
*****************************************************************/

template <class T>

int Stack<T>::size()const
{

  int stkSize = 0;
  Node<T>* ptr;
  for(ptr = stkTop ; ptr != NULL; ptr = ptr->next)
	stkSize++;

  return stkSize;

}

/****************************************************************
   FUNCTION: bool empty()const

   USE: Checks to see if the stack is empty

   ARGUMENTS: none
*****************************************************************/

template <class T>
bool Stack<T>::empty()const
{
  if(stkTop == NULL)
     return true;
  else
     return false;
}

/****************************************************************
   FUNCTION: T top()const

   USE: Returns the data at the top of the stack

   ARGUMENTS: none
*****************************************************************/

template <class T>
T Stack<T>::top()const
{
  return stkTop->data;
}


/****************************************************************
   FUNCTION: void push()

   USE: Inserts items at the top of the stack

   ARGUMENTS: item - a constant T object

*****************************************************************/

template <class T>
void Stack<T>::push(const T& item)
{
  Node <T>* newNode = new Node<T>(item);
  newNode ->next = stkTop;
  stkTop = newNode;
}


/****************************************************************
   FUNCTION: void pop()

   USE: Removes the node at the top of socket

   ARGUMENTS: none
*****************************************************************/

template <class T>
void Stack<T>::pop()
{
  Node<T>* delNode = stkTop;
  stkTop = delNode->next;
  delete delNode;
}
#endif

