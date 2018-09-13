#include <bits/stdc++.h>
using namespace std;
std::vector<int> preOrder;
std::vector<int> inOrder;
int n;
typedef struct NODE *Node;
struct NODE{
	Node left;
	Node right;
	int data;
};
int flag = 1;
void postOrder(Node node){
	if(node==NULL) return;
	postOrder(node->left);
	postOrder(node->right);
	if(flag==1) {
		printf("%d", node->data);
		flag ++;
	}
	else {
		printf(" %d", node->data);
	}
}
Node build(int prel,int prer,int inl,int inr){
	if(prel>prer) return NULL;
	Node node = new NODE;
	node->data = preOrder[prel];
	int i = inl;
	for(;i<=inr;i++){
		if(preOrder[prel]==inOrder[i])
			break;
	}
	int len = i- inl;
	node->left = build(prel+1,prel+len,inl, i-1);
	node->right = build(prel+len+1,prer, i+1,inr);
	return node;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	string data;
	stack<int> s;
	for(int i=0;i<2*n;i++){
		cin>>data;
		//cout<<tmp;
		if(data=="Push"){
			int num;
			scanf("%d",&num);
			//cout<<num<<endl; 
			preOrder.push_back(num);
			s.push(num);
		}else if(data=="Pop"){
			int num = s.top();
			//cout<<num<<endl;
			s.pop();
			inOrder.push_back(num);
		}
	}
	Node tree =  build(0,n-1,0,n-1);
	postOrder(tree);
	return 0;
}


/*
链接：https://www.nowcoder.com/questionTerminal/bde2979e11704031b5ab449d97b7d4c9
来源：牛客网

19
Push 4
Push 11
Push 7
Push 12
Pop
Pop
Pop
Push 14
Push 17
Pop
Pop
Push 6
Push 18
Pop
Push 8
Pop
Pop
Push 4
Pop
Pop
Push 11
Push 16
Push 11
Push 12
Pop
Push 2
Pop
Pop
Pop
Push 7
Push 4
Pop
Pop
Push 12
Pop
Pop
Push 11
Pop
*/
