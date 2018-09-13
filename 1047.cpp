#include <bits/stdc++.h>
using namespace std;
char name[40010][5];
bool cmp(int a,int b){
	return strcmp(name[a],name[b])<0;
}
int main(int argc, char const *argv[])
{
	int n,k,c,course;
	scanf("%d %d",&n,&k);
	std::vector<int> v[2510];
	for(int i=0;i<n;i++){
		scanf("%s %d",name[i],&c);
		for(int j=0;j<c;j++){
			scanf("%d",&course);
			v[course].push_back(i);
		}
	}
	for(int i=1;i<=k;i++){
		printf("%d %d\n",i,v[i].size() );
		sort(v[i].begin(),v[i].end(),cmp);
		for(auto w:v[i]){
			printf("%s\n",name[w] );
		}
	}
	return 0;
}