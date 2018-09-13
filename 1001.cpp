#include <bits/stdc++.h>
using namespace std;
string add(string a,string b){
	int len = max(a.size(),b.size());
	if(a.size()<len){
		for(int i=0;i<(len-a.size());i++){
			a +="0";
		}
	}else if(b.size()<len){
		for(int i=0;i<(len-b.size())+1;i++){
			b +="0";
		}
	}
//	cout<<a<<b<<endl;
	int ci=0;
	string res="";
	for(int i=0;i<len;i++){
		int sum =(a[i]-'0')+(b[i]-'0')+ci;
		res += to_string(sum%10);
		ci = sum/10;
	}
	if(ci) res += to_string(ci);
	reverse(res.begin(),res.end());
	return res;
}
string sub(string a,string b){
	
}
int main(int argc, char const *argv[])
{
	string a,b,res;
	cin>>a>>b;
	res = "";
	if(a[0]=='-'){
		if(b[0]=='-'){
			a = a.substr(1);
			b = b.substr(1);
			reverse(a.begin(),a.end());
			reverse(b.begin(),b.end());
			
			cout<<"-"+add(a,b)<<endl;
		}else {
			a = a.substr(1);
			if(a.size()>b.size()){
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<"-"+ sub(a,b)<<endl;
			}else if(a.size()<b.size()){
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<sub(b,a)<<endl;
			}else if(a>b){
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<"-"+sub(a,b)<<endl;
			}else{
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<sub(b,a)<<endl;
			}
		}
	}else{
		if(b[0]=='-'){
			b = b.substr(1);
			if(b.size()>a.size()){
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<"-"+sub(b,a)<<endl;
			}else if(b.size()<a.size()){
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<sub(a,b)<<endl;
			}else if(b>a){
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<"-"+sub(b,a)<<endl;
			}else{
				reverse(a.begin(),a.end());
				reverse(b.begin(),b.end());
				cout<<sub(a,b)<<endl;
			}
		}
		else{
			reverse(a.begin(),a.end());
			reverse(b.begin(),b.end());
			cout<<add(a,b)<<endl;
		}
	}
	return 0;
}
