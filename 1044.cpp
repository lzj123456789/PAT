#include <bits/stdc++.h>
using namespace std;
int n;
std::vector<int> sum(100010);
int findright(int l,int r,int x){
	int left = l,right = r;
	while(left<right){
		//printf("findright %d %d %d %d\n",left,right,x,a[right]);
		int mid = (left+right)/2;
		if(sum[mid]>=x){
			right = mid;
		}else{
			left = mid+1;
		}
	}
	return left;
}
int main(void){
	int m;
	scanf("%d %d",&n,&m);
	sum[0] = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&sum[i]);
		sum[i] += sum[i-1];
	}
	int optM = 1e9;
	for(int i=0;i<=n;i++){
		int j = findright(i+1,n,sum[i]+m);
		//printf("right %d\n",j);
		if(sum[j]-sum[i]==m){
			optM = m;
			break;
		}else if(j<=n&&sum[j]-sum[i]<optM&&sum[j]-sum[i]>m){
			//printf("optM %d %d %d\n",sum[j],sum[i],optM);
			optM = sum[j]-sum[i];
		}
	}
	for(int i=0;i<=n;i++){
		int j = findright(i+1,n,sum[i]+optM);
		if(sum[j]-sum[i]==optM){
			printf("%d-%d\n",i+1,j );
		}
	}
}
