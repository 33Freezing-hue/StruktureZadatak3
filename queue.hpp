#pragma once
#include "node.hpp"
template<typename T>
class queue{

  node<T>* first;
  node<T>* last;
  size_t size_;
  public:
  queue();
  ~queue();
  queue(const queue&);
  queue(queue&&);
  queue& operator=(const queue&);
  queue& operator=(queue&&);

  template<typename U>
  queue& push( U&&);
  queue& pop();

  size_t size();
  T front();

  void print();
};

template<typename T>
size_t queue<T>::size(){ return size_;}


template<typename T> 
T queue<T>::front(){ return first -> element;}

template<typename T>
queue<T>::queue() : first{nullptr}, last{nullptr}, size_{0} {}

template<typename T>
queue<T>::~queue(){
  while(first){
    auto tmp = first;
    first = first -> next;
    tmp = nullptr;
  }
  first = nullptr;
  last = nullptr;
  size_ = 0;
}

template<typename T>
queue<T>::queue(const queue& other) : size_{0} {
  node<T>* tmp = other.first;
  while(tmp){
  node<T>* newnode = new node<T>(tmp -> element);
  if(size_ == 0){
    first = last = newnode;
    size_++;}
  else{
  last -> next = newnode;
  last = newnode;
  size_++;
  }
  tmp = tmp -> next;
}
}

template<typename T>
queue<T>::queue(queue&& other) : first{other.first}, last{other.last}, size_{other.size_}
{
  other.first = nullptr;
  other.last = nullptr;
  other.size_ = 0;
}

template<typename T>
queue<T>& queue<T>::operator=(const queue& other) {
  size_ = 0;
  auto tmp = other.first;
  while(tmp){
    node<T>* newnode = new node<T>(tmp -> element);
    if(size_== 0){
      first = last = newnode;
      size_++;
    }
    else{
      last -> next = newnode;
      last = newnode;
      size_++;
    }
    tmp = tmp -> next;
  }
  return *this;
}

template<typename T>
queue<T>& queue<T>::operator=(queue&& other){
  std::swap(first, other.first);
  std::swap(last, other.last);
  std::swap(size_, other.size_);
}




template<typename T>
template<typename U>
queue<T>& queue<T>::push(U&& value){
  node<T>* newnode = new node<T>(std::forward<U>(value));
  if(size_ == 0){
    first = last = newnode;
  }
  else{
    last -> next = newnode;
    last =newnode;
  }
  size_ ++;
  return *this;
}

template<typename T>
queue<T>& queue<T>::pop(){
   if(size_ > 0){
    auto tmp = first;
    first = first -> next;
    tmp = nullptr;
    size_--;
  }
  return *this;
}

template<typename T>
void queue<T>::print(){
  for(auto i = first; i != nullptr; i = i-> next){
    std::cout << i->element << " ";
  }
  std::cout << std::endl;
}









