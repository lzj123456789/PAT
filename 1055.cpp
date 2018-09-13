#include <bits/stdc++.h>
using namespace std;
struct NODE{
	char name[10];
	int age;
	int networth;
};
bool cmp(const NODE &a,  const NODE &b){
	return (a.networth==b.networth)?((a.age==b.age)?(strcmp(a.name,b.name)<0):(a.age<b.age)):(a.networth>b.networth);
}
int main(int argc, char const *argv[])
{
	int n,k;
	int num[100010];
	fill(num,num+100010,0);
	scanf("%d %d",&n,&k);
	std::vector<NODE> total1(n);
	for(int i=0;i<n;i++){
		scanf("%s %d %d",total1[i].name,&total1[i].age,&total1[i].networth);
	}
	sort(total1.begin(),total1.end(),cmp);
	std::vector<NODE> total;
	for(auto w:total1){
		if(num[w.age]==0){
			num[w.age] = 1;
			total.push_back(w);
		}else{
			if(num[w.age]<=100){
				total.push_back(w);
				num[w.age]++;
			}
		}
	}
	for(int i=1;i<=k;i++){
		int m,amin,amax;
		scanf("%d %d %d",&m,&amin,&amax);
		std::vector<NODE> tmp;
		for(auto w:total){
			if(w.age>=amin&&w.age<=amax){
				tmp.push_back(w);
			}
		}
		printf("Case #%d:\n", i);
		if(tmp.size()==0){
			printf("None\n");
		}else{
			//sort(tmp.begin(),tmp.end(),cmp);
			for(int j=0;j<((tmp.size()>m)?m:tmp.size());j++){
				printf("%s %d %d\n",tmp[j].name, tmp[j].age,tmp[j].networth);
			}
		}
	}
	return 0;
}
