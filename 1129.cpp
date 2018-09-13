#include <bits/stdc++.h>
using namespace std;
int n,k;
struct NODE{
	int index;
	int weight;
	bool operator < (const NODE &a) const{
		return a.weight!=weight ? (weight > a.weight):(index <a.index);
	}
}; 
int main(int argc, char const *argv[])
{
	scanf("%d %d",&n,&k);
	unordered_map<int ,int> weightMap;
	for(int i=0;i<n;i++){
		weightMap[i] = 0;
	}
	int query;
	scanf("%d",&query);
	weightMap[query] ++;
	set<NODE> rec;
	rec.insert(NODE{query,weightMap[query]});

	for(int i=1;i<n;i++){
		scanf("%d",&query);
		printf("%d:", query);
		int j=0;
		for(auto i:rec){
			if(j>=k) break;
			printf(" %d",i.index );
			j++;
		}
		printf("\n");
		auto findNode = rec.find(NODE{query,weightMap[query]});
		if(findNode!=rec.end()){
			rec.erase(findNode);
		}
		weightMap[query]++;
		rec.insert(NODE{query,weightMap[query]});
	} 

	return 0;
}
