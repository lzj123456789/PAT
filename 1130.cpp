#include <bits/stdc++.h>

using namespace std;
int n;

struct NODE{
	string data;
	int left;
	int right;
};
unordered_map<int,NODE> tree;
int root=1;
void inOrder(int node){
	if(node==-1){
		return ;
	}
	int flag = 0;
	if(tree[node].right!=-1&&node!=root)
	{
		printf("(");
		flag = 1;
	}
	inOrder(tree[node].left);
	cout<<tree[node].data;
	inOrder(tree[node].right);
	if(flag ==1){
		printf(")");
	}
}

void init(){
	scanf("%d",&n);
	string data;
	int left,right;
		
	unordered_map<int,bool> isChild;

	for(int i=1;i<n+1;i++){
		cin>>data>>left>>right;
		isChild[left] = true;
		isChild[right] = true;
		NODE node{data,left,right};
		tree[i] = node;
	}
	while(isChild.count(root)){
		root++;
	}
	inOrder(root);
}

int main(void){
	init();
}
