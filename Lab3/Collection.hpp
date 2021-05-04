//Matthew Michael Sherlin
//CS3 KSU Spring 2021
//Feb 12, 2020

#ifndef Collection_H_
#define Collection_H_
#include <iostream>
#include "list.hpp"

//definitions to avoid problems (specialized template from Nesterenko)
//forward class definition
template <typename T>
class Collection;

//forward function definition  
template <typename T>
bool equal(const Collection<T>&, const Collection<T>&);



//class declaration
template <typename T>
class Collection{
public:
  Collection();
  void add(const T& item);
  void remove(const T& item);
  T last();
  void print();
  friend bool equal<T>(const Collection<T>&, const Collection<T>&);

private:
  node<T> *head;
};



//function definitions 
template <typename T>
Collection<T>::Collection(){
head=nullptr;
}

template <typename T>
void Collection<T>::add(const T& item){
node<T> *newnode;
newnode = new node<T>;                       
newnode->setData(item);                   
newnode->setNext(head);
head = newnode;
}

template <typename T>
void Collection<T>::remove(const T& item){
node<T> *last = nullptr; 
node<T> *ptr = head;
while (ptr != nullptr) {                     //while loop interates until ptr == nullptr
  auto next = ptr->getNext();                //next variable for next node
  if (ptr->getData() == item) {              //checks if current node == item
    if (last != nullptr)                     
	last->setNext(ptr->getNext());             //sets next ptr to the next node
    delete ptr;                              //delete node that corresponds
  }
  if (ptr != nullptr){                      //checking end node to see if it is nullptr
    last = ptr;                             //if it isn't set last to ptr and ptr to next node
    }
  ptr = next;
  }
}

template <typename T>
T Collection<T>::last(){
return head->getData();
}

template <typename T>
void Collection<T>::print(){
auto print = head;
  while(print != nullptr){                  //while loop interates until nullptr
  auto e = print->getData();                //e set to print data so that I can print it using cout
    std::cout << e << " ";
    print = print->getNext();               //print set to next link
  }
}

template <typename T>
bool equal(const Collection<T>& l1, const Collection<T>& l2){
  auto list1 = l1.head;
  auto list2 = l2.head;
  while (list1 != nullptr && list2 != nullptr) {                  //while loop iterates through until either list reaches nullptr
      if (list1->getData() != list2->getData()){                  //compares their data, if they arent the same then return false
        return false;
      }
      list1 = list1->getNext();                                    //get next data
      list2 = list2->getNext();
    }
  return true;
}

#endif