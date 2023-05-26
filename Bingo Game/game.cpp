#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <algorithm>
#include "game1.h"
#include "game2_bos.h"
#include "game3_eoo.h"
using namespace std;
int* getRand(int,int,int);
void game(){
	int *num_cho,n,ct;
	char game,bos;
	int *num_use;  //getRand�Ǧ^���F��
	num_use = getRand(1,80,20);
	/*for(int i=0;i<20;i++){
		printf("[%d]->%d\n",i,num_use[i]);
	}*/
	sort(num_use,num_use+20);//�Ƨ� ����� 
	for(int i=0;i<20;i++){
		printf("[%d]->%d\n",i,num_use[i]);
	}
	cout<<"���k���:\n";
	cout<<"A.�򥻪��k\n"<<"B.�q�j�p\n"<<"C.�q����\n";
	cin>>game;
	if(game>'C'||game<'A'){
		cout<<"�S���o�ӿﶵ!�Э��s��J\n";
		cin>>game;
	}
	switch(game){
		case'A':
			cout<<"���1~10�P\n";
			cin>>n;
			printf("�п�%d�Ӹ��X(1~80):",n); 
			num_cho=(int*)malloc(sizeof(int)*n);
			for(int i=0;i<n;i++){
				//�ۿ︹�X 
				scanf("%d",&num_cho[i]);
			}
			sort(num_use,num_use+20);//�Ƨ� ����� 
			/*for(int i=0;i<20;i++){
				printf("[%d]->%d\n",i,num_use[i]);
			}*/
			ct=cmp(n,num_use,num_cho); //���X�� 
			cout<<"��"<<ct<<"��!"<<endl;//�Ӽ� 
			money(n,ct);
			free(num_cho); 
			break;
		case'B':
			cout<<"�j(B)�Τp(S)\n"; 
			cin>>bos;
			switch(bos){
				case'B':
					if(fbos(num_use)==true){
						cout<<"�q��F!\n������o150��"<<endl;
					}else{
						cout<<"�S���q��~\n�A���A�F!"<<endl;
					}
					break;
				case'S':
					if(fbos(num_use)==false){
						cout<<"�q��F!\n������o150��"<<endl;
					}else{
						cout<<"�S���q��~\n�A���A�F!"<<endl;
					}
					break;
			}
			break;
		case'C':
			char eoo;
			cout<<"��ܳ�(a)�B�p��(b)�B��(c)�B�p��(d)�B�M(e)"<<endl;
			cin>>eoo;
			switch(eoo){
				case 'a':
					if(feoo(num_use)==1){
						cout<<"�q��F!\n������o150��\n";
					}else{
						cout<<"�S���q��~\n�A���A�F!"<<endl;
					}
					break;
				case 'b':
					if(feoo(num_use)==2){
						cout<<"�q��F!\n������o45��\n";
					}else{
						cout<<"�S���q��~\n�A���A�F!"<<endl;
					}
					break;
				case 'c':
					if(feoo(num_use)==3){
						cout<<"�q��F!\n������o150��\n";
					}else{
						cout<<"�S���q��~\n�A���A�F!"<<endl;
					}
					break;
				case 'd':
					if(feoo(num_use)==4){
						cout<<"�q��F!\n������o45��\n";
					}else{
						cout<<"�S���q��~\n�A���A�F!"<<endl;
					}
					break;
				case 'e':
					if(feoo(num_use)==1){
						cout<<"�q��F!\n������o70��\n";
					}else{
						cout<<"�S���q��~\n�A���A�F!"<<endl;
					}
					break;
			}
			break;
	}
	
	
	//return 0;
}
int* getRand(int min, int max, int num){
    int tol = max - min +1;  //��X�`��
    int a[30000];  //��min~max���Ҧ��Ʀr 
    static int b[30000];  //����X���ü� 
    int i,j;
    for(i=0;i<tol;i++){  //��q���n�O�Ю��Ʀr�A�q�p�ƨ�j��ia[0]~a[tol-1] 
        *(a+i) = min+i;
    }
    srand(time(0));
    int ctr;  //�o�u�O�Ӯe���A���Ӹ�a[n]�̪�n�A�ӳo��n�O�ζüƻs�y�� 
    for(i=0;i<num;i++){
        ctr = rand()%(tol-i);
        b[i] = a[ctr];  //���n���üƥ��b�̭� 
        for(j=ctr;j<(tol-1-i);j++){  //�o�O��Ӥ����ƶüƨ�ƪ��g��Ҧb�I
            a[j] = a[j+1];  //�ܷL�����q�q���e���ʤ@�� 
        }
    }
    return b;
}
