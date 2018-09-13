#include <bits/stdc++.h>
using namespace std;
const int maxLen = 110;
std::vector<int> graph[maxLen];
std::vector<int> v(maxLen,0);
bool isVisited[maxLen];
int maxDepth=-1;
void dfs(int node,int depth){
	isVisited[node] = true;
	v[depth]++;
	if(depth>maxDepth) maxDepth = depth;
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
		for(int j=0;j<k;j++){
			scanf("%d",&idi);
			graph[id].push_back(idi);
		}
	}
	dfs(1,1);
	int maxIndex,maxFlag=-1;
	for(int i=1;i<=maxDepth;i++){
		if(v[i]>maxFlag){
			maxFlag = v[i];
			maxIndex = i;
		}
	}
	cout<<v[maxIndex]<<" "<<maxIndex<<endl;
	return 0;
}
