#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include"game2_bos.h"
using namespace std;

bool fbos(int *num_use){
	int ct=0;
	for(int i=0;i<20;i++){
		if(num_use[i]>=41&&num_use[i]<=80){
			ct++;
		}
	}
	if(ct>=13){
		return true;
	}else{
		return false;
	}
}
