#include<iostream>
#include<thread>
#include<chrono>
#include "transaction.hpp"
#include "queue.hpp"
void menu(int &choice){

  std::cout << std::string(100,'\n');
  std::cout << std::string(40, '*');
  std::cout << std::endl;
  std::cout << "Actions: " << std::endl;
  std::cout << "\t 1. New transaction" << std::endl;
  std::cout << "\t 2. Apply transaction " << std::endl;
  std::cout << "\t 3. Pending transaction " << std::endl;
  std::cout << "\t 4. Discard pending transaction " << std::endl;
  std::cout << "\t 5. Ballance " << std::endl;
  std::cout << "\t 6. Exit " << std::endl;
  std::cout << std::endl;
  std::cout << "Your choice: ";
  std::cin >> choice;
  std::cin.clear();
  std::cin.ignore();
}

template<typename T>
void addTransaction(T& account){
  double amount;
  std::string date;
  std::string time;

  std::cout << std::string(100,'\n');
  std::cout <<" \t Enter transaction amount: " ;
  std::cin >> amount;
  std::cin.clear();
  std::cin.ignore();
  std::cout << std::endl;
  std::cout << "\t Enter date of transaction: ";
  
  std::getline(std::cin, date);
 
  std::cout << std::endl;
  std::cout <<  "\t Enter time of transaction: ";
  std::getline(std::cin, time);

  std::cout << std::string(100,'\n');
  std::cout << "Adding the transaction.. " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  

  transaction value(amount, date,time);
  account.push(value);

  std::cout << std::string(100,'\n');
  std::cout << "Transaction succesfully added " << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));

}
template<typename T>
void applyTransaction(queue<T>& account, double& balance){
  if(account.size() != 0){
    std::cout << std::string(100, '\n');
    std::cout << "Applying the transaction.. " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    auto transation = account.front();
    balance += transation.money();
    account.pop();
    
    
    std::cout << std::string(100,'\n');
  std::cout << "Succesfully applied " << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  else{
    std::cout << std::string(100, '\n');
    std::cout << "There are no transactions to apply..!" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
  }
}
  
template<typename T>
void discardPending(T& account){
  if(account.size() !=0){
  std::cout << std::string(100, '\n');
    std::cout << "Discarding pending transaction.. " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));

    account.pop();
   
    std::cout << std::string(100,'\n');
  std::cout << "Succesfully discarted " << std::endl;
  std::this_thread::sleep_for(std::chrono::seconds(1));
  }
  else {
  std::cout << std::string(100, '\n');
    std::cout << "No transactions to discard.. " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  }
}

template<typename T>
void showPending(T& account){
  if(account.size() != 0){
  auto x = account.front();
 
  std::cout << std::string(100,'\n');
  x.showAll();

  std::this_thread::sleep_for(std::chrono::seconds(5));
  }
  else{
    std::cout << std::string(100, '\n');
    std::cout << "No transactions pending.. " << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(1));
  } 
}

void showBalance(const double& balance){

    std::cout << std::string(100, '\n');
    std::cout << "Current account balance:  " << balance <<  std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(3));
  
}

void exit(){

  std::cout << std::string(100,'\n');
        std::cout << "Program exited succesfully.. " << std::endl;
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::cout << std::string(100,'\n');
}
















   
