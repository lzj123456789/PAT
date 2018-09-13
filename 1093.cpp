#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char data[100010];
	scanf("%s",data);
	int len = strlen(data);
	int num[100010];
	fill(num,num+len,0);
	if(data[0]=='P') num[0]=1;
	else num[0] = 0;
	for(int i=1;i<len;i++){
		if(data[i]=='P'){
			num[i] = num[i] + num[i-1]+1;
		}else {
			num[i] = num[i-1];
		}
	}
	int count=0;
	long int res=0;
	for(int i=len-1;i>=0;i--){
		if(data[i]=='T'){
			count++;
		}else if(data[i]=='A'){
			res += num[i]*count;
		}
	}
	cout<<res%1000000007;
	return 0;
}
