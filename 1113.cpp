#include <bits/stdc++.h>
using namespace std;
int n;
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	int input;
	std::vector<int> v;
	for(int i=0;i<n;i++){
		scanf("%d",&input);
		v.push_back(input);
	}
	sort(v.begin(),v.end());
	int i=1;
	int n1=0,n2=0,s1=0,s2=0;
	for(auto w:v){
		if(i<=n/2){
			n1++;
			s1 += w;
		}else{
			n2++;
			s2+=w;
		}
		i++;
	}
	printf("%d %d\n",n2-n1,s2-s1 );
	return 0;
}
