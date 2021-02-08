/*
 * 12011.cpp
 *
 *  Created on: 2016. 12. 1.
 *      Author: tjddl
 */
#include <iostream>
using namespace std;

class Point
{
	int x,y;
public:
	Point() : x(0), y(0) {}
	Point(int a,int b) : x(a), y(b) {}
	Point(const Point &p): x(p.x), y(p.y) {}
	friend ostream& operator<<(ostream& os, const Point& p)
	{
		os<<"("<<p.x<<","<<p.y<<")";
		return os;
	}
	friend Point operator+(const Point& a, const Point& b)//+연산자 오버로딩1
	{
		return Point(a.x+b.x, a.y+b.y);

	}
	friend Point operator+(const int& a, const Point& b)//+연산자 오버로딩2
	{
			return Point(a+b.x,a+b.y);
	}
	friend int operator*(const Point& a, const Point& b)//*연산자 오버로딩
	{
		return a.x*b.x+a.y*b.y;
	}
	friend Point scale(const Point& a, const Point& b)//scale
	{
		return Point(a.x*b.x, a.y*b.y);
	}
	friend Point transpose(const Point& p)//transpose
	{
		return Point(p.y,p.x);
	}
};
class Rect
{
	Point p,q;
public:
	Rect():p(0,0),q(0,0){}
	Rect(int x1, int y1, int x2, int y2):p(x1,y1),q(x2,y2){}
	Rect(const Point& a,const Point& b):p(a),q(b){}
	friend ostream& operator<<(ostream& os, const Rect& i)//출력 연산자 오버로딩
	{
		os<<i.p<<"-"<<i.q;//(a,b)-(c,d)
		return os;
	}
	friend Rect operator+(const Rect& a, const Point& b)//+연산자 오버로딩1
	{
		return Rect(a.p+b,a.q+b);//rect + point
	}
	friend Rect operator+(const Rect& a,const int& b)//+연산자 오버로딩2
	{
		return Rect(b+a.p,b+a.q);//int + rect
	}
	friend Rect operator*(const Rect& a,const Point& b)//*연산자 오버로딩
	{
		Point f;//(w,h)
		Point d(-1,-1);//-연산을 위한 point
		f=a.q+scale(a.p,d);//q-p = (w,h)
		return Rect(a.p,a.p+scale(f,b));//(p,new q)// new q = p+(w,h)
	}
	int area()//넓이 구하기
	{
		Point a;//(w,h)
		Point d(-1,-1);//-연산을 위한 point
		a=q+scale(p,d);//(w,h)=a=q-p
		return a*transpose(a)/2;// w*h =(w*h+h*w)/2
	}
};
int main()
{
	Point A(1,2);
	Point B(3,3);
	Rect a;//(0,0)-(0,0)
	Rect b(1,2,3,4);//rect(x1,y1,x2,y2)
	Rect c(A,B);//rect(point A, point B)

	cout<<"point-1 "<<A<<endl;
	cout<<"point-2"<<B<<endl;
	cout<<"CHECK1"<<endl<<"rect-1 : "<<a<<endl;//1번 확인
	cout<<"rect-2 : "<<b<<endl;
	cout<<"rect-3 : "<<c<<endl;
	cout<<"CHECK2.1 : "<<b+A<<endl;//2-1확인
	cout<<"CHECK2.2 : "<<b+3<<endl;//2-2확인
	cout<<"CHECK3 : "<<b*A<<endl;//3번 확인
	cout<<"CHECK4 : "<<b.area()<<endl;//4번 확인

	return 0;

}
