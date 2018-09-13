#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n,id;
	scanf("%d",&n);
	getchar();
	string data;
	unordered_map<string,set<int> > graph[6];
	for(int i=0;i<n;i++){
		scanf("%d",&id);
		getchar();
		for(int j=1;j<=5;j++){
			getline(cin,data);
			if(j==3){
				data += ' '; 
				int begin = 0,end = 0;;
				for(int m=0;m<data.size();m++){
					if(data[m]==' '){
						end = m;
						string tmp = data.substr(begin,end-begin);
						//cout<<tmp<<" "<<tmp.size()<<endl;
						graph[j][tmp].insert(id);
						begin = m+1;
					}
				}
			}else{
				graph[j][data].insert(id);
			}
		}
	}
	int m;
	scanf("%d",&m);
	getchar();
	for(int i=0;i<m;i++){
		getline(cin,data);
		cout<<data<<endl;
		int index = stoi(data.substr(0,1));
	//	cout<<index<<endl;
		string tmp = data.substr(3,data.size()-3);
		if(graph[index].count(tmp))
			for(auto w:graph[index][tmp]){
				printf("%07d\n", w);
			} 
		else{
			printf("Not Found\n");
		}
	}
	return 0;
}

/*
3
1111111
The Testing Book
Yue Chen
test code debug sort keywords
ZUCS Print
2011
3333333
Another Testing Book
Yue Chen
test code sort keywords
ZUCS Print2
2012
2222222
The Testing Book
CYLL
keywords
ZUCS Print2
2011
6
1: The Testing Book
2: Yue Chen
3: keywords
4: ZUCS Print
5: 2011
3: blablabla
*/
