#include <bits/stdc++.h>
using namespace std;
int n;
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	int couple1,couple2;
	unordered_map<int,int> couple;
	unordered_map<int,bool> graph;
	for (int i = 0; i < n; ++i)
	{
		cin>>couple1>>couple2;
		couple[couple1] = couple2;
		couple[couple2] = couple1;
	}
	int m,guests;
	scanf("%d",&m);
	std::vector<int> v,res;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d",&guests);
		v.push_back(guests);
	}

	for(auto w:v){
		if(couple.count(w)==0) res.push_back(w);
		else if(find(v.begin(),v.end(),couple[w])==v.end()) res.push_back(w);
	}

	sort(res.begin(),res.end());
	unsigned int i=1;
	printf("%d\n", res.size());
	for(auto w:res){
		if(i==1) printf("%d",w);
		else printf(" %d",w);
		i++;
	}
	return 0;
}
