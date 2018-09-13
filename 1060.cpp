#include <bits/stdc++.h>
using namespace std;
int finds(string s){
	int i=0;
	for(auto &w:s){
		if(w!='0'&&w!='.'){
			return i;
		}
		i++;
	}
	return i-1;
}
int n;
string judge(string a){
	string resa;
	auto pointa = a.find(".");
	int finda = finds(a);
	//cout<<finda<<" "<<findb<<endl;
	if(pointa!=string::npos){
		int pointab = a.find(".");
		if(pointa<finda){
			string asubstr = a.substr(finda,n);
			resa = "0."+asubstr;
		//	cout<<resa<<endl; 
			int i=1;
			string zeros="";
			while(i<=n- asubstr.size()){
				zeros+="0";
				i++;
			}
			if(finda+1==a.size()&&a[a.size()-1]=='0') resa += zeros + "*10^"+to_string(0);
			else resa += zeros + "*10^-"+to_string(finda-pointab-1); 
		}else{
			string asubstr = a.substr(finda,n+1);
			//cout<<asubstr<<endl;
			if(asubstr.find(".")!=string::npos){
				asubstr = asubstr.erase(asubstr.find("."),1);
			}else{
				asubstr = asubstr.substr(0,n);
			}
			//	cout<<asubstr<<endl;
			resa = "0."+asubstr;
			int i=1;
			string zeros="";
			while(i<=n- asubstr.size()){
				zeros+="0";
				i++;
			}
			resa += zeros + "*10^"+to_string(-finda+pointab);
		}
	}else {
		string asubstr = a.substr(finda,n);
		resa = "0."+asubstr;
		//cout<<resa<<endl; 
		int i=1;
		string zeros="";
		while(i<=n- asubstr.size()){
			zeros+="0";
			i++;
		}
		if(finda+1==a.size()&&a[a.size()-1]=='0') resa += zeros + "*10^"+to_string(0); 
		else resa += zeros + "*10^"+to_string(a.size()-finda);
	}
	return resa;
}
int main(int argc, char const *argv[])
{
	
	string a,b;
	scanf("%d",&n);
	cin>>a>>b;
	string resa = judge(a);
	string resb = judge(b);
	if(resa==resb){
		cout<<"YES"<<" "<<resa <<endl;
	}	else{
		cout<<"NO"<<" "<<resa<<" "<<resb<<endl;
	}
	
	return 0;
}
