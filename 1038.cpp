#include <bits/stdc++.h>
using namespace std;
bool cmp(string a,string b){
	return a+b<b+a;
}
int main(int argc, char const *argv[])
{
	int n;
	string data;
	scanf("%d",&n);
	std::vector<string> v;
	for(int i=0;i<n;i++){
		cin>>data;
		v.push_back(data);
	}
	sort(v.begin(),v.end(),cmp);
	string res ="";
	for(auto w:v){
		res+=w;
	}
	int i=0;
	for(auto &w:res){
		if(w-'0'!=0){
			break;
		}
		i++;
	}
	res = res.substr(i,res.size()-i);
	if(res.size()!=0) cout<<res;
	else cout<<"0"
	return 0;
}
