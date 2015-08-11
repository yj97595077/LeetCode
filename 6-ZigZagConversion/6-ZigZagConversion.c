/*
ZigZag Conversion
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: 
(you may want to display this pattern in a fixed font for better legibility)
P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/

#include<stdio.h>
#include<stdlib.h>

char* convert(char* s, int numRows) {
	//输出s的长度 
	int length = 0;
	for(int i=0; *(s+i)!='\0'; i++){
		length += 1;
	}
	//printf("%d\n",length);
    
    //定义动态数组 
	char* result = (char*)malloc((length+1)*(sizeof(char)));
    
    //排除掉特殊情况 
    if(numRows==1 || length==0){
    	result = s;
	}else{
	    //定义下来每个单元有几个数，并计算出有几个循环单元，输出的时候有用 
		int period = 2*(numRows - 1);
		int x = length / period;
		//printf("%d\n%d\n",period,x);
		
		//定义新数组下角标 
		int index = 0;
		//按照之字形的横排开始读取 
		for(int i=1; i<=numRows; i++){
			//第一排的情况，记住*（s）里面的都是要和真实的序号减1 
			if(i==1){
				for(int j=0; j<=x && period*j<length; j++){
					*(result+index) = *(s+period*j);
					index++;
				}
			}
			//定义中间排的情况，每次输出两个数 
			if(i>1 && i<numRows){
				for(int j=0; j<=x && (period*j+i-1)<length; j++){
					*(result+index) = *(s+period*j+i-1);
					index++;
					//判断最后一个不连续的循环在不在，全不全，有则输出，没有就跳过 
					if((period*j+period-i+1)<length){
						*(result+index) = *(s+period*j+period-i+1);
						index++;
					}	
				}
			}
			//最后一排的情况，和第一排差不多，还是记得行号和指针里面的数差1 
			if(i==numRows){
				for(int j=0; j<=x && (period*j+i-1)<length; j++){
					*(result+index) = *(s+period*j+i-1);
					index++;
				}			
			}	
		}		
	}
	return result;
}

void main(){
	//char s[]="PAYPALISHIRING";
	//char s[]="abc";
	char s[]="abcdefghijklmnopqrstuvwxyz";
	//这个字母表，4行之字形输出应该为“agmsybfhlnrtxzceikoquwdjpv” 
	char* t = convert(s,4);
	//循环的方式输出一个数组 
	for(int i=0; *(t+i)!='\0'; i++){
		printf("%c",*(t+i));
	}
}
