#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector> 

using namespace std;
int N;

bool judge(int a, int b){
	return a<=b;
}

void init()
{
	scanf("%d",&N);
	int i=0;
	unsigned int m;
	int data; 
	vector<int> v;
	for(i=0;i<N;i++){
		scanf("%d",&data);
		v.push_back(data);
	}
	sort(v.begin(),v.end(),judge);

	int minInteger=1;

	for(m=0;m<v.size();m++){
		if(v[m]>=minInteger){
			minInteger = v[m];
			if((m+1)<v.size()){
				if((v[m+1]==(v[m]+1))||(v[m+1]==v[m])){
					continue;
				}else{
					minInteger = v[m]+1;
					break;
				}
			}else{
				
				minInteger = v[m]+1;
			}
		}
	}
	
	printf("%d\n", minInteger);
}


int main(int argc, char const *argv[])
{
	init();
	return 0;
}
