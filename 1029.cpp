#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	std::vector<long int> v(200010);
	int index=0;
	int len=0;
	for(int i=0;i<2;i++){
		int n;
		scanf("%d",&n);
		len += n;
		long int data;
		for(int j=0;j<n;j++){
			scanf("%ld",&v[index]);
			index++;
		}
	}
	sort(v.begin(),v.begin()+len);
	printf("%ld\n",v[len/2] );
	return 0;
}