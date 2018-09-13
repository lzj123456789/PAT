#include <bits/stdc++.h>
using namespace std;
struct NODE{
	int prime;
	int num;
};
bool isPrime(long int a){
	if(a<=1) return false;
	for(long int i=2;i*i<=a;i++){
		if(a%i==0)
			return false;
	}
	return true;
}
int main(int argc, char const *argv[])
{
	long int n;
	scanf("%ld",&n);
	NODE tmp;
	printf("%ld=", n);
	
	if(isPrime(n)||n==1){
		printf("%ld",n);
		return 0;
	} 
	
	int j=0;
	long int boundn = n;
	for(long int i=2;i*i<=boundn;i++){
		if(isPrime(i)&&(n%i==0)){
			tmp.prime = i;
			tmp.num = 0;
			while(n%i==0){
				n = n/i;
				tmp.num ++;
			}
			if(j==0){
				if(tmp.num!=1){
					printf("%ld^%ld", tmp.prime,tmp.num);
				}else{
					printf("%ld", tmp.prime);
				}
				j++;
			}else{
				if(tmp.num!=1){
					printf("*%ld^%ld", tmp.prime,tmp.num);
				}else{
					printf("*%ld", tmp.prime);
				}
			}
		}
	}
	return 0;
}
