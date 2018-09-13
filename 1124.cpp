#include <bits/stdc++.h>
using namespace std;
int m,n,s;
int main(int argc, char const *argv[])
{
	scanf("%d %d %d",&m,&n,&s);
	unordered_map<int,string> nick;
	string name;
	for(int i=1;i<m+1;i++){
		cin>>name;
		nick[i] = name;
	}

	if(s>m){
		printf("Keep going...\n");
	}
	std::vector<string> res;
	for(int i=s;i<m+1;){
		auto findi = find(res.begin(),res.end(),nick[i]);
		if(findi!=res.end()){
			i = i+1;
			if(i>=m+1) break;
			res.push_back(nick[i]);
			cout<<nick[i]<<endl;
			i = i+n;
		}else{
			res.push_back(nick[i]);
			cout<<nick[i]<<endl;
		//	printf("%d\n", i);
			i = i+n;
		}

	}
	return 0;
}