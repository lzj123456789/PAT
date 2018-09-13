#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int m,n,k;
	scanf("%d %d %d",&m,&n,&k);
	std::vector<int> check(n+1);
	for(int i=0;i<k;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&check[j]);
		}
		stack<int> s;
		bool flag = true;
		int current = 1;
		for(int j=1;j<=n;j++){
			s.push(j);
			if(s.size()>m){
				flag = false;
				break;
			}
			//printf("%d\n",check[current]);
			while(!s.empty() && s.top()== check[current]){
				s.pop();
				current ++;
			}
		}
		if(s.empty()==true&&flag==true){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	return 0;
}