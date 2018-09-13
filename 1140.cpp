#include <cstdio>
#include <cstdlib>

using namespace std;

int D,N;
const int lengthL= 1e5;

void init(){
	scanf("%d %d",&D,&N);
	int *string1 = (int *)malloc(sizeof(int)*lengthL);
	int *strint2 = (int *)malloc(sizeof(int)*lengthL);
	int i=0;
	for(i=0;i<lengthL;i++){
		string1[i] = -1;
		strint2[i] = -1;
	}

	string1[0] = D;
	for(i=1;i<N;i++){
		int j=0;
		int count = 0;
		while(string1[j]!=-1){
			int num=0;
			int start = string1[j];
			strint2[count] = start;
			count++;
			while(string1[j] == start){
				num++;
				j++;
			}
			strint2[count] = num;
			count++;

		}
		for(j=0;j<lengthL;j++){
			if(strint2[j]==-1) break;
			string1[j] = strint2[j];
			strint2[j] = -1;
		}

	}
	int j=0;
	for(j=0;j<lengthL;j++){
		if(string1[j]==-1) break;
		printf("%d", string1[j]);
	}

}

int  main(int argc, char const *argv[])
{
	init();
	return 0;
}
