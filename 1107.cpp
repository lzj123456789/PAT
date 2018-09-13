#include <bits/stdc++.h>
using namespace std;
std::vector<int> fa(1010);
/*int findFather(int a){
	int x = a;
	while(a!=fa[a]){
		a = fa[a];
	}
	while(x!=fa[x]){
		int z = x;
		x = fa[x];
		fa[z] = a;
	}
}*/
bool cmp(int a,int b){
	return a>b;
}
int findFather(int a){
	return (a==fa[a])?(a):(fa[a] = findFather(fa[a]));
}
void Union(int a,int b){
	int faa = findFather(a);
	int fab = findFather(b);
	if(faa!=fab){
		fa[fab] = faa;
	}
}
int main(int argc, char const *argv[])
{
	int n,k,h1,h2;
	scanf("%d",&n);
	for(int i=0;i<=n;i++){
		fa[i] = i;
	}
	set<int> totalH;
	std::vector<int> v,res1(1010,0),res;
	for(int i=1;i<=n;i++){
		scanf("%d: %d",&k,&h1);
		totalH.insert(h1);
		v.push_back(h1);
		for(int j=0;j<k-1;j++){
			scanf("%d",&h2);
			Union(h1,h2);
			totalH.insert(h2);
		}
	}
	for(auto w:v){
		int tmp =findFather(w);
		res1[tmp]++;
	}
	for(auto w:res1){
		if(w!=0) res.push_back(w);
	}
	sort(res.begin(),res.end(),cmp);
	cout<<res.size()<<endl;
	int i=0;
	for(auto w:res){
		if(i==0) cout<<w;
		else cout<<" "<<w;
		i++;
	}
	return 0;
}
