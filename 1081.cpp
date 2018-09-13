#include <bits/stdc++.h>
using namespace std;
struct NODE{
	long int up;
	long int down;
};
long int gcd(long int a,long int b){
	return !b?a:(gcd(b,a%b));
}
NODE reduction(NODE a){
	if(a.down<0){
		a.up = -a.up;a.down = -a.down;
	}
	if(a.up == 0){
		a.down = 1;
	}else {
		long int g = gcd(abs(a.up),abs(a.down));
		a.up = a.up/g;
		a.down = a.down/g;
	}
	return a;
}
NODE add(NODE a, NODE b){
	NODE res;
	res.up = a.up*b.down+a.down*b.up;
	res.down = a.down*b.down;
	return res;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	NODE res,tmp;
	for(int i=0;i<n;i++){
		scanf("%ld/%ld",&tmp.up,&tmp.down);
		if(i==0){
			res.up = tmp.up;res.down = tmp.down;
			res = reduction(res);
		}else{
			res = add(res,tmp);
			res = reduction(res);
		}
	}
	long int integer = res.up/res.down;
	long int numerator = res.up%res.down;
	if(integer==0&&numerator!=0){
		printf("%ld/%ld\n",res.up,res.down );
	}else if(numerator==0){
		printf("%ld\n", integer);
	}else {
		printf("%ld %ld/%ld\n",integer,res.up%res.down,res.down );
	}

	return 0;
}

