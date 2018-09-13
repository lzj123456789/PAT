#include <bits/stdc++.h>
using namespace std;
string add(string a){
	reverse(a.begin(),a.end());
	string res = "";
	int cin = 0,sum=0;
	for(auto w:a){
		sum = 2*(w-'0')+cin;
		res += to_string(sum%10);
		cin = sum/10;
	}
	if(cin) res += to_string(cin);
	reverse(res.begin(),res.end());
	return res;
}

int main(int argc, char const *argv[])
{
	string data;
	cin>>data;
	std::vector<int> times(10,0),times1(10,0);
	int index = 0;
	for(auto w:data){
		times[(w-'0')] ++;
	}
	data = add(data);
	for(auto w:data){
		times1[(w-'0')] ++;
	}
	if(times1==times){
		printf("Yes\n");
	}else printf("No\n");
	cout<<data;
	return 0;
}