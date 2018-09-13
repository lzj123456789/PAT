#include <bits/stdc++.h>
using namespace std;
struct NODE{
	char name[11];
	char id[11];
	int grade;
};
bool cmp(const NODE &a,const NODE &b){
	return a.grade>b.grade;
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	std::vector<NODE> v(n);
	for(int i=0;i<n;i++){
		scanf("%s %s %d",v[i].name,v[i].id,&v[i].grade);
	}
	sort(v.begin(),v.end(),cmp);
	int amin,amax;
	scanf("%d %d",&amin,&amax);
	std::vector<NODE> res;
	for(auto w:v){
		if(w.grade>=amin&&w.grade<=amax) res.push_back(w);
	}
	if(res.size()==0){
		printf("NONE\n");
	}else {
		for(auto w:res){
			printf("%s %s\n",w.name,w.id );
		}
	}
	return 0;
}
