#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	long int a,b;
	scanf("%ld %ld",&a,&b);
	string res = to_string(a+b);
	string tmp="";
	reverse(res.begin(),res.end());
	int i=0;
	while(i<res.size()){
		string substring = res.substr(i,3);
		if(substring.size()<3){
			tmp += substring;
		}else{
			tmp += substring;
			if(res[i+3]!='-'&&res[i+3]!='\0'){
				tmp +=",";
			}
		}
		i = i+3;
	}
	reverse(tmp.begin(),tmp.end());
	cout<<tmp<<endl;
	return 0;
}
