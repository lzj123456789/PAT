#include <bits/stdc++.h>
using namespace std;
int n;
bool cmp(const int &a,const int &b){
	return a>b;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	std::vector<int> v,v1;
	int data;
	for(int i=0;i<n;i++){
		scanf("%d",&data);
		v.push_back(data);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto i=0;i<v.size();i++){
		printf("%d %d\n",i,v[i] );
		if(v[i]==i) 
			printf("%d\n",v[i]);
	}
	int i=0;
	while(i<n&&v[i]>i+1){
		i++;
		printf("%d %d\n",i ,v[i]);
	}
}
