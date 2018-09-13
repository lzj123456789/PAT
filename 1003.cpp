#include <bits/stdc++.h>
using namespace std;
const int maxLen=500+5;
const int INF = 1e6;
int n,m,c1,c2;
int teams[maxLen];
int D[maxLen][maxLen];
unordered_map <int,std::vector<int> > graph;
int main(void){
	fill(D[0],D[0]+maxLen*maxLen,INF);
	int s,d;
	cin>>n>>m>>s>>d;
	int team;
	for(int i=0;i<n;i++){
		scanf("%d",&team);
		teams[i] = team;
	}
	int l;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&c1,&c2,&l);
		D[c1][c2] = l;
		D[c2][c1] = l;
		graph[c1].push_back(c2);
		graph[c2].push_back(c1);
	}
	int dis[maxLen];
	fill(dis,dis+maxLen,INF);
	dis[s] = 0;
	int num[maxLen];
	fill(num,num+maxLen,INF);
	num[s] = 1;
	bool isVisited[maxLen];
	fill(isVisited,isVisited+maxLen,false);
	int maxGather[maxLen];
	fill(maxGather,maxGather+maxLen,INF);
	maxGather[s] = teams[s];
	for(int i=0;i<n;i++){
		int minFlag=INF;
		int u = -1;
		for(auto v:graph){
			if(isVisited[v.first]==false&&dis[v.first]<minFlag){
				minFlag = dis[v.first];
				u = v.first;
			}
		}
		isVisited[u] = true;
		for(auto v:graph[u]){
			if(isVisited[v]==false&&D[u][v]!=INF){
				if(dis[u]+D[u][v]<dis[v]){
					dis[v] = dis[u]+D[u][v];
					num[v] = num[u];
					maxGather[v] = maxGather[u]+teams[v];
				}else if(dis[u]+D[u][v]==dis[v]){
					num[v] += num[u];//可能有很多条 易错点
					if(maxGather[v]<maxGather[u]+teams[v]){
						maxGather[v] = maxGather[u]+teams[v];
					}
				}
			}
		}
	}
	cout<<num[d]<<" "<<maxGather[d]<<endl;
}