#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int m,n;
	scanf("%d %d",&m,&n);
	unordered_map<string,int> graph;
	string data;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>data;
			if(graph.count(data)==0) graph[data] = 1;
			else graph[data] ++;
		}
	}
	string domin;
	int maxNum = -1;
	for(auto w:graph){
		if(w.second>maxNum){
			maxNum = w.second;
			domin = w.first;
		}
	}
	cout<<domin<<endl;
	return 0;
}