#include <bits/stdc++.h>
using namespace std;
//直接字符串比较更加简单
struct NODE{
	string name;
	int inH,inM,inS,outH,outM,outS;
};
bool cmp1(const NODE a,const NODE b){
	if(a.inH<b.inH) return true;
	else if(a.inH>b.inH) return false;
	else{
		if(a.inM<b.inM) return true;
		else if(a.inM>b.inM) return false;
		else{
			if(a.inS<b.inS) return true;
			else if(a.inS>b.inS) return false;
		}
	} 
}
bool cmp2(const NODE a,NODE b){
	return (a.outH==b.outH)?((a.outM==b.outM)?(a.outS>b.outS):(a.outM>b.outM)):(a.outH>b.outH);
}
int main(int argc, char const *argv[])
{
	int n;
	string name;
	int inH,inM,inS,outH,outM,outS;
	scanf("%d",&n);
	std::vector<NODE> v;
	for(int i=0;i<n;i++){
		cin>>name;
		scanf("%d:%d:%d %d:%d:%d",&inH,&inM,&inS,&outH,&outM,&outS);
		NODE node{name,inH,inM,inS,outH,outM,outS};
		v.push_back(node);
	}
	sort(v.begin(),v.end(),cmp1);
	cout<<v[0].name<<" ";
	sort(v.begin(), v.end(),cmp2);
	cout<<v[0].name<<endl;	
	return 0;
}