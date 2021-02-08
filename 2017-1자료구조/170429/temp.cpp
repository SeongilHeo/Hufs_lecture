/*
 * temp.cpp
 *
 *  Created on: 2017. 4. 27.
 *      Author: tjddl
 */
#include <iostream>
#include <cstring>
using namespace std;

struct Books{
   string b_id;
   string b_name;
   int b_price;
   int b_num;
};

typedef Books ItemType;

struct Node{
   ItemType info;
   Node* next;
};

class List{
   Node* head;
   Node* sell;
public:
   List();
   ~List();
   bool find(string);
   bool find_sell(string);
   void N(Books);
   void R(string, int);
   void S(string, int);
   void D(string);
   void I(string);
   void P();
   void L();
};
List::List(){
   sell = NULL;
   head = NULL;
}
/*****************************************************************************************/
bool List::find(string a){
   Node* location = head;

   while(location != NULL){
      if(location->info.b_id == a){
         return true;
      }
      location = location->next;
   }
   return false;
}
/*****************************************************************************************/
bool List::find_sell(string a){
   Node* location = sell;

   while(location != NULL){
      if(location->info.b_id == a){
         return true;
      }
      location = location->next;
   }
   return false;
}

void List::N(Books book){
   Node* newNode = new Node;
   newNode->info = book;

   if(find(book.b_id) == true){
      cout <<"error: 1"<< endl;
      return;
   }

   if(head == NULL){
      newNode->next = head;
      head = newNode;
   }
   else if(head->info.b_id >= newNode->info.b_id){
      newNode->next = head;
      head = newNode;
   }
   else{
      Node* before = head;
      while(before->next != NULL && before->next->info.b_id < newNode->info.b_id){
         before = before->next;
      }
      newNode->next = before->next;
      before->next = newNode;
   }
}
/******************************************************************************************/
void List::R(string id, int amount){
   if(find(id) == false){
      cout <<"error: 2"<< endl;
      return;
   }
   Node* location = head;
   while(location->info.b_id != id){
      location = location->next;
   }
   location->info.b_num += amount;
}
/******************************************************************************************/
void List::S(string id, int amount){
   if(find(id) == false){
      cout <<"error: 2"<< endl;
      return;
   }
   Node* search = head;
   while(search->info.b_id != id){
      search = search->next;
   }
   if((search->info.b_num - amount) < 0){
      cout <<"error: 3"<< endl;
      return;
   }
   else{
      search->info.b_num -= amount;

      Node* newNode = new Node;
      newNode->info = search->info;
      newNode->info.b_num = amount;

      if(sell == NULL){
         newNode->next = sell;
         sell = newNode;
      }
      else if(find_sell(id) == true){
         Node* search_sell = sell;
         while(search_sell->info.b_id != id){
            search_sell = search_sell->next;
         }
         search_sell->info.b_num += amount;
      }
      else{
         Node* before = sell;
         while(before->next != NULL && before->next->info.b_id < newNode->info.b_id){
            before = before->next;
         }
         newNode->next = before->next;
         before->next = newNode;
      }
   }
}
/******************************************************************************************/
void List::D(string id){
   if(find(id) == false){
      cout <<"error: 2"<< endl;
      return;
   }
   Node* before = head;

   if(head->info.b_id == id){
      Node* cut;
      cut = head;
      head = head->next;
      delete cut;
   }
   else{
      while(before->next->next != NULL && before->next->info.b_id != id){
         before = before->next;
      }
      if(before->next->next == NULL){
         Node* end;
         end = before->next;
         before->next = NULL;
         delete end;
      }
      else if(before->next->info.b_id == id){
         Node* cut;
         cut = before->next;
         before->next = before->next->next;
         delete cut;
      }
   }
}
/******************************************************************************************/
void List::I(string id){
   if(find(id) == false){
      cout <<"error: 2"<< endl;
      return;
   }
   Node* search = head;
   while(search->info.b_id != id){
      search = search->next;
   }
   cout << search->info.b_id <<" "<< search->info.b_name <<" "<< search->info.b_price <<" "<< search->info.b_num << endl;
}
/*****************************************************************************************/
void List::P(){
   Node* print = head;

   while(print != NULL){
      cout << print->info.b_id <<" "<< print->info.b_name <<" "<< print->info.b_price <<" "<< print->info.b_num << endl;
      print = print->next;
   }
}
/******************************************************************************************/
void List::L(){
   Node* print = sell;

   while(print != NULL){
      cout << print->info.b_id <<" "<< print->info.b_name <<" "<< print->info.b_price <<" "<< print->info.b_num << endl;
      print = print->next;
   }
}
List::~List(){
   Node* tempPtr;
   while(head != 0){
      tempPtr = head;
      head = head->next;
      delete tempPtr;
   }
}

int main(){
   List L;
   Books B;
   string id;
   int amount;
   string command;

   while(1){
      cin >> command;
      if(command == "N"){
         cin >> B.b_id >> B.b_name >> B.b_price >> B.b_num;
         L.N(B);
      }
      else if(command == "R"){
         cin >> id >> amount;
         L.R(id, amount);
      }
      else if(command == "S"){
         cin >> id >> amount;
         L.S(id, amount);
      }
      else if(command == "D"){
         cin >> id;
         L.D(id);
      }
      else if(command == "I"){
         cin >> id;
         L.I(id);
      }
      else if(command == "P"){
         L.P();
      }
      else if(command == "L"){
         L.L();
      }
      else if(command == "Q"){
         break;
      }
   }
   return 0;
}


