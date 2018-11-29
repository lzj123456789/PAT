#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	double w,t,l;
	double sum=1.0;
	std::vector<char> v;
	for(int i=0;i<3;i++){
		scanf("%lf %lf %lf",&w,&t,&l);
		if(w>t&&w>l){
			sum *= w;
			v.push_back('W');
		}else if(t>w&&t>l){
			sum *= t;
			v.push_back('T');
		}else if(l>t&&l>w){
			sum *= l;
			v.push_back('L');
		}
	}
	for(auto i:v){
		cout<<i<<" ";
	}
	//sum = (sum*0.65-1)*2;
	printf("%.2lf\n", (sum*0.65-1)*2);
	return 0;
}