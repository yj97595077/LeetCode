/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
*/ 
#include<stdio.h>
#include<stdlib.h>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

//定义一个结构体 
struct ListNode {
	int val;
	struct ListNode* next;
};

//计算两个链表的和 
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    //想要创建一个链表必须得malloc空间，得到空间地址 
	struct ListNode* l = (struct ListNode*)malloc(sizeof(struct ListNode));
	//想要遍历、处理一个链表，必须得有个新指针步步追踪 
    struct ListNode* p = l1;
    struct ListNode* q = l2;
    struct ListNode* r = l;
	
	//定义新链表l的第一个节点，一般节点都需要以NULL结尾，所以While循环之前定义好第一个节点很必要 
	int sum = 0;
	int result = 0;
	int rest = 0;
					
	sum = p->val + q->val;
	result = sum % 10;
	r->val = result + rest;
	r->next = NULL;
	rest = sum / 10;
	
	//用p、q来指挥l1、l2向后移动一个节点 
	p = p->next;
	q = q->next;
	
	while(p || q){
		//给下一个节点分配空间，把具体指针给第一个节点的指针 
		r->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		r = r->next;

		sum = p->val + q->val;
		result = sum % 10;
		r->val = result + rest;
		r->next = NULL;
		rest = sum / 10;
		
		p = p->next;
		q = q->next;
		
		//如果有一个长一个短的list，如下处理 
		if((p == NULL) && (q != NULL)){
			r->next = q;
			q->val += rest;
			break;
		}
		if((q == NULL) && (p != NULL)){
			r->next = p;
			p->val += rest;
			break;
		}
	}
	return l;
}

void main(){
	struct ListNode *l1 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *l2 = (struct ListNode*)malloc(sizeof(struct ListNode));
	struct ListNode *p = l1;
	struct ListNode *q = l2;
	int num1, num2;
	
	//初始化创建list1 
	printf("请输入List1，这是第1个\n");
	scanf("%d",&num1);
	p->val = num1;
	p->next = NULL;
	for(int i=2; i<=3; i++){
		p->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		p = p->next;
		printf("请输入List1，这是第%d个\n",i);
		scanf("%d",&num1);
		p->val = num1;
		p->next = NULL;
	}
	
	/*
	测试初始化创建的list1是否成功 
	struct ListNode* s = l1;
	while(s != NULL){
		printf("%d\n",s->val);
		s = s->next;
	}
	*/
	
	//初始化创建list2
	printf("请输入List2，这是第1个\n");
	scanf("%d",&num2);
	q->val = num2;
	q->next = NULL;
	for(int i=2; i<=4; i++){
		q->next = (struct ListNode*)malloc(sizeof(struct ListNode));
		q = q->next;
		printf("请输入List2，这是第%d个\n",i);
		scanf("%d",&num2);
		q->val = num2;
		q->next = NULL;
	}
	
	//计算两个链表的和 
	struct ListNode* l = addTwoNumbers(l1,l2);
	
	//输出链表的每个节点，用新指针r来遍历 
	struct ListNode* r = l;
	while(r){
		printf("%d\n",r->val);
		r = r->next;
	}
}
