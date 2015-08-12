/*
Reverse digits of an integer.

Example1: x = 123, return 321
Example2: x = -123, return -321
*/

#include<stdio.h>
#include<stdlib.h>

int reverse(int x) {
    int reverse[10]={};
    int index=0;
    int result=0;
    
    if(x==0){
        result=0;
    }
    if(x>0){
        while(x){
            reverse[index++]=x%10;
            x/=10;
        }
        /*
        测试翻转是否成功 
        for(int i=0;i<index;i++){
            printf("%d\n",reverse[i]);
        } 
        */
        //测试index是否和预期一致 
    	//printf("%d\n",index);
    	
        for(int i=0;i<index;i++){
        	//设置每次乘以的倍数，就是10的多少次方 
            int times=1;
            for(int j=0;j<(index-i);j++){
                if(j==0){
                    times*=1;
                }else{
                    times*=10;
                }
            }
            result+=reverse[i]*times;
        }
    }
    if(x<0){
        int y;
        y=x*(-1);
        while(y){
            reverse[index++]=y%10;
            y/=10;
        }
    
        for(int i=0;i<index;i++){
            int times=1;
            for(int j=1;j<(index-i);j++){
                if(j==0){
                    times*=1;
                }else{
                    times*=10;
                }
            }
            result+=reverse[i]*times;
        }
        result=result*(-1);
    }
    return result;
}

void main(){
	printf("%d\n",reverse(-123));
	//尼玛，这个越界问题处理不了了，他娘的 
	printf("%d\n",reverse(1534236469));
}
