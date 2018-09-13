#include <cstdio>
#include <cstdlib>

#include <unordered_map>

using namespace std;

int N;
const int MaxLen = 50005;
int preOrder[MaxLen];
int inOrder[MaxLen];
int key;

bool flag = 0;

void findTree(int PreBegin,int PreEnd,int InBegin,int InEnd){
	if(flag==1) return;
	if(PreBegin==PreEnd) {
		flag = 1;
		key = preOrder[PreBegin];
		return;
	}
	int root = preOrder[PreBegin];
	int len;
	int i;
	for(i = InBegin;i<=InEnd;i++){
		if(inOrder[i]==root){
			len = i - InBegin;
			break;
		}
	}
	if(len==0) {
		return findTree(PreBegin+1,PreEnd,InBegin,InEnd);
	}else{
		return findTree(PreBegin+1,PreBegin+len,InBegin,1);
	}

}

void init()
{
	scanf("%d",&N);

	for(int i=0;i<N;i++){
		scanf("%d",&preOrder[i]);
	}
	for(int i=0;i<N;i++){
		scanf("%d",&inOrder[i]);
	}
	findTree(0,N-1,0,N-1);
	printf("%d\n", key);
}

int main(int argc, char const *argv[])
{
	init();
	
	return 0;
}
