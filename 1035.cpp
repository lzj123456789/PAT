#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	unordered_map<string,string> data;
	std::vector<string> v;
	string team,password;
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		cin>>team>>password;
		int change = 0;
		for(auto &w:password){
			if(w=='1'){
				w = '@';
				change = 1;
			}else if(w=='0'){
				w = '%';
				change = 1;
			}else if(w=='l'){
				w = 'L';
				change = 1;
			}else if(w=='O'){
				w = 'o';
				change = 1;
			}
		}
		v.push_back(team);
		if(change) 	data[team] = password;

	}

	if(data.size()==0){
		if(n==1){
			printf("There is 1 account and no account is modified\n");
		}
		else printf("There is %d accounts and no account is modified\n", n);
	}else{
		printf("%d\n", data.size());
		for(auto w:v){
			if(data.count(w)!=0)
				cout<<w<<" "<<data[w]<<endl;
		}
	}

	return 0;
}
