#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<int,int> inOrder;
unordered_map<int,int> postOrder;
unordered_map<int,int> tree;
int lastPlace=-1;
void buildTree(int inl,int inr,int postl,int postr,int node){
	if(inl>inr||inl>=n||inr>=n) return;
	tree[node] = postOrder[postr];
	if(node>lastPlace) lastPlace = node;
	int i;
	for(i=inl;i<=inr;i++){
		if(inOrder[i]==postOrder[postr]){
			break;
		}
	}
	buildTree(inl,i-1,postl,postl+(i-inl)-1,2*node);
	buildTree(i+1,inr,i,postr-1,2*node+1);
}
void printfTree(){
	bool flag = false;
	if(tree.size()==0) return;
	if(tree.size()>=1) {
		printf("%d", tree[1]); 
	}
	for(int i=2;i<lastPlace;i=i*2){
		if(flag==false)
			for(int j=i;j<i*2;j++){
				if(tree.count(j)!=0){
					printf(" %d", tree[j]);
				}
			}
		else{
			for(int j=2*i-1;j>=i;j--){
				if(tree.count(j)!=0){
					printf(" %d", tree[j]);
				}
			}
		}
		flag = !flag;
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	int data;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&data);
		inOrder[i] = data;
	}
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&data);
		postOrder[i] = data;
	}
	buildTree(0,n-1,0,n-1,1);
	printfTree();
	return 0;
}
