#include <bits/stdc++.h>
using namespace std;
struct NODE{
	string father;
	double estate;
	double area;
};
unordered_map<string,NODE> father;
string findFather(string a){
	return (a==father[a].father)?(a):(father[a].father=findFather(father[a].father));
}
void unionNode(string a,string b){
	string aFa = findFather(a);
	string bFa = findFather(b);
	if(aFa>bFa){
		father[aFa].father = bFa;
	}else if(aFa<bFa){
		father[bFa].father = aFa;
	}
}
bool cmp(const NODE &a,const NODE &b){
	return (a.area!=b.area)?(a.area>b.area):(a.father<b.father);
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	string id,p1,p2;
	int k;
	double estate,area;
	string child;
	for(int i=0;i<n;i++){
		cin>>id>>p1>>p2;
		NODE node{id,0,0};
		if(father.count(id)==0) father[id]=node;
		if(p1!="-1"&&father.count(p1)==0){
			NODE node1{p1,0,0};
			father[p1] = node1;
		}
		if(father.count(p1)!=0) unionNode(id,p1);
		if(p2!="-1"&&father.count(p2)==0){
			NODE node2{p2,0,0};
			father[p2] = node2;
			
		}
		if(father.count(p2)!=0) unionNode(id,p2);
		scanf("%d",&k);
		for(int j=0;j<k;j++){
			cin>>child;
			if(father.count(child)==0){
				NODE node3{child,0,0};
				father[child] = node3;
			}
			if(father.count(child)!=0) unionNode(id,child);
		}
		scanf("%lf %lf",&estate,&area);
		father[id].estate = estate;
		father[id].area = area;

	}
	unordered_map<string,std::vector<string> > familyMem;
	for(auto w:father){
		string a = findFather(w.first);
		familyMem[a].push_back(w.first);
	}
	printf("%d\n", familyMem.size());
	std::vector<NODE> v;
	int totalE,totalA;
	for(auto w:familyMem){
		totalE=totalA=0;
		for(auto x:w.second){
			totalE += father[x].estate;
			totalA += father[x].area;
		}
		father[w.first].estate = totalE/(1.0*w.second.size());
		father[w.first].area = totalA/(1.0*w.second.size());
		v.push_back(father[w.first]);
	}
	sort(v.begin(),v.end(),cmp);
	for(auto w:v){
		cout<<w.father<<" "<<familyMem[w.father].size();
		printf(" %.3f %.3f\n",w.estate,w.area );
	}
	return 0;
}
