#include "stdio.h"
#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <queue>

using namespace std;

typedef struct NODE *Node;

int root;
struct NODE{
	Node left;
	Node right;
	int data;
};
int M,N;
typedef struct QUEUE *Queue;

struct QUEUE{
	Queue next;
	Node data;
};

bool isEmpty(Queue &que)
{
	if(que==NULL){
		return true;
	}
	else return false;
}

Queue push(Queue &que,Node data){
	Queue head =que;
	if(que==NULL){
		que = (Queue) malloc(sizeof(struct QUEUE));
		que->next = NULL;
		que->data = data;
		return que;
	}
	while(que->next!=NULL){
		que = que->next;
	}
	Queue tmp;
	tmp = (Queue) malloc(sizeof(struct QUEUE));
	tmp->next = NULL;
	tmp->data = data;
	que->next = tmp;
	return head;
}


Node pop(Queue &que){
	Queue tmp;
	tmp = que;
	que = que->next;
	return tmp->data;
}



int buildTree(Node& node,int * key,int flag)
{
	int i=0;
	int tmpflag;
	if(node==NULL){
		node = (Node) malloc(sizeof(struct NODE));
 		node->data = key[0];
		node->left = NULL;
		node->right = NULL;
	}
	Queue que=NULL;
	que = push(que,node);
	for(i=1;i<N;){	
		while(!isEmpty(que)){
			Node tmp = pop(que);
			tmp->left =(Node) malloc(sizeof(struct NODE));
			tmp->left->left = NULL;
			tmp->left->right = NULL;
			tmp->left->data = key[i];

			if(tmp->left->data<tmp->data) tmpflag = 1;
			else tmpflag = 2;

			if(tmpflag != flag) flag = 3;
	

			que = push(que,tmp->left);
			i++;


			if(i>=N) return flag;
			tmp->right = (Node) malloc(sizeof(struct NODE));
			tmp->right->left = NULL;
			tmp->right->right = NULL;
			tmp->right->data = key[i];

			if(tmp->right->data<tmp->data) tmpflag = 1;
			else tmpflag = 2;

			if(tmpflag != flag) flag = 3;
		

			que = push(que,tmp->right);
			i++; 
			if(i>=N) return flag;
		}
	}
}

bool space = true;
void postOrder(Node node)
{
	if(node==NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	if(space){
		printf("%d", node->data);
		space = false;
	}else{
		printf(" %d",node->data);
	}
	
}

Node insert(Node &node,int data)
{
	if(node==NULL){
		node = (Node) malloc(sizeof(struct NODE));
		node->left = NULL;
		node->right = NULL;
		node->data = data;
		return node;
	}
	if(node->data>data) insert(node->left,data);
	else insert(node->right,data);
}

void init()
{
	scanf("%d %d",&M,&N);
	int i=0;
	for(i=0;i<M;i++){
	  space = true;
		int j;
		int* tmp = (int *)malloc(N* sizeof(int));
		Node Heap=NULL;
		for(j=0;j<N;j++){
			scanf("%d",&tmp[j]);
		}
		int flag = 0;
		if(tmp[0]>tmp[1]) flag = 1;
		else flag = 2; 
		flag = buildTree(Heap,tmp,flag);
    	root = tmp[0];
		if(flag==1) printf("Max Heap\n");
		else if(flag==2) printf("Min Heap\n");
		else if(flag ==3) printf("Not Heap\n");
		postOrder(Heap);
		printf("\n");
	}
}

int main(void)
{
	init();
	return 0;
}