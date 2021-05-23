#pragma once
#include<iostream>
template<typename T>
class node{
  public:
  T element;
  node<T>* next;

  template<typename U>
    node(U&& value) : element{std::forward<T>(value)}, next{nullptr} {}
};
