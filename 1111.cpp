#include <bits/stdc++.h>
using namespace std;
const int MAXLEN = 500+10;
const int INF = 1e9;
int n,m,s;
int L[MAXLEN][MAXLEN],T[MAXLEN][MAXLEN];
std::vector<int> preL[MAXLEN],preT[MAXLEN];
unordered_map<int,std::vector<int> > graph;
std::vector<int> optPath,tempPath;
int optTime=INF,optdis;
void dfsDis(int node){
	if(node==s){
		int tempTime = 0,tempdis=0;
		tempPath.push_back(node);
		
		for(int i=tempPath.size()-1;i>=1;i--){
			int v1 = tempPath[i],v2=tempPath[i-1];
			tempTime += T[v1][v2];
			tempdis+=L[v1][v2];
		}
		if(tempTime<optTime){
			optTime = tempTime;
			optdis = tempdis;
			optPath = tempPath;
		}
		tempPath.pop_back();
		return;
	}
	tempPath.push_back(node);
	for(auto v:preL[node]){
		dfsDis(v);
	}
	tempPath.pop_back();
}

std::vector<int> optPathTime,tempPathTime;
int leastNode=INF;
void dfsTime(int node){
	if(node==s){
		tempPathTime.push_back(node);
		if(tempPathTime.size()<leastNode){
			leastNode = tempPathTime.size();
			optPathTime = tempPathTime;
		}
		tempPathTime.pop_back();
		return;
	}
	tempPathTime.push_back(node);
	for(auto w:preT[node]){
		dfsTime(w);
	}
	tempPathTime.pop_back();
}



void dijkstraDis(int s){
	bool isVisited[MAXLEN] = {false};
	int d[MAXLEN];
	fill(d,d+MAXLEN,INF);
	d[s] = 0;
	for(int i=0;i<n;i++){
		int minFlag = INF,u=-1;
		for(auto v:graph){
			if(isVisited[v.first]==false&&d[v.first]<minFlag){
				minFlag = d[v.first];
				u = v.first;
			}
		}
		isVisited[u] = true;
		for(auto v:graph[u]){
			if(isVisited[v]==false&&L[u][v]!=INF){
				if(d[u]+L[u][v]<d[v]){
					d[v] = d[u]+L[u][v];
					preL[v].clear();
					preL[v].push_back(u);
				}else if(d[u]+L[u][v]==d[v]){
					preL[v].push_back(u);
				}
			}
		}
	}
}

void dijkstraTime(int s){
	bool isVisited[MAXLEN] = {false};
	int d[MAXLEN];
	fill(d,d+MAXLEN,INF);
	d[s] = 0;
	for(int i=0;i<n;i++){
		int minFlag = INF,u=-1;
		for(auto v:graph){
			if(isVisited[v.first]==false&&d[v.first]<minFlag){
				minFlag = d[v.first];
				u = v.first;
			}
		}
		isVisited[u] = true;
		for(auto v:graph[u]){
			if(isVisited[v]==false&&T[u][v]!=INF){
				if(d[u]+T[u][v]<d[v]){
					d[v] = d[u]+T[u][v];
					preT[v].clear();
					preT[v].push_back(u);
				}else if(d[u]+T[u][v]==d[v]){
					preT[v].push_back(u);
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	fill(L[0],L[0]+MAXLEN*MAXLEN,INF);
	fill(T[0],T[0]+MAXLEN*MAXLEN,INF);
	scanf("%d %d",&n,&m);
	int v1,v2,oneway,length,time;
	for(int i=0;i<m;i++){
		scanf("%d %d %d %d %d",&v1,&v2,&oneway,&length,&time);
		if(oneway){
			graph[v1].push_back(v2);
			L[v1][v2] = length;
			T[v1][v2] = time;
		}else{
			graph[v1].push_back(v2);
			graph[v2].push_back(v1);
			L[v1][v2] = length;
			T[v1][v2] = time;
			L[v2][v1] = length;
			T[v2][v1] = time;
		}
	}
	int d;
	scanf("%d %d",&s,&d);
	dijkstraDis(s);
	dfsDis(d);
	
	dijkstraTime(s);
	dfsTime(d);
	int totalTime = 0;
	bool isSame = true;
	if(optPathTime.size()==optPath.size())
		for(int i=0;i<optPathTime.size()-1;i++){
			int v1 = optPathTime[i],v2 = optPathTime[i+1];
			if(optPathTime[i]!=optPath[i]||optPathTime[i+1]!=optPath[i+1]){
				isSame = false;
			}
			totalTime+= T[v2][v1];
		}
	else{
		isSame = false;
		for(int i=0;i<optPathTime.size()-1;i++){
			int v1 = optPathTime[i],v2 = optPathTime[i+1];
			totalTime+= T[v2][v1];
		}
	}
	if(isSame==false){
		printf("Distance = %d: %d", optdis,optPath[optPath.size()-1]);
		for(int i=optPath.size()-2;i>=0;i--){
			printf(" -> %d", optPath[i]);
		}
		printf("\n");
		printf("Time = %d: %d", totalTime,optPathTime[optPathTime.size()-1]);
		for(int i=optPathTime.size()-2;i>=0;i--){
			printf(" -> %d", optPathTime[i]);
		}	
	}else{
		printf("Distance = %d; ", optdis);
		printf("Time = %d: %d", totalTime,optPathTime[optPathTime.size()-1]);
		for(int i=optPath.size()-2;i>=0;i--){
			printf(" -> %d", optPath[i]);
		}
	}
	
	return 0;
}
