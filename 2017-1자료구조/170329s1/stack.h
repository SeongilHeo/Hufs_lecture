/*
 * stack.h
 *
 *  Created on: 2017. 3. 29.
 *      Author: tjddl
 */

#ifndef STACK_H_
#define STACK_H_

typedef int ItemType;

const int MAX_STACK_SIZE = 30;          // 스택의 최대 크기 설정
class Stack {
      int top;                              // 스택에서 가장 위에 있는 요소의 배열위치
      ItemType data[MAX_STACK_SIZE];   // 요소를 저장하는 배열
public:
      Stack();		       // 스택 생성자
      ~Stack();                  // 스택 소멸자
      bool isEmpty();
      bool isFull();
      void push(ItemType e);    // 스택에 요소 삽입
      ItemType pop( ); 	       // 가장 최근에 스택에 삽입된 요소를 삭제하고 반환
      ItemType peek( ); 	       // 가장 최근에 스택에 삽입된 요소를 반환
};

#endif /* STACK_H_ */
