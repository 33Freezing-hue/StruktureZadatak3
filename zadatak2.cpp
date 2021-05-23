#include<iostream>
#include "help.hpp"
#include "queue.hpp"
#include "transaction.hpp"
int main(int argc, char *argv[])
{
  double balance = 0;
  int choice;
  queue<transaction> account;
  
  while(true){
    menu(choice);
    if(choice == 1){
      addTransaction(account);

    }
    else if(choice == 2){
      applyTransaction(account, balance);

   }
    else if(choice == 3){
      showPending(account);

    }
   else if(choice == 4){
      discardPending(account);

    }
   else if(choice == 5 ){
     showBalance(balance);

    }
    else if(choice == 6 ){
      exit();
      return 0;
    }
    else {

   }
  } 

}
