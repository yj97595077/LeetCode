/*
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
*/ 

/**
*  * Note: The returned array must be malloced, assume caller calls free().
*  */
#include<stdio.h>
#include<stdlib.h>

//定义一个结构体 
typedef struct node{
	int idx;
    int data;
}Node;

//创建qsort快排比较函数，如下是从小到大排列，快排输入的是结构体指针 
int cmp(const void* p1, const void* p2){
    int result;
    if(((Node*)p1)->data - ((Node*)p2)->data < 0)
        result = -1;
	else if (((Node*)p1)->data - ((Node*)p2)->data == 0)
        result = 0;
    else
        result = 1;
    return result;
}

//主返回index数据指针的函数 
int* twoSum(int* nums, int numsSize, int target) {
	Node* cpnums = (Node*)malloc(numsSize * sizeof(Node));//定义一个空的结构体指针并申请内存 
	
	//把输入的数组拷贝过去，拷贝时候加上index ，注意指针的用法，直接拿数据名当的指针不能++ 
	for(int i = 0; i < numsSize; i++){
		(cpnums+i)->idx = i+1;
		(cpnums+i)->data = *(nums+i);
	}
	
	//快排这个新结构体数组 
	qsort(cpnums,numsSize,sizeof(Node),cmp);
	
	/*测试快排后的结果 
	for(int i=0; i<numsSize; i++){
		printf("data:%d ",(cpnums+i)->data);
		printf("index:%d\n",(cpnums+i)->idx);
	} 
	*/
	
	//定义一个返回index数据，初始化为0，为了返回时指针可控，加上static 
	static int ret[2] = {0,0};
	
	//遍历数组判断target是否存在 
	for(int j = 0; j < numsSize; j++){
		for(int k = j+1; k < numsSize; k++){
			if ((cpnums+j)->data + (cpnums+k)->data == target){
				ret[0] = (cpnums+j)->idx;
				ret[1] = (cpnums+k)->idx;
				if(ret[0] > ret[1]){
					int t;
					t = ret[0];
					ret[0] = ret[1];
					ret[1] = t;
				}
			}
		}
	}
    return ret;
 }

//验证结果的主函数 
void main(){
	int array[] = {1,9,7,10,2,4,24,67,3,43,12,21};
	int* index = twoSum(array,sizeof(array)/sizeof(array[0]),88);
	for(int i=0; i<2; i++)
		printf("index is %d\n", *(index + i));
}

//加油 fighting！！

