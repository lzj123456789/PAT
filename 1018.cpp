#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
const int MAXLEN = 500+10;
int cmax,n,sp,m;
unordered_map<int,std::vector<int> > graph;
int c[MAXLEN];
int D[MAXLEN][MAXLEN];
std::vector<int> pre[MAXLEN];
std::vector<int> optPath,tmpPath;
int optSend=INF,optBack=INF;
void dfs(int node){
	if(node==0){
		int tmpSend = INF,tmpBack=0;
		tmpPath.push_back(node);
		for(auto i=tmpPath.size()-1;i>=1;i--){
			if(i==tmpPath.size()-1){
				tmpSend = cmax-c[tmpPath[i-1]];
			}
			tmpBack += c[tmpPath[i]];
		}
		
		tmpBack = tmpBack+tmpSend-(tmpPath.size()-1)*(cmax/2);
		if(tmpSend<optSend){
			optSend = tmpSend;
			optBack = tmpBack;
			optPath = tmpPath;
		}else if(tmpSend==optSend){
			if(tmpBack<optBack){
				optSend = tmpSend;
				optBack = tmpBack;
				optPath = tmpPath;
			}
		}
		tmpPath.pop_back();
		return;
	}
	tmpPath.push_back(node);
	for(auto v:pre[node]){
		dfs(v);
	}
	tmpPath.pop_back();
}
void dijkstra(int s){
	bool isVisited[MAXLEN]={false};
	int d[MAXLEN];
	fill(d,d+MAXLEN,INF);
	d[s] = 0;
	for(int i=0;i<n+1;i++){
		int minFlag = INF,u=-1;
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
					d[v] = d[u] + D[u][v];
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
	scanf("%d %d %d %d",&cmax,&n,&sp,&m);
	fill(D[0],D[0]+MAXLEN*MAXLEN,INF);
	for(int i=1;i<=n;i++){
		scanf("%d",&c[i]);
	}
	int si,sj,tij;
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&si,&sj,&tij);
		graph[si].push_back(sj);
		graph[sj].push_back(si);
		D[si][sj] = tij;
		D[sj][si] = tij;
	}
	dijkstra(0);
	dfs(sp);
	cout<<optSend<<" ";
	for(int i=optPath.size()-1;i>=0;i--){
		if(optPath[i]==0) cout<<0;
		else cout<<"->"<<optPath[i];
	}
	cout<<" "<<optBack<<endl;
	return 0;
}
