#include<bits/stdc++.h>
using namespace std;
const int maxLen = 1e5;
int s;
std::vector<int> graph[maxLen];
std::vector<int> weight(maxLen);
bool isVisited[maxLen];
std::vector<int> tmp;
std::vector<std::vector<int> > res;
bool cmp(std::vector<int> a,std::vector<int> b){
	int len = min(a.size(),b.size());
	for(int i=0;i<len;i++){
		if(a[i]>b[i]) return true;
		else if(a[i]<b[i]) return false;
	}
}
void dfs(int node,int we){
	tmp.push_back(weight[node]);
	isVisited[node] = true;
	if(graph[node].size()==0){
		if(we==s){
			res.push_back(tmp);
		}
	}
	for(auto w:graph[node]){
		if(isVisited[w]==false){
			dfs(w,we+weight[w]);
		}
	}
	tmp.pop_back();
}
int main(int argc, char const *argv[])
{
	int n,m,id,k,idk;
	scanf("%d %d %d",&n,&m,&s);
	fill(isVisited,isVisited+n,false);
	for(int i=0;i<n;i++){
		scanf("%d",&weight[i]);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d",&id,&k);
		for(int j=0;j<k;j++){
			scanf("%d",&idk);
			graph[id].push_back(idk);
		}
	}
	dfs(0,weight[0]);
	sort(res.begin(),res.end(),cmp);
	for(auto w:res){
		int i=0;
		for(auto v:w){
			if(i==0) printf("%d", v);
			else printf(" %d", v);
			i++;
		}
		printf("\n");
	}
	return 0;
}
