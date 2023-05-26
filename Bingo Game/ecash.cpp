#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include<fstream>
#include<string>
#include "ecash.h"
using namespace std;

FILE *f1;

eCash::eCash(){
	money=0;	
} 
eCash::~eCash(){
	cout<<"eCash: 帳號登出, 已存檔!\n謝謝，ByeBye!\n";
}
int eCash::login(string name){
//讀檔->沒有這個檔就創新檔
	f1 = fopen(name.c_str(),"r");
	if(f1==NULL){
		return 1;
	}else{
		//exist
		return 0;
	}
	fclose(f1);
			
}
void eCash::logout(string name){
//存檔
	f1 = fopen(name.c_str(),"w");
	fprintf(f1,"%d",money);
	fclose(f1); 
}
void eCash::store(int m){
	if(m<0){
		cout<<"eCash: 請輸入大於0的金額"<<endl;
	}else{
		money+=m;	
		cout<<"eCash: 您存了"<<m<<"元\n";
	}
} 
void eCash::win(int m){
	money+=m;
}
/*void eCash::pay(int m){
	if(m<0){
		cout<<"eCash: 請輸入大於0的金額"<<endl;
	}else if(m>money){
		cout<<"eCash: 您的錢不夠"<<endl;
	}else {
		money-=m;
		cout<<"eCash: 您花了"<<m<<"元\n";
	}
} */
void eCash::lose(int m){
	money-=m;
}
void eCash::display() {
	cout<<"eCash: 您尚有"<<money<<"元"<<endl;
}
int eCash::getMon(int curmon){
	money = curmon;
	return money;
}
int eCash::getMon(){
	return money;
}

