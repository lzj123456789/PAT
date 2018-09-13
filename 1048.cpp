#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,m,data;
	scanf("%d %d",&n,&m); 
	unordered_map<int,int> isexit(1e5);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		if(isexit.count(data)==0) isexit[data] = 1;
		else isexit[data] ++;
	}
	int v1,v2;
	for(int i=1;i<m/2;i++){
		v1 = i;v2 = m-v1;
		if(isexit.count(v1)&&isexit.count(v2)){
			if(v1==v2&&isexit[v1]<=1) continue;
			printf("%d %d\n",v1,v2 );
			return 0;
		}
	}
	printf("No Solution\n");
	return 0;
}
