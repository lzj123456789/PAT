#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long long int n;
	scanf("%lld",&n);
	int maxLen=-1;
	long long int tmp;
	int index;
	for(long long int i=2;i*i<=n;i++){
		if(n%i==0){
			tmp=i;
			int len = 1;
			for(long long int j=i+1;j*2<=n;j++){
				if(n%j==0){
					len++;
					tmp *= j;
					if(tmp>=n) break;
				}else break;
			}
			if(len>maxLen){
				maxLen = len;
				index = i;
			}
		}
	}
	if(maxLen<1){
		printf("1\n%lld",n);
		return 0;
	}
	long long int i=0;
	printf("%d\n",maxLen);
	for(i=0;i<maxLen;i++){
		if(i==0) printf("%lld", i+index);
		else printf("*%lld",i+index );
	}
	return 0;
}
