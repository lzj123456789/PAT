#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	std::vector<bool> valid(n,true);
	std::vector<int> v(n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	int maxFlag=-1;
	for(int i=0;i<n;i++){
		if(v[i]>maxFlag){
			maxFlag = v[i];
		}else {
			valid[i] = false;
		}
	}
	int minFlag = 1e9;
	for(int i=n-1;i>=0;i--){
		if(v[i]<minFlag){
			minFlag = v[i];
		}else{
			valid[i] = false; 
		}
	}
	std::vector<int> res;
	int j=0;
	for(int i=0;i<n;i++){
		if(valid[i]){
			res.push_back(v[i]);
			j++;
		}
	}
	sort(res.begin(),res.begin()+j);
	printf("%d\n", j);
	if(j==0){
		printf("\n");
		return 0;
	}
	for(int i=0;i<j;i++){
		if(i==0) printf("%d",res[0] );
		else printf(" %d", res[i]);
	}
	return 0;
}
