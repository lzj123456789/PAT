#include <bits/stdc++.h>
using namespace std;
const int MaxLen = 1010;
std::vector<int> graph[MaxLen];
int main(int argc, char const *argv[])
{
	int n,m,v1,v2;
	scanf("%d %d",&n,&m);
	std::vector<int> inDegree(n+1,0);
	for(int i=0;i<m;i++){
		scanf("%d %d",&v1,&v2);
		graph[v1].push_back(v2);
		inDegree[v2] +=1;
	}
	int k,v;
	scanf("%d",&k);
	std::vector<int> res;
	for(int i=0;i<k;i++){
		int flag = true;
		std::vector<int> tmp(inDegree);
		for(int j=1;j<=n;j++){
			scanf("%d",&v);
		//	printf("%d %d ",v,tmp[v]); 
			if(tmp[v]==0){
				for(auto w:graph[v]){
					tmp[w] --;
				}
			}else{
				flag = false;
			}
		//	printf("\n");
		}
		if(flag == false) res.push_back(i);
	}
	int i=0;
	for(auto w:res){
		if(i==0) printf("%d", w);
		else printf(" %d", w);
		i++;
	}
	return 0;
}
