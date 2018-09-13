#include <bits/stdc++.h>
using namespace std;
const int maxLen = 1e3;
std::vector<int> graph[maxLen];
int n,m;
bool isVisited[maxLen] = {false};
int isEul=0;
void dfs(int node){
	isVisited[node] = true;
	isEul++;
	for(auto w:graph[node]){
		if(isVisited[w]==false){
			dfs(w);
		}
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&m);
	int v1,v2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d %d",&v1,&v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
	}
	int odd=0,even=0;
	for (int i = 1; i <= n; ++i)
	{	
		if(int(graph[i].size())%2==0){
			even ++;
		}else{
			odd ++;
		}
		if(i==1) {
			printf("%d",graph[i].size() );
		}
		else printf(" %d", graph[i].size());
	}
	dfs(1);
	printf("\n");
//	printf("%d %d %d\n",even,odd,isEul );
	if(isEul==n&&even==n){
		printf("Eulerian\n");
	}else if(isEul==n&&odd==2){
		printf("Semi-Eulerian\n");
	}else {
		printf("Non-Eulerian\n");
	}
	
	return 0;
}
