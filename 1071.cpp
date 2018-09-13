#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string data;
	getline(cin,data);
	data += ".";
	unordered_map<string,int> graph;
	int begin=0,end=0;
	for(int i=0;i<data.size();){
		char w = data[i];
		if((w>='0'&&w<='9')||(w>='A'&&w<='Z')||(w>='a'&&w<='z')){
			if(w>='A'&&w<='Z'){
				data[i] = tolower(data[i]);
			}
			i++;
		}else {
			end = i;
			string tmp = data.substr(begin,end-begin);
			if(graph.count(tmp)==0){
				graph[tmp] =1;
			}else graph[tmp]++;
			//cout<<tmp<<" "<<tmp.size()<<endl;
			while(1){
				i++;
				w = data[i];
				if(((w>='0'&&w<='9')||(w>='A'&&w<='Z')||(w>='a'&&w<='z'))||i>=data.size())
					break;	
			}
			begin = i;
		}
	}
	int maxFlag=-1;
	set<string> res;
	for(auto w:graph){
		if(w.second>maxFlag){
			maxFlag = w.second;
			res.clear();
			res.insert(w.first);
		}else if(w.second == maxFlag){
			res.insert(w.first);
		}
	}
	int i=0;
	for(auto w:res){
		if(i==0) {
			cout<<w<<" "<<graph[w]<<endl;
			break;
		}
	}
	

	return 0;
}
