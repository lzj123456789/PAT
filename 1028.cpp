#include <bits/stdc++.h>
using namespace std;
struct NODE{
	string id;
	string name;
	int score;
};
int c;
bool cmp(const NODE &a,const NODE &b){
	if(c==1){
		return a.id<b.id;
	}else if(c==2){
		return (a.name==b.name)?(a.id<b.id):(a.name<b.name);
	}else if(c==3){
		return (a.score==b.score)?(a.id<b.id):(a.score<b.score);
	}
}
int main(int argc, char const *argv[])
{
	int n;
	string id;
	int score;
	string name;
	std::vector<NODE> v;
	scanf("%d %d",&n,&c);
	for(int i=0;i<n;i++){
		cin>>id>>name>>score;
		NODE node{id,name,score};
		v.push_back(node);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto w:v){
		printf("%s %s %d\n",w.id.c_str(),w.name.c_str(),w.score );
	}
	return 0;
}