#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	std::vector<string> v;
	string data;
	int length=1e9;
	scanf("%d",&n);
	getchar();
	int i=0;
	for(i=0;i<n;i++){
		getline(cin,data);
		if(data.size()<length){
			length = data.size();
		}
		reverse(data.begin(),data.end());
		v.push_back(data);
	}
	int flag = 1;
	
	for(i=0;i<length;i++){
		for(int j=0;j<n;j++){
			if(v[0][i]==v[j][i]){

			}else{
				flag = 0;
				break;
			}
		}
		if(flag==0){
			break;
		}
	}
	if(i==0) printf("nai\n");
	else {
		string res = data.substr(0,i);
		reverse(res.begin(),res.end()) ;
		cout<<res<<endl;
	}
	
}
