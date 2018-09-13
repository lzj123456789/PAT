#include <bits/stdc++.h>
using namespace std;
struct NODE{
	int left;
	int right;
	int data;
};
int n;
std::vector<int> weight(100);
unordered_map<int,NODE > graph;
int now = 0;
int k = 0;
void bfs(int node){
	if(graph.count(node)==0) return;
	queue<NODE> q;
	q.push(graph[node]);
	while(!q.empty()){
		NODE tmp = q.front();
		if(k==0){
			printf("%d",tmp.data );
			k++;
		}
		else printf(" %d",tmp.data );
		q.pop();
		if(tmp.left!=-1) q.push(graph[tmp.left]);
		if(tmp.right!=-1) q.push(graph[tmp.right]);
	}
}
void inOrder(int node){
	if(node==-1) return;
	inOrder(graph[node].left);
	graph[node].data = weight[now++];
	inOrder(graph[node].right);
}
int main(int argc, char const *argv[])
{
	int left,right;
	NODE tmp;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d %d",&left,&right);
		//cout<<left<<right;
		tmp.left = left;
		tmp.right = right;
		tmp.data = -1;
		graph[i] = tmp;
	}
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	sort(weight.begin(),weight.begin()+n);
	inOrder(0);
	bfs(0);
	return 0;
}
