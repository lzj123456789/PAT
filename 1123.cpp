#include <bits/stdc++.h>
using namespace std;
typedef struct NODE* Node;
struct NODE{
	int data;
	Node left;
	Node right;
};
int n;
int getHeight(Node node){
	if(node==NULL){
		return 0;
	}
	int l= getHeight(node->left);
	int r = getHeight(node->right);
	return max(l,r)+1;
}
Node rotateR(Node &a){
	Node tmp = a->left;
	a->left = tmp->right;
	tmp->right=a;
	return tmp;
}
Node rotateL(Node &a){
	Node tmp = a->right;
	a->right = tmp->left;
	tmp->left = a;
	return tmp;
}
Node rotateLR(Node &a){
	a->left = rotateL(a->left);
	return rotateR(a);
}
Node rotateRL(Node &a){
	a->right = rotateR(a->right);
	return rotateL(a);
}
void insert(Node &node,int data){
	if(node==NULL){
		node = new NODE();
		node->data = data;
		return;
	}
	if(node->data>data){
		insert(node->left,data);
		int l,r;
		r = getHeight(node->right);
		l = getHeight(node->left);
		if(l-r>=2){
			if(data<node->left->data){
				node = rotateR(node);
			}else{
				node = rotateLR(node);
			}
		}
	}else{
		insert(node->right,data);
		int l,r;
		r = getHeight(node->right);
		l = getHeight(node->left);
		if(r-l>=2){
			if(data>node->right->data){
				node = rotateL(node);
			}else{
				node = rotateRL(node);
			}
		}
	}
}
int isCom=1,tmpFlag=0;
void levelOrder(Node root){
	queue<Node> q;
	q.push(root);
	int i=1;
	while(!q.empty()){
		Node node = q.front();
		q.pop();
		if(i==1) printf("%d",node->data );
		else printf(" %d",node->data);
		if(node->left){
			q.push(node->left);
			if(tmpFlag) isCom=0;
		}else{
			tmpFlag = 1;
		}
		if(node->right){
			q.push(node->right);
			if(tmpFlag) isCom = 0;
		}else{
			tmpFlag = 1;
		}
		i++;
	}
}
int main(void){
	scanf("%d",&n);
	int data;
	Node root=NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		insert(root,data);
	}
	levelOrder(root);
	printf("\n%s", isCom?"YES":"NO");
}
