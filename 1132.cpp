#include <bits/stdc++.h>

using namespace std;

int n;

bool judge(string test){
	string a,b;
	int lenSize = test.size();
	a="";
	b="";
	for(int i=0;i<lenSize/2;i++){
		a += test[i];
		b += test[i+lenSize/2];
	}
	int num = stoi(test);
	int numa = stoi(a);
	int numb = stoi(b);
	if(numa*numb!=0){
		if(num%(numb*numa)==0){
			return true;
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void init(){
	scanf("%d",&n);
	string test;
	for(int i=0;i<n;i++){
		cin>>test;
		if(judge(test)) printf("Yes\n");
		else printf("No\n");
	}
}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}
