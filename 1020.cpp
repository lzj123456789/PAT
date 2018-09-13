#include <bits/stdc++.h>
using namespace std;
std::vector<int> postOrder(31);
std::vector<int> inOrder(31);
typedef struct NODE *Node;
struct NODE{
	Node left;
	Node right;
	int data;
};
void levelOrder(Node root){
	int i=0;
	if(root==NULL) return;
	queue<Node> q;
	q.push(root);
	while(!q.empty()){
		Node tmp = q.front();
		if(i==0) {
			printf("%d",tmp->data );
			i++;
		}else printf(" %d", tmp->data);
		q.pop();
		if(tmp->left) q.push(tmp->left);
		if(tmp->right) q.push(tmp->right);
	}
}
void preOrder(Node node){
	if(node==NULL) return;
	printf("%d ", node->data);
	preOrder(node->left);
	preOrder(node->right);
}
Node build(int postl,int postr,int inl,int inr){
	if(postl>postr){
		return NULL;
	}
	Node node = new NODE;
	node->data = postOrder[postr];
	node->left = NULL;
	node->right = NULL;
	int i=inl;
	for(;i<=inr;i++){
		if(postOrder[postr]==inOrder[i]){
			break;
		}
	}
	int len = i-inl;
	node->left = build(postl,postl+len-1,inl,i-1);
	node->right = build(postl+len,postr-1,i+1,inr);
	return node;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<2;i++)
		for(int j=0;j<n;j++){
			if(i==0) scanf("%d",&postOrder[j]);
			else if(i==1) scanf("%d",&inOrder[j]);
		}
	Node Tree =  build(0,n-1,0,n-1);
	levelOrder(Tree);
	return 0;
}
