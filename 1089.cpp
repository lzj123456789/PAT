#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	std::vector<int> init(n),part(n);
	for(int j=0;j<2;j++)
		for(int i=0;i<n;i++){
			if(j==0) scanf("%d",&init[i]);
			else if(j==1) scanf("%d",&part[i]);
		}
	std::vector<int> tmp = init;
	for(int i=1;i<=n;i++){
		sort(tmp.begin(),tmp.begin()+i);
		if(tmp==part){
			for(int j=i+1;j<=n;j++){
				sort(tmp.begin(),tmp.begin()+j);
				if(tmp!=part) break;
			}		
			int j=0;
			printf("Insertion Sort\n");
			for(auto w:tmp){
				if(j==0) printf("%d", w);
				else printf(" %d",w );
				j++;
			}
			return 0;
		}
	}
	tmp = init;
	bool isM = false;
	for(int l=2;l/2<n;l = l*2 ){
		for(int i=0;i<n;i+=l){
			sort(tmp.begin()+i,min(tmp.end(),tmp.begin()+i+l));
		}
		if(isM){
			printf("Merge Sort\n");
			int j=0; 
			for(auto w:tmp){
				if(j==0) printf("%d", w);
				else printf(" %d",w );
				j++;
			}
			return 0;
		}
		if(tmp==part){
			isM = true;
		}
	}
	return 0;
}
