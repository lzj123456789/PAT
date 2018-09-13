#include <bits/stdc++.h>
using namespace std;
unordered_map<string,std::vector<string> > tree;
unordered_map<string,string> findroot;
bool first=false,close = false;
string last;
bool bfs(string node){
	queue<string> q;
	q.push(node);
	while(!q.empty()){
		string current = q.front();
		//cout<<current<<endl;
		if(current!="-") last = current;
		q.pop();
		if(current!="-"){
			if(first) return false;
			q.push(tree[current][0]);
			q.push(tree[current][1]);
		}else if(!close){
			first=true;
			close = true;
		}	
	}
	return true;
}
int main(int argc, char const *argv[])
{
	int n;
	string root="0";
	scanf("%d",&n);
	string left,right,node;
	for(int i=0;i<n;i++){
		cin>>left>>right;
		node = to_string(i);
		tree[node].push_back(left);
		tree[node].push_back(right);
		findroot[left] = node;
		findroot[right] = node;
	}
	while(findroot.count(root)!=0){
		root = findroot[root];
	}
	bool isCB = bfs(root);
	if(isCB){
		printf("YES ");
		cout<<last;
	} else{
		printf("NO ");
		cout<<root;
	}
	return 0;
}
