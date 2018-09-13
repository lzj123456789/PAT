#include <bits/stdc++.h>
using namespace std;

const int maxLen = 1e4;

int M,N,K;

void init(){
	scanf("%d %d",&N,&M);
	
	unordered_map<int ,bool> graph;

	std::vector<int> graphV[maxLen];
	int v1,v2;

	for (int i = 0; i < M; ++i)
	{
		scanf("%d %d",&v1,&v2);
		graphV[v1].push_back(v2);
		graphV[v2].push_back(v1);
		graph[N*v1+v2] = true;
		graph[N*v2+v1] = true;
	}
	int count=0;
	int K1;
	scanf("%d",&K1);



	for (int i = 0; i < K1; ++i)
	{
		scanf("%d",&K);
		int v;
		count=0;
		unordered_map<int ,bool> graphTmp = graph;
		for (int j = 0; j < K; ++j)
		{
			scanf("%d",&v);
			for(auto w:graphV[v]){
				//printf("%d\n",w);
				if(graphTmp.count(v*N+w)){
					//delete
					if(graphTmp[v*N+w]){
					//	printf("%d %d\n", v,w);
						graphTmp[v*N+w] = false;
						graphTmp[w*N+v] = false;
						count++;
					}
				}
			}
		}
	//	printf("%d\n", count);
		if(count == M){
			printf("Yes\n");
		}else{
			printf("No\n");
		}
	}



}


int main(int argc, char const *argv[])
{
	init();
	return 0;
}
