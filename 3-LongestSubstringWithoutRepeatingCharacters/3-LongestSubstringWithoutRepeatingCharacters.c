/*
Given a string, find the length of the longest substring without repeating characters. 
For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. 
For "bbbbb" the longest substring is "b", with the length of 1.
*/

#include<stdio.h>
#include<stdlib.h>

//定义链表的结构体 
typedef struct node{
	int data;
	struct node* next;
}Node;

//设计函数，输出一个字符在上个已经存在无、重复元素的字符串中的重复元素位置，无重复元素输出0 
int repeatNum(char s, Node* l){
	int i = 0;
	int j = 0;
	Node* p = l;
	while(p){
		i = i + 1;
		if(s == p->data){
			j = i;
			//break;
		}
		p = p->next;
	}
	return j;
}

int lengthOfLongestSubstring(char* s) {
	//输出数组的长度，字符数 
	int slength = 0;
	for(int i=0; *(s+i)!=0; i++){
		slength += 1;
	}
	//测试输出s长度是否有问题 
	//printf("in f slength: %d\n",slength);
	
	//把返回值在最外面定义，不然大括号里面定义，出了大括号就得重新申请了 
	int longest = 0;
	
	//排除掉长度为1和2的短数组 
	if(slength==0){
		return 0;
	}else if(slength==1){
		return 1;
	}else{
		//定义一个新结构体l,并且定义q来追踪处理l 
		Node* l = (Node*)malloc(sizeof(Node));
		Node* p = l;
		
		//直接把数组第一个元素传递给链表第一个节点 
		p->data = *s;
		p->next = NULL;
		
		int Num = 0;
		
		for(int i=1; *(s+i) != '\0'; i++){
			//输出重复元素的位置 
			Num = repeatNum(*(s+i),l);
			
			//把数组的新值赋给链表，至少是数组的第二个值了 
			p->next = (Node*)malloc(sizeof(Node));
			p = p->next;
			p->data = *(s+i);
			p->next = NULL;
			
			//假设前面有重复的，把链表的指针向后移动对应的位置，l不可能是null 
			if(Num != 0){
				for(int j=0; j<Num; j++){
					l = l->next;
				}
			}
			
			//不断的计算l指针移动后产生的没有重复元素的新链表的节点个数 
			Node* q = l;
			int sum = 0;
			while(q){
				sum += 1;
				q = q->next;
			}
			
			//如果没有重复元素的新链表的节点个数大于已有的最长数，就替换最长 
			if(sum > longest){
				longest = sum;
			}			
		}		
	}
	return longest;
}

void main(){
	char s[] = "abcdecdefabc";
	//char s[] = "abcabcbb";
	//char s[] = "bbbb";
	//char s[] = "abcdefg";
	//char s[] = "a";
	//char s[] = "";
	printf("最长子链：%d\n",lengthOfLongestSubstring(s));
}
