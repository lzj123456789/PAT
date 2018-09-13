#include<bits/stdc++.h>
using namespace std;
bool isPrime(int a){
	if(a<=1) return false;
	for(int i =2;i*i<=a;i++){
		if(a%i==0)
			return false;
	}
	return true;
}
int findMinPrime(int a){
	int res=a;
	while(!isPrime(res)){
		res++;
	}
	return res;
}
int main(int argc, char const *argv[])
{
	int msize,n;
	scanf("%d %d",&msize,&n);
	msize = findMinPrime(msize);
	std::vector<int> isUsed(msize,0);
	std::vector<int> loc(n,-1);
	int data;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		for(int j=0;j<msize;j++){
			if(isUsed[(data+j*j)%msize]==0){
				isUsed[(data+j*j)%msize] = 1;
				loc[i] = (data+j*j)%msize;
				break;
			}
		}
	}
	int i=0;
	for(auto w:loc){
		if(w== -1){
			if(i==0){
				printf("-");
				i++;
			}else{
				printf(" -");
			}
		}else{
			if(i==0){
				printf("%d",w );
				i++;
			}else{
				printf(" %d",w );
			}
		}
	}
	return 0;
}
