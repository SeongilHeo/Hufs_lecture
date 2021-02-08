#include <iostream>

using namespace std;

const int MAX_SIZE = 50; // const는 상수 (변하지 않음), 글로벌 상수

class Web_browser
{
	string addr_arr[MAX_SIZE];
	string history[MAX_SIZE];
	string home_addr;
	int current;
	int length;
	int a;

public:
	Web_browser();
	void go(string addr);
	void forward();
	void backward();
	string get_current_addr();
	void print_addr_arr();
	void home();
	void set_home_addr(string addr);
	void histroy();
};


Web_browser :: Web_browser()
{
	current = 0;
	home_addr = "http://ces.hufs.ac.kr";
	addr_arr[current] = home_addr;
	length = 1;
	history[0]= home_addr;
	cout << get_current_addr() << endl;
	a=0;
}

void Web_browser :: go(string addr)
{
	if(current <= MAX_SIZE -1)
	{
		current++;
		addr_arr[current] = addr;
		length = current + 1;
		a++;
		history[a]= addr;
	}
}

void Web_browser :: forward()
{
	if(current < length -1)
	{
		current++;
	}
}

void Web_browser :: backward()
{
	if(current != 0)
	{
		current--;
	}
}

string Web_browser :: get_current_addr()
{
	return addr_arr[current];
}

void Web_browser ::  print_addr_arr()
{
	for(int i = 0; i < length; i++)
		if(i == length-1)
			cout << addr_arr[i] << endl;
		else
			cout << addr_arr[i] << " - ";
}
void Web_browser :: home()
{
	go(home_addr);
}
void Web_browser ::set_home_addr(string addr)
{
	home_addr = addr;
}

void Web_browser ::histroy()
{
	for(int i=0 ; i<=a && i<10 ; i++ )
	{
		cout << history[i] << endl;
	}
}

int main()
{
	Web_browser wb;
	string command;
	string addr;
	string EXITCMD = "quit";

	while(cin >> command)
	{
		if(command == EXITCMD)
		{
			break;
		}
		else if(command == "go")
		{
			cin >> addr;
			wb.go(addr);
			cout << wb.get_current_addr() << endl;
			//wb.print_addr_arr();
		}
		else if(command == "forward")
		{
			wb.forward();
			cout << wb.get_current_addr() << endl;
			//wb.print_addr_arr();
		}
		else if(command == "backward")
		{
			wb.backward();
			cout << wb.get_current_addr() << endl;
			//wb.print_addr_arr();
		}
		else if(command == "set_home")
		{
			cin >> addr;
			wb.set_home_addr(addr);
		}
		else if(command == "home")
		{
			wb.home();
			cout << wb.get_current_addr() << endl;
		}
		else if(command == "history")
		{
			wb.histroy();
		}
	}
	return 0;
}
