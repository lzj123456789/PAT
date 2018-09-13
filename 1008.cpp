#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	std::vector<int> v(n+1);
	v[0] = 0;
	int res=0;
	for(int i=1;i<=n;i++){
		scanf("%d",&v[i]);
		res += (v[i]>v[i-1])?(6*(v[i]-v[i-1])):(4*(v[i-1]-v[i]));
		//printf("%d\n",res );
	}	
	res += n*5;
	printf("%d\n", res);
	return 0;
}
