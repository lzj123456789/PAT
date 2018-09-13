#include <cstdio>
#include <cstdlib>
#include <string>
#include <vector>
#include <iostream>
#include<algorithm>
#include <unordered_map>

using namespace std;

int N,M,K;
const int MaxLen = 1e4;

std::vector<int> v[MaxLen];
unordered_map<int ,bool> bg;

struct NODE{
	int a;
	int b;
	NODE(int a,int b):a(a),b(b){}
};

void findFirend(std::vector<NODE> &res,int a,int b){
	for(auto m:v[a]){
		for(auto n:v[b]){
			//cout<<"a "<<m<<" b "<<n<<endl;
			if(m==n||m==b||n==a) continue;
			if(bg[m*10000+n]) {
				res.push_back(NODE(m,n));
			}
		}
	}
}
/*
bool cmp(const friends &a,const friends &b)
{
    return a.x==b.x?a.y<b.y:a.x<b.x;
}*/

bool cmp(const NODE &a,const NODE &b){

	return a.a==b.a? ( a.b<b.b ):(a.a<b.a);


}

void init(){

	scanf("%d %d",&N,&M);
	string p1,p2;
	for(int i=0;i<M;i++){
		cin>>p1>>p2;
		if(p1.size()==p2.size()){
			//same gender
			v[ abs(stoi(p1)) ].push_back(abs(stoi(p2)));
			v[ abs(stoi(p2)) ].push_back(abs(stoi(p1)));
		}//else{
			bg[abs(stoi(p1))*10000+ abs(stoi(p2))] = bg[abs(stoi(p2))*10000 +abs(stoi(p1))] = true;
		//}	
	}
	cin>>K;
	int a1,a2;
	for(int i=0;i<K;i++){
		cin>>a1>>a2;
		std::vector<NODE> res;
		findFirend(res,abs(a1),abs(a2));
		sort(res.begin(),res.end(),cmp);
		printf("%d\n", res.size());
		for(auto w:res){
			printf("%d %d\n",w.a,w.b );
		}
	}

}
int main(int argc, char const *argv[])
{
	init();
	return 0;
}
