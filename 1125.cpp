#include <bits/stdc++.h>
using namespace std;
int n;
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	std::vector<int> ropes;
	int rope;
	for (int i = 0; i < n; ++i)
	{
		scanf("%d",&rope);
		ropes.push_back(rope);
	}
	sort(ropes.begin(),ropes.end());
	int i=0;
	while(1){
		std::vector<int> res;
	//	sort(ropes.begin(),ropes.end());
		if(ropes.size()>2){
			res.push_back((ropes[0]+ropes[1])/2);
		}else if(ropes.size()==2){
			printf("%d\n", (ropes[0]+ropes[1])/2);
			break;
		}
		for(auto i=2;i<ropes.size();i++){
			res.push_back(ropes[i]);
		}
		ropes = res;
	}

	return 0;
}
