#include <bits/stdc++.h>
using namespace std;
bool cmp(int a,int b){
	return (a>0)?(a>b):(a<b);
}
int main(int argc, char const *argv[])
{
	int nc,np;
	scanf("%d",&nc);
	std::vector<int> ncv[2],ncp[2];
	int data;
	for (int i = 0; i < nc; ++i)
	{
		scanf("%d",&data);
		if(data>0) ncv[0].push_back(data);
		else  ncv[1].push_back(data);
	}
	for(int i=0;i<2;i++){
		sort(ncv[i].begin(),ncv[i].end(),cmp);
	}
	scanf("%d",&np);
	for (int i = 0; i < np; ++i)
	{
		scanf("%d",&data);
		if(data>0) ncp[0].push_back(data);
		else  ncp[1].push_back(data);
	}
	for(int i=0;i<2;i++){
		sort(ncp[i].begin(),ncp[i].end(),cmp);
	}
	int sum=0;
	for(int i=0;i<2;i++){
		int min1 = min(ncp[i].size(),ncv[i].size());
		for(int j=0;j<min1;j++){
		//	cout<<ncv[i][j]<<" "<<ncp[i][j]<<endl;
			sum+=ncv[i][j]*ncp[i][j];
		}
	}
	printf("%d\n",sum);
	return 0;
}
