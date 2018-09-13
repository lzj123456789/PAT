/*
 * int line[maxn][maxn]={0};
 * bool vis[maxn]={false};
 */

#include <bits/stdc++.h>
using namespace std;
int n;
const int maxLen = 1e4;
std::vector<std::vector<int> > graph;
void init(){
	scanf("%d",&n);
	int m;
	int first,second;
	unordered_map<int,int> line;
	for(int i=0;i<n;i++){
		scanf("%d",&m);
		if(m>1) {
			scanf("%d",&first);
		}
		for(int j=1;j<m;j++){
			scanf("%d",&second);
			graph[first].push_back(second);
			graph[second].push_back(first);
			line[first*maxLen+second] = i;
			line[second*maxLen+first] = i;
		}


	}
}
int main(int argc, char const *argv[])
{
	init();
	return 0;
}