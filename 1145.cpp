#include <cstdio>
#include <cstdlib>

using namespace std;

int MSize,N,M;

bool judgePrime(int data)
{
	if(data<=3) return true;
	int i=2;
	for(i=2;i<=data/2;i++){
		if(data%i==0)
			return false;
	}
	return true;
}

int findMinPrime(int data)
{
	int i=data;
	for(i=data;;i++){
		if(judgePrime(i)){
			return i;
		}
	}
}

void init()
{
	scanf("%d %d %d",&MSize,&N,&M);
	MSize = findMinPrime(MSize);

	int * hash = (int *)malloc(sizeof(int)*MSize);
	int i=0;
	for(i=0;i<MSize;i++){
		hash[i] = -1;
	}
	int key;
	int flag = 0;
	for(i=0;i<N;i++){
		scanf("%d",&key);
		int j;
		flag = 0;
		for(j=0;j<MSize;j++){
			if (hash[(key+j*j)%MSize]==-1)
			{
				hash[(key+j*j)%MSize] = key;
				flag = 1;
				break;
			}
		}
		if(flag==0){
			printf("%d cannot be inserted.\n", key);
		}
	}
	int  count = 0;
	for(i=0;i<M;i++){
		flag = 0;
		scanf("%d",&key);
		int j;
		for(j=0;j<MSize;j++){
			if((hash[(key+j*j)%MSize]==key)||(hash[(key+j*j)%MSize]==-1)){
				flag = 1;
				count+=(j+1);
				break;
			}
		}
		if(flag==0){
			count += (j+1);
		}
	}

	float cost;
	cost = 1.0*count/M;

	printf("%.1f\n", cost);

}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}
