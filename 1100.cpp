#include <bits/stdc++.h>
using namespace std;
unordered_map<string,string> earthTomars;
unordered_map<string,string> marsToearch;
string low[13] = {"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string high[13] = {"","tam", "hel", "maa", "huh", "tou","kes", "hei", "elo", "syy", "lok", "mer", "jou"}; 
void init(){
	for(int i=0;i<169;i++){
		std::vector<int> v;
		int tmp=i;
		while(tmp){
			v.push_back(tmp%13);
			tmp = tmp/13;
		}
		if(i==0)v.push_back(i);
		reverse(v.begin(),v.end());
		if(v.size()==2){
			string tmp = high[v[0]]+" "+low[v[1]];
			if(v[1]==0)  tmp = high[v[0]];
			earthTomars[to_string(i)] = tmp;
			marsToearch[tmp] = to_string(i);
		}else if(v.size()==1){
			earthTomars[to_string(i)] = low[v[0]];
			marsToearch[low[v[0]]] = to_string(i);
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	string data;
	scanf("%d",&n);
	getchar();
	init(); 
	for(int i=0;i<n;i++){
		getline(cin,data);
		if(marsToearch.count(data)){
			cout<<marsToearch[data]<<endl;
		}else if(earthTomars.count(data)){
			cout<<earthTomars[data]<<endl;
		}
	}
	return 0;
}
