#include <cstdio>
#include <cstdlib>

using namespace std;

int N,M,K;

void init()
{
	scanf("%d %d",&N,&M);
	int i;
	int begin,end;
	int* graph = (int *)malloc(sizeof(int)*N*N);

	for(i=0;i<N*N;i++){
		graph[i] =0;
	}

	for(i=0;i<M;i++){
		 
		scanf("%d %d",&begin,&end);
		begin --;
		end--;
		graph[begin*N +end] = 1; 
		graph[end*N+begin] = -1;
		//printf("%d %d %d\n",i,begin*N +end,end*N+begin);
	}
	scanf("%d",&K);

	int *tmp = (int *)malloc(sizeof(int)*N*N);

	int query;
	int *degree = (int *)malloc(sizeof(int)*N);

	for(i=1;i<N;i++){
		degree[i] = 0;
	}

	int *result = (int *) malloc(sizeof(int)*K);

	for(i=0;i<K;i++){
		result[i] = -1;
	}

	int count = 0;
	for(i=0;i<K;i++){
		int m,n;
		for(m=0;m<N;m++){
			for(n=0;n<N;n++){
				tmp[m*N+n]= graph[m*N+n];
			}
		}

		int j=0;
		for(j=0;j<N;j++){
			scanf("%d",&query);
			query--;
			degree[j] = query;
		}

		int flag = 1;
		for(j=0;j<N;j++){
			for(m=0;m<N;m++){
				//printf("%d %d tmp %d\n",degree[j] ,m,tmp[degree[j]*N+m]);
				if(tmp[degree[j]*N+m]==-1)
				{
					
					result[count] = i;
					count++;
					flag = 0;
					break;
				}

				if(tmp[degree[j]*N+m]==1){
					tmp[degree[j]*N+m] = 0;
					tmp[m*N+degree[j]] = 0;
				}

			}
			if(flag==0)
				break;
		}

	}
	if(result[0]!=-1) {
		printf("%d", result[0]);
	}else{
		return;
	}

	for(i=1;i<K;i++){
		if(result[i]!=0)
			printf(" %d", result[i]);
	}
}


int main(int argc, char const *argv[])
{
	init();
	return 0;
}
