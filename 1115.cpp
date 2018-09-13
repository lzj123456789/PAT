#include <bits/stdc++.h>
using namespace std;
typedef struct NODE *Node;
struct NODE{
	Node left;
	Node right;
	int data;
	int depth;
};
std::vector<int> depthNum;
int maxDepth=-1;
void insert(Node &node,int data,int depth){
	if(node==NULL){
		node = new NODE();
		node->data = data;
		node->depth = depth;
		depthNum.push_back(node->depth);
		if(node->depth>maxDepth) maxDepth=node->depth;
		return;
	}
	if(node->data>=data){
		insert(node->left,data,node->depth+1);
	}else{
		insert(node->right,data,node->depth+1);
	}
}
int n,input;
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	Node root = NULL;
	for(int i=0;i<n;i++){
		scanf("%d",&input);
		insert(root,input,0);
	}
	unordered_map<int,int> res;
	res[maxDepth] = 0;
	res[maxDepth-1] = 0;
	for(auto w:depthNum){
		if(w==maxDepth){
			res[maxDepth]++;
		}else if(w==maxDepth-1){
			res[maxDepth-1]++;
		}
	}
	printf("%d + %d = %d\n", res[maxDepth],res[maxDepth-1],res[maxDepth]+res[maxDepth-1]);
	return 0;
}
