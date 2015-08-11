/*
Given a string S, find the longest palindromic substring in S. 
You may assume that the maximum length of S is 1000, and there exists one unique longest palindromic substring.
*/

#include<stdio.h>
#include<stdlib.h>

int check1(char* s, int n){
	if(*(s-n) == *(s+n)){
		return 1;
	}else{
		return 0;
	}
}

int check2(char* s, int n){
	if(*(s-n-1) == *(s+n)){
		return 1;
	}else{
		return 0;
	}
}

char* longestPalindrome(char* s) {
	int length = 0;
	for(int i=1; *(s+i)!='\0'; i++){
		length += 1;
	}
	
	int sum = 0;
	for(int i=1; i<length; i++){
		for(int j=1; j<i && j<(length-i+1); j++){
			if(check1(*(s+i),j)){
				continue;
			}else{
				break;
			}
		}
		if(sum < (j-1)){
			sum = j-1;
		}
	}
	
	
	
	char* r = (char*)malloc(sizeof(char));
	
    
}
