#include <bits/stdc++.h>
using namespace std;
string shi[4] = {"","Qian","Bai","Shi"};
string wan[2] = {"Yi","Wan"};
string num[10] = {"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
void beString(int n){
	string data = to_string(n);
	std::vector<string> res;
	int left=0;
	int right = (data.size())%4;
	int wanNum = (data.size())/4;
	int i;
	while(right<=data.size()){
		i=left;
		while((data[i]-'0')==0){
			i++;
		}
		if(i!=left) res.push_back(num[9]);
		for(;i<right;i++){
			cout<<i<<endl;
			int tmp = data[i]-'0';
			if((data[i]-'0')==0){
				continue;
			}else{
				cout<<num[tmp]<<" "<<shi[tmp%4]<<endl; 
				res.push_back(num[tmp]);
				res.push_back(shi[tmp%4]);
			}
		}
		left = i+1;
		right = right+4;
	}
	for(auto w:res){
		cout<<w<<endl;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	if(n<0){
		printf("Fu");
		beString(-n);
	}
	return 0;
}
