#include <bits/stdc++.h>
using namespace std;
int n,m;
unordered_map<int,std::vector<int> > graph; 
unordered_map<int,bool> isEdge;
int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&m);
	int v1,v2;
	for(int i=0;i<m;i++){
		scanf("%d %d",&v1,&v2);
		graph[v1].push_back(v2);
		graph[v2].push_back(v1);
		isEdge[v1*201+v2] = true;
		isEdge[v2*201+v1] = true;
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		int nv,v;
		scanf("%d",&nv);
		std::vector<int> ve;
		set<int> setV;
		bool flag=true;
		for(int j=0;j<nv;j++){
			scanf("%d",&v);
			ve.push_back(v);
			setV.insert(v);
		}
		for(auto j=1;j<ve.size();j++){
			if(isEdge.count(ve[j]*201+ve[j-1])==0){
				flag = false;
			}
		}
		if(nv!=n+1||flag==false||setV.size()!=n){
			printf("NO\n");
			continue;
		}
		if(ve[0]==ve[nv-1]){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}
