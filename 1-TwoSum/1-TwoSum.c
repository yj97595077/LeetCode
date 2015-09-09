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

//����һ���ṹ�� 
typedef struct node{
	int idx;
    int data;
}Node;

//����qsort���űȽϺ����������Ǵ�С�������У�����������ǽṹ��ָ�� 
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

//������index����ָ��ĺ��� 
int* twoSum(int* nums, int numsSize, int target) {
	Node* cpnums = (Node*)malloc(numsSize * sizeof(Node));//����һ���յĽṹ��ָ�벢�����ڴ� 
	
	//����������鿽����ȥ������ʱ�����index ��ע��ָ����÷���ֱ��������������ָ�벻��++ 
	for(int i = 0; i < numsSize; i++){
		(cpnums+i)->idx = i+1;
		(cpnums+i)->data = *(nums+i);
	}
	
	//��������½ṹ������ 
	qsort(cpnums,numsSize,sizeof(Node),cmp);
	
	/*���Կ��ź�Ľ�� 
	for(int i=0; i<numsSize; i++){
		printf("data:%d ",(cpnums+i)->data);
		printf("index:%d\n",(cpnums+i)->idx);
	} 
	*/
	
	//����һ������index���ݣ���ʼ��Ϊ0��Ϊ�˷���ʱָ��ɿأ�����static 
	static int ret[2] = {0,0};
	
	//���������ж�target�Ƿ���� 
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

//��֤����������� 
void main(){
	int array[] = {1,9,7,10,2,4,24,67,3,43,12,21};
	int* index = twoSum(array,sizeof(array)/sizeof(array[0]),88);
	for(int i=0; i<2; i++)
		printf("index is %d\n", *(index + i));
}

//���� fighting����

