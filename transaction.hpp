#pragma once
#include<iostream>
class transaction{
  private:
  double amount;
  std::string date;
  std::string time;

  public:
 transaction(double a, std::string b, std::string c) : amount{a}, date{b}, time{c}{}
  double money(){return amount;}

  void showAll();

};

void transaction::showAll(){
  std::cout << std::string(100,'\n');
  
  std::cout << "Pending transaction amount: " << amount << std::endl;
  std::cout << std::endl;

  std::cout << "Pending transaction date: " << date << std::endl;
  std::cout << std::endl;

  std::cout << "Pending transaction time: " << time << std::endl;
  std::cout << std::endl;
}

