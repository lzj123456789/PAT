#include <bits/stdc++.h>
using namespace std;

string N;

string invertN(string str){
	int lenStr = str.size();
	string inv="";
	for(int i=0;i<lenStr;i++){
		inv += str[lenStr-i-1];
	}
	return inv;
}

string addNum(string a,string b){
	string result="";
	int lenStr = a.size();
	int sum;
	int ci=0;
	for(int i=lenStr-1;i>=0;i--){
		sum = (a[i]-'0')+(b[i]-'0')+ci;
		result += to_string(sum%10);
		ci = sum/10;
	}
	if(ci){
		result +=  to_string(ci);
	}
	result = invertN(result);
	return result;
}

bool judge(string str)
{
	int lenStr = str.size();
	for(int i=0;i<lenStr/2;i++){
		if(str[i]!=str[lenStr-1-i]){
			return false;
		}
	}
	return true;
}

void init(){
	cin>>N;
	for(int i=0;i<10;i++){

		if(judge(N)){
			cout << N<<" is a palindromic number."<<endl;
			return;
		}
		string inv = N;
		inv = invertN(inv);
		string res =  addNum(N,inv);
		cout<<N<<" + "<<inv<<" = "<<res<<endl;
		if(judge(res)){
			cout << res<<" is a palindromic number."<<endl;
			return;
		}
		N = res;
	}
	cout<<"Not found in 10 iterations."<<endl;

}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}
