#include <bits/stdc++.h>
using namespace std;
int k;
int main(int argc, char const *argv[])
{
	scanf("%d",&k);
	string input;
	unordered_map<char,int> repeated;
	string res="";
	unordered_set<char> setV;
	cin>>input;
	for(int i=0;i<input.size();){
		int count=0;
		int j=i;
		while(input[i]==input[j]){
			count++;
			j++;
			if(j==input.size()) break;
		}
		if(repeated.count(input[i])==0){
			repeated[input[i]] = count;
			
		}else{
			if(count>=3&&repeated[input[i]]%3==0) {
				repeated[input[i]] += count;
			}
		}
		i=j;
	}
	
	for(int i=0;i<input.size();){
		int count=0;
		int j=i;
		while(input[i]==input[j]){
			if(repeated[input[i]]<3) res += input[j];
			else{
				if(setV.find(input[j])==setV.end()){
					cout<<input[j];
					setV.insert(input[j]);
				}
				if((j-i)%3==0){
					res += input[j];
				}
			}
			count++;
			j++;
			if(j==input.size()) break;
		}

		i=j;
	}
	printf("\n");
	cout<<res<<endl;

	return 0;
}
