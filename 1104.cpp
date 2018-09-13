#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	std::vector<double> v(n+1);
	double res = 0;
	for(int i=1;i<=n;i++){
		scanf("%lf",&v[i]);
		res += v[i] * i* (n+1-i);
	}
	printf("%.2lf\n",res );
	return 0;
}
