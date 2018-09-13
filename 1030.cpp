#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXLEN = 500+10;
unordered_map<int,std::vector<int> > graph;
int D[MAXLEN][MAXLEN] ;
int c[MAXLEN][MAXLEN] ;
std::vector<int> pre[MAXLEN];
std::vector<int> tempPath,optPath;
int n,m,s;
int optCost = INF;
void dfs(int node){
	if(node==s){
		tempPath.push_back(node);
		int tmpCost =0;//注意初始化
		for(auto i=0;i<tempPath.size()-1;i++){
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
	for(auto v:pre[node]){
		dfs(v);
	}
	tempPath.pop_back();
}
void dijkstra(int s){
	bool isVisited[MAXLEN] ={false};
	int d[MAXLEN];
	fill(d,d+MAXLEN,INF);
	d[s] = 0;
	for(int i=0;i<n;i++){
		int minFlag = INF;
		int u = -1;
		for(auto v:graph){
			if(isVisited[v.first]==false&&d[v.first]<minFlag){
				minFlag = d[v.first];
				u = v.first;
			}
		}
		isVisited[u] = true;
		for(auto v:graph[u]){
			if(isVisited[v]==false&&D[u][v]!=INF){
				if(d[u]+D[u][v]<d[v]){
					d[v] = d[u]+D[u][v];
					pre[v].clear();
					pre[v].push_back(u);
				}else if(d[u]+D[u][v]==d[v]){
					pre[v].push_back(u);
				}
			}
		}
	}
}
int main(int argc, char const *argv[])
{
	int d,c1,c2,distance,cost;
	fill(D[0],D[0]+MAXLEN*MAXLEN,INF);
	scanf("%d %d %d %d",&n,&m,&s,&d);
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d",&c1,&c2,&distance,&cost);
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
		D[c1][c2] = distance;
		D[c2][c1] = distance;
		c[c1][c2] = cost;
		c[c2][c1] = cost;
	}
	dijkstra(s);
	dfs(d);
	reverse(optPath.begin(),optPath.end());
	int totalCost=0,totalDis=0;
	for(auto w=0;w<optPath.size()-1;w++){
		totalCost+=c[optPath[w]][optPath[w+1]];
		totalDis+=D[optPath[w]][optPath[w+1]];
	}
	for(auto w:optPath){
		cout<<w<<" ";
	}
	cout<<totalDis<<" "<<totalCost;
	return 0;
}
