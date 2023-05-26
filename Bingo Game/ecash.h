#ifndef ECASH_H
#define ECASH_H
#include <iostream>
#include <string>
using namespace std;
class  eCash{
	public:
		eCash();
		~eCash();
		int login(string name);
		void logout(string name);
		void store(int m); 
		void win(int m);
		void pay(int m); 
		void lose(int m);
		void display();
		int getMon(int curmon);
		int getMon();
		 
	private:
		int money;
		string name;
};

#endif
