#include <cstdio>
#include <cstdlib>

using namespace std;

int Nv,Ne,M,K;

void init(){
	scanf("%d %d",&Nv,&Ne);
	int i;
	int v1,v2;
	int * graph = (int *)malloc(sizeof(int)*Nv*Nv);
	for(i=0;i<Nv;i++){
		int j=0;
		for(j=0;j<Nv;j++){
			if(i!=j) graph[i*Nv+j] = -1;
			else graph[i*Nv+j]=1;

		}
	}
	for(i=0;i<Ne;i++){
		scanf("%d %d",&v1,&v2);
		v1--;
		v2--;
		graph[Nv*v1+v2] = 1;
		graph[Nv*v2+v1] = 1;
	}
	/*for(i=0;i<Nv*Nv;i++){
		printf("%d ",graph[i]);
		if((i+1)%Nv==0) printf("\n");
	} */ 
	scanf("%d",&M);
	for(i=0;i<M;i++){
		int *tmpGraph = (int *)malloc(sizeof(int)*Nv *Nv);
		int m,n;

		for(m=0;m<Nv*Nv;m++){
			tmpGraph[m] = graph[m];
		}

		scanf("%d",&K);
		int j;
		int* query = (int *)malloc(sizeof(int)*K);
		int tmp;
		for(j=0;j<K;j++){
			scanf("%d",&tmp);
			query[j] = --tmp;
		}
		
		int flag = 0;
		for(m=0;m<K;m++){
			for(n=m;n<K;n++){
				if(tmpGraph[query[m]*Nv+query[n]]==1){		
					tmpGraph[query[m]*Nv+query[n]] = -1;
					tmpGraph[query[n]*Nv+query[m]] = -1;
					flag = 1;
				} else{
					flag = 0;
					break;
				}
			}
			if(flag==0){
				break;
			}
		}
		if(flag==0){
			printf("Not a Clique\n");
			continue;
		}else{
			int flag1=0;
			for(m=0;m<Nv;m++){
				flag = 0;
				for(n=0;n<K;n++){
					if(tmpGraph[m*Nv+query[n]]==1&&m!=query[n]){
						flag ++;
					}
				}

				if(flag==K&&flag!=0){
					printf("Not Maximal\n");
					flag1=1;
					break;
				}
			}
			if(flag1==0) printf("Yes\n");
		}
	}
}

/*
vector<int>q;
q.resize(k+1);
for(int i=0;i<k;i++)scanf("%d",&q[i]);
*/

int main(int argc, char const *argv[])
{
	init();
	return 0;
}
