/*
 * 10271.cpp
 *
 *  Created on: 2016. 10. 27.
 *      Author: tjddl
 */
#include <iostream>
#include <string>
using namespace std;

class Car
{
public:

	int speed;
	float dist;
	string name;

	void updateDist(int a);
	void updatespeed(int a);
	void printCar();
	void accelerate(int a);

};
void Car::updateDist(int a)
{
	float temp =speed +a/2.0;
	dist =dist +temp;

}
void Car::updatespeed(int a)
{
	speed = speed + a;
}
void Car::accelerate(int a)
{
	updateDist(a);
	updatespeed(a);
}
void Car::printCar()
{
	cout<<name<<": ";
	cout<<speed<<" ";
	cout<<dist<<endl;
}

int main (void)
{
	Car car1,car2;
	car1.name="bmw";
	car1.speed=0;
	car1.dist=0;
	car2.name="audi";
	car2.speed=0;
	car2.dist=0;

	car1.printCar();
	car2.printCar();
	for(int i=0; i<100 ; i++)
	{
		car1.accelerate(2);
		car2.accelerate(3);
	}
	car1.printCar();
	car2.printCar();

	return 0;
}

