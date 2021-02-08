/*
 * stack.h
 *
 *  Created on: 2017. 3. 29.
 *      Author: tjddl
 */

#ifndef STACK_H_
#define STACK_H_

typedef int ItemType;

const int MAX_STACK_SIZE = 30;          // ������ �ִ� ũ�� ����
class Stack {
      int top;                              // ���ÿ��� ���� ���� �ִ� ����� �迭��ġ
      ItemType data[MAX_STACK_SIZE];   // ��Ҹ� �����ϴ� �迭
public:
      Stack();		       // ���� ������
      ~Stack();                  // ���� �Ҹ���
      bool isEmpty();
      bool isFull();
      void push(ItemType e);    // ���ÿ� ��� ����
      ItemType pop( ); 	       // ���� �ֱٿ� ���ÿ� ���Ե� ��Ҹ� �����ϰ� ��ȯ
      ItemType peek( ); 	       // ���� �ֱٿ� ���ÿ� ���Ե� ��Ҹ� ��ȯ
};

#endif /* STACK_H_ */
