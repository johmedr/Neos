#include <iostream>

using namespace std; 

struct Base
{
	virtual void f()
	{
		cout << "Base" << endl; 
	}; 
};

struct S1 : virtual public Base 
{
	virtual void f()
	{
		cout << "S1" << endl; 
	}; 
};

struct S2 : virtual public Base 
{
	virtual void f2()
	{
		cout << "S2" << endl; 
	}; 
};

struct Son : public S1, public S2 
{};

int main() 
{
	Son s; 
	s.f(); 
}