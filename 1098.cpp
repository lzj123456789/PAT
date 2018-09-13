#include <bits/stdc++.h>
using namespace std;
std::vector<int> origin(100),part(100),heap(100);
void downAdj(int low,int high)
{
	int i=low,j = 2*i;
	while(j<=high){
		if(j+1<=high){
			if(heap[j]<heap[j+1]){
				j++;
			}
		}
		if(heap[i]<heap[j]){
			swap(heap[i],heap[j]);
			i = j;
			j = 2*i;
		}else{
			break;
		}
	}
}
int main(int argc, char const *argv[])
{
	int n,data;
	scanf("%d",&n);
	for(int j = 0;j<2;j++)
		for(int i=0;i<n;i++){
			if(j==0) {
				scanf("%d",&data);
				origin.push_back(data);
			}
			else if(j==1) {
				scanf("%d",&data);
				part.push_back(data);
			}
		}
	std::vector<int> tmp = origin;
	for(int i=0;i<=n;i++){
		sort(tmp.begin(),tmp.begin()+i);
		if(tmp==part){
			printf("Insertion Sort\n");
			while(tmp==part){
				i++;
				sort(tmp.begin(),tmp.begin()+i);
			}
			int i=0;
			for(auto w:tmp){
				if(i==0) printf("%d",w);
				else printf(" %d",w );
				i++;
			}
		}
	}

	for()

	return 0;
}