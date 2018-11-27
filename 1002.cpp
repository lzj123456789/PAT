#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int k,n;
	float a;
	scanf("%d",&k);
	map<int ,float> m;
	for(int i=0;i<k;i++){
		scanf("%d %f",&n,&a);
		m[n] = a;
	}
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d %f",&n,&a);
		if(m.count(n)!=0){
			m[n] += a;
		}else{
			m[n] = a;
		}
	}
	for(auto w:m){
		if(w.second==0){
			m.erase(w.first);
		}
	}
	printf("%d", m.size());
	for(auto w=m.rbegin();w!=m.rend();w++){
		printf(" %d %.1f",w->first,w->second);
	}
	return 0;
}