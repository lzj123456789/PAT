#include <bits/stdc++.h>
using namespace std;
typedef struct NODE *Node;
struct NODE{
	Node left;
	Node right;
	int data;
};
int getHeight(Node node){
	if(node==NULL) return 0;
	int l = getHeight(node->left);
	int r = getHeight(node->right);
	return max(l,r)+1;
}
Node rotateR(Node node){
	Node tmp = node->left;
	node->left = tmp->right;
	tmp->right = node;
	return tmp;
}
Node rotateL(Node node){
	Node tmp = node->right;
	node->right = tmp->left;
	tmp->left = node;
	return tmp;
}
Node rotateLR(Node node){
	node->left = rotateL(node->left);
	return rotateR(node);
}
Node rotateRL(Node node){
	node->right = rotateR(node->right);
	return rotateL(node);
}
Node insert(Node node,int data){
	if(node==NULL){
		node = new NODE();
		node->data = data;
		node->left = node->right = NULL;
	}else if(data<node->data){
		node->left = insert(node->left,data);
		int l = getHeight(node->left),r = getHeight(node->right);
		if(l-r==2){
			if(data<node->left->data){
				node = rotateR(node);
			}else{
				node = rotateLR(node);
			}
		}
	}else {
		node->right = insert(node->right,data);
		int l = getHeight(node->left),r = getHeight(node->right);
		if(r-l==2){
			if(data>node->right->data){
				node = rotateL(node);
			}else{
				node = rotateRL(node);
			}
		}
	}
	return node;
}
int main(int argc, char const *argv[])
{
	int n,data;
	scanf("%d",&n);
	Node tree = NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		tree = insert(tree,data);
	}
	printf("%d\n",tree->data );
	return 0;
}
