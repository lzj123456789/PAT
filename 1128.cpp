#include <bits/stdc++.h>
using namespace std;
int k,n;
int main(int argc, char const *argv[])
{
	scanf("%d",&k);
	int n,q,flag;
	for(int i=0;i<k;i++){
		scanf("%d",&n);
		flag = 0;
		unordered_map<int,int> chessBoard;
		for(int j=1;j<n+1;j++){
			scanf("%d",&q);
			if(flag==1) continue;
			chessBoard[j] = q;
			for(int x=1;x<j;x++){
				if(chessBoard[x]==chessBoard[j]){
					flag = 1;
					printf("%d\n",chessBoard[x]);
					break;
				}else if((abs(chessBoard[x]-chessBoard[j]))==(abs(x-j))){
					printf("%d %d\n",chessBoard[x],chessBoard[j]);
					flag = 1;
					break;
				}
			}

		}
		if(flag) printf("NO\n");
		else printf("YES\n"); 
	}
	return 0;
}
