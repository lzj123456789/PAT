#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int maxLen = 500+10;
std::vector<int> graph[maxLen];
int d[maxLen][maxLen];
int c[maxLen][maxLen];
std::vector<int> pre[maxLen];
std::vector<int> tempPath,optPath;
int optCost = INF;
int n,m,s,d,c1,c2,di,co;
void dfs(int node){
	if(node==s){
		tempPath.push_back(node);
		int tmpCost = 0;
		for(auto i = 0;i<tempPath.size();i++){
			tmpCost+=c[tempPath[i]][tempPath[i+1]];
		}
		if(tmpCost<optCost){
			optCost = tmpCost;
			optPath = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(node);
	for(auto w:pre[node]){
		dfs(w);
	}
	tempPath.pop_back();
}
void dijkstra(int s){
	bool isVisited[maxLen]={false};
	int dis[maxLen] = {INF};
	dis[s] = 0;
	for(int i=0;i<n;i++){
		int minFlag = INF;
		int k = -1;
		for(int j=0;j<n;j++){
			if(isVisited[j]==false&&dis[j]<minFlag){
				minFlag = dis[j];
				k = j;
			}
		}
		if(k==-1) return;
		isVisited[j] = true;
		for(auto w:graph[k]){
			if(isVisited[w]==false&&d[k][w]!=INF){
				if(dis[k]+d[k][w]<dis[w]){
					dis[w] = dis[k]+d[k][w];
					pre[w].clear();
					pre[w].push_back(k);
				}else if(dis[k]+d[k][w]==dis[w]){
					pre[w].push_back(k);
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n,&m,&s,&d);
	fill(d[0],d[0]+maxLen*maxLen,INF);
	fill(c[0],c[0]+maxLen*maxLen,INF);
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d",&c1,&c2,&di,&co);
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
		d[c1][c2] = di;
		d[c2][c1] = di;
		c[c1][c2] = co;
		c[c2][c1] = co;
	}
	dijkstra(s);
	dfs(d);
	return 0;
}