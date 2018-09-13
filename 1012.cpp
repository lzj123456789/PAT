#include <bits/stdc++.h>
using namespace std;
struct NODE{
	string id;
	int grade[4];
};
int current = 0;
bool cmp(const NODE &a,const NODE &b){
	return a.grade[current]>b.grade[current];
}
string res[4] = {"A","C","M","E"};
int main(int argc, char const *argv[])
{
	int n,M;
	scanf("%d %d",&n,&M);
	string id;
	int c,m,e,a;
	std::vector<NODE> v;
	for(int i=0;i<n;i++){
		cin>>id>>c>>m>>e;
		a = round((c+m+e)/3.0);
		NODE node{id,{a,c,m,e}};
		v.push_back(node);
	}
	unordered_map<string,std::vector<int> > rankStu;
	for(current=0;current<4;current++){
		sort(v.begin(),v.end(),cmp);
		rankStu[v[0].id].push_back(1);
		for(int j=1;j<v.size();j++){
			if(v[j].grade[current]==v[j-1].grade[current]){
				rankStu[v[j].id].push_back(rankStu[v[j-1].id][current]);
			}else {
				rankStu[v[j].id].push_back(j+1);
			}
		}
	}
	for(int i=0;i<M;i++){
		cin>>id;
		if(rankStu.count(id)==0){
			printf("N/A\n");
			continue;
		}
		std::vector<int> tmp = rankStu[id];
		int j=0;
		int findMin=1e9,minIndex=0;
		for(auto w:tmp){
			if(w<findMin){
				findMin = w;
				minIndex = j;
			}
			j++;
		}
		cout<<findMin<<" "<<res[minIndex]<<endl;
	}
	return 0;
}
