#include <bits/stdc++.h>
using namespace std;
struct NODE{
	int n;
	float a;
};
bool cmp(const NODE a,const NODE b){
	return a.n>b.n;
}
int main(int argc, char const *argv[])
{
	int k,n;
	float a;
	scanf("%d",&k);
	unordered_map<int ,float> m;
	for(int i=0;i<k;i++){
		scanf("%d %f",&n,&a);
		m[n]=a;
	}
	scanf("%d",&k);
	unordered_map<int,float> res;
	for(int i=0;i<k;i++){
		scanf("%d %f",&n,&a);
		for(auto w:m){
			int tmpn = w.first+n;
			float tmpa = w.second*a;
			if(res.count(tmpn)!=0){
				res[tmpn] += tmpa;
			}else{
				res[tmpn] = tmpa;
			}
		}
	}
	std::vector<NODE> v;
	for(auto w:res){
		if(w.second!=0){
			NODE node{w.first,w.second};
			v.push_back(node);
		}
	}
	sort(v.begin(),v.end(),cmp);
	printf("%d", (int)v.size());
	for(auto w:v){
		printf(" %d %.1f",w.n,w.a );
	}
	return 0;
}