#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string s1,s2;
	getline(cin,s1);
	unordered_map<char,bool> table;
	getline(cin,s2);
	for(auto w:s2){
		table[w] = true;
	}
	for(auto w:s1){
		if(table.count(w)==0)
		printf("%c", w);
	}
	return 0;
}
