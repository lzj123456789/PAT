#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d %d",&n,&k);
	unordered_map<string,set<int> > graph;
	int index,ni;
	string name;
	for(int i=0;i<k;i++){
		scanf("%d %d",&index,&ni);
		for(int j=0;j<ni;j++){
			cin>>name;
			graph[name].insert(index);
		}
	}
	for(int i=0;i<n;i++){
		cin>>name;
		cout<<name<<" "<<graph[name].size();
		for(auto w:graph[name]){
			cout<<" "<<w;
		}
		cout<<endl;
	}
	return 0;
}
