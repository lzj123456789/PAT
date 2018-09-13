#include <bits/stdc++.h>
using namespace std;
int n;
unordered_map<string,std::vector<string> > graph;
unordered_map<string,string> parents;
int flag=0;
void inOrder(string node){
	if(node=="-") return;
	inOrder(graph[node][1]);
	if(flag==0){
		cout<<node;
		flag++;
	}else{
		cout<<" "<<node;
	}
	inOrder(graph[node][0]);
}
void levelOrder(string root ){
	queue<string> q;
	q.push(root);
	int i=0;
	while(!q.empty()){
		string tmp = q.front();
		q.pop();
		if(i==0){
			cout<<tmp;
			i++;
		}else cout<<" "<<tmp;
		if(graph[tmp][1]!="-") q.push(graph[tmp][1]);
		if(graph[tmp][0]!="-") q.push(graph[tmp][0]);
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	string left,right,data;
	for(int i=0;i<n;i++){
		data = to_string(i);
		parents[data] = data;
	}
	for(int i=0;i<n;i++){
		cin>>left>>right;
		data = to_string(i);
		graph[data].push_back(left);
		graph[data].push_back(right);
		if(left!="-") parents[left] = data;
		if(right!="-") parents[right] = data;
	}
	data = "0";
	while(parents[data]!=data) data = parents[data];
	string root = data;
	levelOrder(root);
	cout<<endl;
	inOrder(root);
	return 0;
}