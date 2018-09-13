#include <bits/stdc++.h>
using namespace std;
int n;
int main(void){
	scanf("%d",&n);
	set<int> setD;
	for(int i=0;i<n;i++){
		string data;
		cin>>data;
		int sum=0;
		for(auto j:data){
			sum += (j-'0');
		}
		//cout<<sum<<endl;
		setD.insert(sum);
	}
	printf("%d\n", setD.size());
	int i=0;
	for(auto w:setD){
		if(i==0){
			printf("%d", w);
			i++;
		}else printf(" %d", w);
	}
}
