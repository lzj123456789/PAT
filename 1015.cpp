#include <bits/stdc++.h>
using namespace std;
bool isPrime(int a){
	if(a<=1) return false;
	for(int i=2;i*i<=a;i++){
		if(a%i==0)
			return false;
	}
	return true;
}
int rev(int a,int d){
	std::vector<int> v;
	while(a){
		v.push_back(a%d);
		a = a/d;
	}
	int res=0;
	for(auto w:v){
		res  = res*d+w;
	}
	return res ;
}
int main(int argc, char const *argv[])
{
	int a,b;
	while(scanf("%d",&a)!=EOF){
		if(a==-2) break;
		scanf("%d",&b);
		if(isPrime(a)&&isPrime(rev(a,b))){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}
	return 0;
}
