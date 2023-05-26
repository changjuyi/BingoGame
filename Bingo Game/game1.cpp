#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"game1.h"

using namespace std;

//基本玩法 //return 中幾個 
int cmp(int n,int *num_use,int *num_cho){
	//對獎 
	int ct=0;
	for(int i=0;i<n;i++){
		for(int j=0;j<20;j++){
			if(num_cho[i]==num_use[j]){
				ct++;
			}
		}
	}
	return ct;
}