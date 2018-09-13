#include <bits/stdc++.h>
using namespace std;
double p,r;
const int maxLen = 100010;
std::vector<int> graph[maxLen];
bool isVisited[maxLen];
int maxDepth = -1;
int current = 0;
void dfs(int node,int depth){
	isVisited[node] = true;
	if(graph[node].size()==0){
		if(maxDepth<depth){
			maxDepth = depth;
			current=1;
		}else if(maxDepth==depth){
			current++;
		}
	//	cout<<node<<" "<<maxDepth<<" "<<current<<endl;
	}
	for(auto w:graph[node]){
		if(isVisited[w]==false){
			dfs(w,depth+1);
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,supplier;
	scanf("%d %lf %lf",&n,&p,&r);
	fill(isVisited,isVisited+n,false);
	int root;
	for(int i=0;i<n;i++){
		scanf("%d",&supplier);
		if(supplier!=-1) graph[supplier].push_back(i);
		else root = i;
	}
	dfs(root,0);
	printf("%.2lf %d\n",p*pow(1+0.01*r,maxDepth),current );
	return 0;
}
