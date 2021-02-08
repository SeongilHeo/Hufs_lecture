/*
 * SimpleLinked.h
 *
 *  Created on: 2017. 4. 5.
 *      Author: tjddl
 */

#ifndef SIMPLELINKEDLIST_H_
#define SIMPLELINKEDLIST_H_

#include "Node.h"

class SimpleLinkedList{
public :
  SimpleLinkedList();
  //~SimpleLinkedList();
  bool isEmpty() const;
  void insertBefore(int insertValue);
  void removeBefore();
  void printAll() const;

private :
  Node* head;
};



#endif /* SIMPLELINKEDLIST_H_ */
