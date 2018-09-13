#include <bits/stdc++.h>
using namespace std; 
int n;
bool isPrime(int num){
	if(num==2) return true;
	for(int i=2;i<num/2;i++){
		if(num%i==0){
			return false;
		}
	}
	return true;
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	string id;
	unordered_map<string,string> award;
	unordered_map<string,bool> isVisited;
	for(int i=1;i<=n;i++){
		cin>>id;
		isVisited[id] = false;
		if(i==1) {
			award[id] = "Mystery Award";
		}else if(isPrime(i)){
			award[id] = "Minion";
		}else{
			award[id] = "Chocolate";
		}
	}
	int k;
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		cin>>id;
		if(award.count(id)!=0){
			if(isVisited[id]==false){
				cout<<id+": "<<award[id]<<endl;
				isVisited[id] = true;
			}else{
				cout<<id+": Checked"<<endl;
			}
		}else{
			cout<<id+": Are you kidding?"<<endl;
		}
	}
	return 0;
}
