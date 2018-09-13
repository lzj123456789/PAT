#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m,data;
	scanf("%d",&n);
	unordered_set<int> v[51];
	for(int i=1;i<=n;i++){
		scanf("%d",&m);
		for(int j=0;j<m;j++){
			scanf("%d",&data);
			v[i].insert(data);
		}
	}
	int k,a,b;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %d",&a,&b);
		int same = 0,total=0;
		unordered_map<int,bool> tmp;
		for(auto w:v[a]){
			tmp[w] = true;
			total++;
		}
		for(auto w:v[b]){
			if(tmp.count(w)) same++;
			
		}
		printf("%.1lf%%\n",1.0*same/(v[a].size()+v[b].size()-same)*100 );
	}
	return 0;
}
