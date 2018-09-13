#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,data;
	scanf("%d",&n);
	int flag[10010];
	std::vector<int> v;
	fill(flag,flag+10010,0);
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		v.push_back(data);
		flag[data]++;
	}
	for(auto w:v){
		if(flag[w]==1){
			printf("%d\n", w);
			return 0;
		}
	}
	printf("None\n");
	return 0;
}
