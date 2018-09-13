#include <bits/stdc++.h>
using namespace std;
string add(string a,string b){
	int sum=0,cin=0;
	string res="";
	for(int i=0;i<a.size();i++){
		sum = (a[i]-'0')+(b[i]-'0')+cin;
		res += to_string(sum%10);
		cin = sum/10;
	}
	if(cin) res+= to_string(cin);
	reverse(res.begin(),res.end());
	return res;
}
int main(int argc, char const *argv[])
{
	string data;
	int k;
	cin>>data>>k;
	string tmp,tmpdata;
	for(int i=1;i<=k;i++){
		tmpdata = data;
		reverse(data.begin(),data.end());
		if(tmpdata == data){
			printf("%s\n%d",data.c_str(),i-1 );
			return 0;
		}
		tmp = add(data,tmpdata);
		data = tmp;
	}
	printf("%s\n%d",data.c_str(),k );
	return 0;
}