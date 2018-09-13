#include <bits/stdc++.h>
using namespace std;
const int maxLen = 1e5;
std::vector<int> graph[maxLen];
std::vector<int> v(maxLen,0);
bool isVisited[maxLen];
int maxDepth=-1;
void dfs(int node,int depth){
	isVisited[node] = true;
	if(graph[node].size()==0){
		v[depth]++;
	}
	if(maxDepth<depth){
		maxDepth = depth;
	}
	for(auto w:graph[node]){
		if(isVisited[w]==false){
			dfs(w,depth+1);
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,m,id,idi,k;
	scanf("%d %d",&n,&m);
	fill(isVisited,isVisited+n,false); 
	for(int i=0;i<m;i++){
		scanf("%d %d",&id,&k);
		for(int i=0;i<k;i++){
			scanf("%d",&idi);
			graph[id].push_back(idi);
		}
	}
	dfs(1,1);
	for(int i=1;i<=maxDepth;i++){
		if(i==1) printf("%d",v[i] );
		else printf(" %d",v[i] );
	}
	return 0;
}
