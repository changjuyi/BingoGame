#include<stdio.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

int feoo(int *num_use){
	//even(246) or odd(135)
	int even=0,odd=0;
	for(int i=0;i<20;i++){
		if(num_use[i]%2==0){
			even++;
		}else{
			odd++;
		}
	}
	// normal 13
	// little  11or12 
	if(odd>=13){
		return 1;
	}else if(odd==11||odd==12){
		return 2;
	}else if(even>=13){
		return 3;
	}else if(even==11||even==12){
		return 4;
	}else if(even==odd){
		return 5;
	}
}
