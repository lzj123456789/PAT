#include <bits/stdc++.h>
using namespace std;
/*
 *int findFa(int x){return fa[x]==x ? x : fa[x] = findFa(fa[x]);}
 */
int n;
unordered_map<int,int> father;
int findFather(int a){
	return (father[a]==a)?(a):(father[a] = findFather(father[a]));
}
void unionNode(int a,int b){
	int aFa = findFather(a);
	int bFa = findFather(b);
	if(aFa!=bFa){
		father[bFa] = father[aFa]; 
	}
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		int k,bird,id;
		scanf("%d %d",&k,&id);
		if(father.count(id)==0) father[id] = id;
		for(int j=1;j<k;j++){
			scanf("%d",&bird);
			if(father.count(bird)==0) father[bird] = bird;
			unionNode(id,bird);
		}
	}
	set<int> fathers;
	for(auto w:father){
		findFather(w.first);
	}
	for(auto w:father){
		fathers.insert(w.second);
	}
	printf("%d %d\n",fathers.size(),father.size() );
	int q,b1,b2;
	scanf("%d",&q);
	for(int i=0;i<q;i++){
		scanf("%d %d",&b1,&b2);
		printf("%s\n",(findFather(b1)==findFather(b2))?("Yes"):("No") );
	}
	return 0;
}
