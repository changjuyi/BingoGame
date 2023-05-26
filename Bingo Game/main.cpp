#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include <fstream>
#include "game1.h"
#include "game2_bos.h"
#include "game3_eoo.h"
#include "ecash.h"
using namespace std;
int* getRand(int,int,int);

int main(int argc, char** argv) {
	int *num_cho,n,ct;
	char game,bos;
	int *num_use;  //getRand傳回的東西
	num_use = getRand(1,80,20);
	FILE *f1;
	char op;
	int m,curmon;
	eCash e;
	string name;
	cout<<"=== 歡迎使用儲值系統 ===\n"<<"eCash: 請輸入您的帳號:";
	cin>>name;
	if(e.login(name)==0){
		//要讀檔給money 
		f1 = fopen(name.c_str(),"r");
		fscanf(f1,"%d",&curmon);
		fclose(f1);
		e.getMon(curmon);
		cout<<"eCash: 帳號開啟完成!\n";
	}else{
		cout<<"eCash: 帳號不存在, 第一次使用!\n";
	}
	cout<<endl;
	while(1){
		cout<<name<<"您好，請選擇項目:\ns: 儲值\nd: 查詢餘額\nq:開始遊戲(至少要25元才可以玩遊戲)\n>";
		cin>>op;
		switch(op){
			case 's'://儲值
				cout<<"請輸入儲存金額:\n";
				cin>>m;
				e.store(m);
				break;
			/*case 'p'://消費
				cout<<"請輸入消費金額:\n";
				cin>>m;
				e.pay(m); 
				break;*/
			case 'd'://查詢餘額
				e.display();
				break;
			case 'q':
				break;
		
		}
		if(op=='q'&&e.getMon()>=25){
			cout<<"start game!\n";
			break;
		}else if(op=='q'&&e.getMon()<25){
			cout<<"錢不夠!請儲值!\n";
		}
		//system("pause");
		//system("cls");
	}
	//system("cls");
	
	cout<<"玩法選擇:\n";
	cout<<"A.基本玩法\n"<<"B.猜大小\n"<<"C.猜單雙\n"<<"E.離開\n";
	cin>>game;
	if(game=='E'){
		return 0;
	}else if((game>'C'&&game<'A') || (game>'c' && game< 'a')){
		cout<<"沒有這個選項!請重新輸入\n";
		cin>>game;
	}
	
	e.lose(25);
	
	switch(game){
		case 'A':
		case 'a':
			cout<<"選擇1~10星(幾星就是選幾個號碼):\n";
			cin>>n;
			printf("請選%d個號碼(1~80):",n); 
			num_cho=(int*)malloc(sizeof(int)*n);
			for(int i=0;i<n;i++){
				//自選號碼 
				scanf("%d",&num_cho[i]);
			}
			
			ct=cmp(n,num_use,num_cho); //中幾個 
			cout<<"中"<<ct<<"個!"<<endl;//個數 
			//money(n,ct);
			switch(n){
				case 1:
					switch(ct){
						case 0:
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 1:
							cout<<"恭喜中50元!\n";
							e.win(50);
							break;
					}
					break;
				case 2:
					switch(ct){
						case 0:
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 1:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 2:
							cout<<"恭喜中75元!\n";
							e.win(75);
							break;
					}
					break;
				case 3:
					switch(ct){
						case 0:
						case 1:
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 2:
							cout<<"恭喜中50元!\n";
							e.win(50);
							break;
						case 3:
							cout<<"恭喜中500元!\n";
							e.win(500);
							break;
					}
					break;
				case 4:
					switch(ct){
						case 0:
						case 1:
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 2:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 3:
							cout<<"恭喜中100元!\n";
							e.win(100);
							break;
						case 4:
							cout<<"恭喜中1,000元!\n";
							e.win(1000);
							break;
					}
					break;
				case 5:
					switch(ct){
						case 0:
						case 1:
						case 2:	
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 3:
							cout<<"恭喜中50元!\n";
							e.win(50);
							break;
						case 4:
							cout<<"恭喜中500元!\n";
							e.win(500);
							break;
						case 5:
							cout<<"恭喜中7,500元!\n";
							e.win(7500);
							break;
					}
					break;
				case 6:
					switch(ct){
						case 0:
						case 1:
						case 2:	
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 3:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 4:
							cout<<"恭喜中200元!\n";
							e.win(200);
							break;
						case 5:
							cout<<"恭喜中1,000元!\n";
							e.win(1000);
							break;
						case 6:
							cout<<"恭喜中25,000元!\n";
							e.win(25000);
							break;
					}
					break;
				case 7:
					switch(ct){
						case 0:
						case 1:
						case 2:	
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 3:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 4:
							cout<<"恭喜中50元!\n";
							e.win(50);
							break;
						case 5:
							cout<<"恭喜中300元!\n";
							e.win(300);
							break;
						case 6:
							cout<<"恭喜中3000元!\n";
							e.win(3000);
							break;
						case 7:
							cout<<"恭喜中80,000元!\n";
							e.win(80000);
							break;
					}
					break;
				case 8:
					switch(ct){
						case 0:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 1:
						case 2:	
						case 3:
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 4:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 5:
							cout<<"恭喜中200元!\n";
							e.win(200);
							break;
						case 6:
							cout<<"恭喜中1,000元!\n";
							e.win(1000);
							break;
						case 7:
							cout<<"恭喜中20,000元!\n";
							e.win(20000);
							break;
						case 8:
							cout<<"恭喜中500,000元!\n";
							e.win(500000);
							break;
					}
					break;
				case 9:
					switch(ct){
						case 0:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 1:
						case 2:	
						case 3:
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 4:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 5:
							cout<<"恭喜中100元!\n";
							e.win(100);
							break;
						case 6:
							cout<<"恭喜中500元!\n";
							e.win(500);
							break;
						case 7:
							cout<<"恭喜中3,000元!\n";
							e.win(3000);
							break;
						case 8:
							cout<<"恭喜中100,000元!\n";
							e.win(100000);
							break;
						case 9:
							cout<<"恭喜中1,000,000元!\n";
							e.win(1000000);
							break;
						
					}
					break;
				case 10:
					switch(ct){
						case 0:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 1:
						case 2:	
						case 3:
						case 4:
							cout<<"沒有錢~再接再厲~\n";
							break;
						case 5:
							cout<<"恭喜中25元!\n";
							e.win(25);
							break;
						case 6:
							cout<<"恭喜中250元!\n";
							e.win(250);
							break;
						case 7:
							cout<<"恭喜中2,500元!\n";
							e.win(2500);
							break;
						case 8:
							cout<<"恭喜中25,000元!\n";
							e.win(25000);
							break;
						case 9:
							cout<<"恭喜中250,000元!\n";
							e.win(250000);
							break;
						case 10:
							cout<<"恭喜中5,000,000元!\n";
							e.win(5000000);
							break;
					}
					break;
					
			}
			free(num_cho); 
			break;
		case 'B':
		case 'b':
			cout<<"大(B)或小(S)\n"; 
			cin>>bos;
			switch(bos){
				case'B':
					if(fbos(num_use)==true){
						cout<<"猜對了!\n恭喜獲得150元"<<endl;
						e.win(150);
					}else{
						cout<<"沒有猜對~\n再接再厲!"<<endl;
					}
					break;
				case'S':
					if(fbos(num_use)==false){
						cout<<"猜對了!\n恭喜獲得150元"<<endl;
						e.win(150);
					}else{
						cout<<"沒有猜對~\n再接再厲!"<<endl;
					}
					break;
			}
			break;
		case 'C':
		case 'c':
			char eoo;
			cout<<"選擇單(a)、小單(b)、雙(c)、小雙(d)、和(e)"<<endl;
			cin>>eoo;
			switch(eoo){
				case 'a':
					if(feoo(num_use)==1){
						cout<<"猜對了!\n恭喜獲得150元\n";
						e.win(150);
					}else{
						cout<<"沒有猜對~\n再接再厲!"<<endl;
					}
					break;
				case 'b':
					if(feoo(num_use)==2){
						cout<<"猜對了!\n恭喜獲得45元\n";
						e.win(45);
					}else{
						cout<<"沒有猜對~\n再接再厲!"<<endl;
					}
					break;
				case 'c':
					if(feoo(num_use)==3){
						
						cout<<"猜對了!\n恭喜獲得150元\n";
						e.win(150);
					}else{
						cout<<"沒有猜對~\n再接再厲!"<<endl;
					}
					break;
				case 'd':
					if(feoo(num_use)==4){
						cout<<"猜對了!\n恭喜獲得45元\n";
						e.win(45);
					}else{
						cout<<"沒有猜對~\n再接再厲!"<<endl;
					}
					break;
				case 'e':
					if(feoo(num_use)==1){
						cout<<"猜對了!\n恭喜獲得70元\n";
						e.win(70);
					}else{
						cout<<"沒有猜對~\n再接再厲!"<<endl;
					}
					break;
			}
			break;
	}
	cout<<"以下為中獎號碼:\n";
	sort(num_use,num_use+20);//排序 對獎用 
	for(int i=0;i<20;i++){
		printf("[%d]->%d\n",i+1,num_use[i]);
	}
	e.logout(name);
	
	return 0;
}
int* getRand(int min, int max, int num){
    int tol = max - min +1;  
    int a[90];   
    static int b[90];  
    int i,j;
    for(i=0;i<tol;i++){   
        *(a+i) = min+i;
    }
    srand(time(0));
    int ctr;   
    for(i=0;i<num;i++){
        ctr = rand()%(tol-i);
        b[i] = a[ctr];  
        for(j=ctr;j<(tol-1-i);j++){  
            a[j] = a[j+1];  
        }
    }
    return b;
}
