#include <bits/stdc++.h>
using namespace std;
struct NODE{
	int id;
	int p[6];
	int num;
	int total;
};
bool cmp(const NODE &a,const NODE &b){
	return (a.total==b.total)?((a.num==b.num)?(a.id<b.id):(a.num>b.num)):(a.total>b.total);
}
int main(int argc, char const *argv[])
{
	int n,k,m;
	int fullp[6];
	scanf("%d %d %d",&n,&k,&m);
	for(int i=1;i<=k;i++){
		scanf("%d",&fullp[i]);
	}
	int id,score,p;
	std::vector<NODE> v(n+1);
	for(int i=1;i<=n;i++){
		v[i].num = 0;
		v[i].id = i;
		v[i].total= 0;
		fill(v[i].p,v[i].p+6,-2);
	}
	for(int i=0;i<m;i++){
		scanf("%d %d %d",&id,&p,&score);
		if(v[id].p[p] < score) v[id].p[p] = score;
		if(score==fullp[p]) v[id].num ++;
	}
	std::vector<NODE> res;
	int flag = 0;
	for(int i=1;i<=n;i++){
		flag = 0;
		for(int j=1;j<=k;j++){
			if(v[i].p[j]>=0) flag=1;
			if(v[i].p[j]>0) v[i].total += v[i].p[j];
		}
		if(flag){
			res.push_back(v[i]);
		}
	}
	sort(res.begin(),res.end(),cmp);
	int r=1;
	printf("%d %05d %d", r,res[0].id,res[0].total);
	for(int j=1;j<=k;j++){
		int data = res[0].p[j];
		if(data>=0) printf(" %d",data );
		else if(data==-1) printf(" 0");
		else if(data==-2) printf(" -");
	}
	printf("\n");
	for(int i=1;i<res.size();i++){
		if(res[i].total==res[i-1].total){

		}else{
			r = i+1;
		}
		printf("%d %05d %d", r,res[i].id,res[i].total);
		for(int j=1;j<=k;j++){
			int data = res[i].p[j];
			if(data>=0) printf(" %d",data );
			else if(data==-1) printf(" 0");
			else if(data==-2) printf(" -");
		}
		printf("\n");
	}
	return 0;
}
