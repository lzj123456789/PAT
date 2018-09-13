#include <cstdio>
#include <cstdlib>
#include <vector>
#include <map>
#include <iostream>

using namespace std;


int M,N;

void init(){
	scanf("%d %d",&M,&N);
	int i;
	//Node BST=NULL;
	int data;

	std::vector<int> ve;

	for(i=0;i<N;i++){
		scanf("%d",&data);
		ve.push_back(data);

	}
	int u,v;
//	postOrder(BST);
//	printf("\n");
//	bulidSearchTable(BST,ve);
	int lca;
	for(i =0 ;i<M;i++){
		int flag1 = 0;
		int flag2 = 0;
		scanf("%d %d",&u,&v);
		unsigned int j=0;
		for(j = 0;j<ve.size();j++){
			if(u==ve[j]) flag1 = 1;
			if(v==ve[j]) flag2 = 1;
		}
		if(flag1==0&&flag2==0){
			printf("ERROR: %d and %d are not found.\n",u,v);
			continue;
		}else if(flag1==0&&flag2==1){
			printf("ERROR: %d is not found.\n", u);
			continue;
		}else if(flag1==1&&flag2==0){
			printf("ERROR: %d is not found.\n", v);
			continue;
		}else{

			for(j=0;j<ve.size();j++){
				if((u>ve[j]&&ve[j]>v)||(u<ve[j]&&ve[j]<v)||(u==ve[j])||(v==ve[j]))
				{
					lca = ve[j];
					break;
				}

			}
			
			if(lca==u)
				printf("%d is an ancestor of %d.\n", lca,v);
			else if(lca==v){
				printf("%d is an ancestor of %d.\n", lca,u);
			}else{
				printf("LCA of %d and %d is %d.\n", u,v,lca);
			}
		}

	}
}

int main(int argc, char const *argv[])
{
	init();
	
	return 0;
}
