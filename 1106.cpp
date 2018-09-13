#include <bits/stdc++.h>
using namespace std;
double p,r;
const int maxLen = 100010;
std::vector<int> graph[maxLen];
unordered_map<int,int> mapV;
bool isVisited[maxLen];
int minDepth=1e9;
void dfs(int node,int depth){
	isVisited[node] = true;
	if(graph[node].size()==0){
		if(depth<minDepth){
			minDepth = depth;
		}
		if(mapV.count(depth)==0) mapV[depth] = 1;
		else mapV[depth] ++;
	}
	for(auto w:graph[node]){
		if(isVisited[w]==false){
			dfs(w,depth+1);
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,k,data;
	scanf("%d %lf %lf",&n,&p,&r);
	fill(isVisited,isVisited+n,false);
	for(int i=0;i<n;i++){
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			scanf("%d",&data);
			graph[i].push_back(data);
		}
	}
	dfs(0,0);
	printf("%.4lf %d\n",p*pow(1+0.01*r,minDepth) ,mapV[minDepth]);
	return 0;
}