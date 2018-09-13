#include <bits/stdc++.h>
using namespace std;
const int maxLen = 100010; 
std::vector<int> graph[maxLen];
bool isVisted[maxLen];
std::vector<double> amount(maxLen);
double p,r;
double totalPrice;
void dfs(int node,double price){
	isVisted[node] = true;
	if(graph[node].size()==0){
		//printf("%lf %lf\n",price,amount[8]);
		totalPrice += price*amount[node];
	}
	//printf("%d\n", node);
	for(auto w:graph[node]){
		if(isVisted[w]==false){
			dfs(w,price+price*r*0.01);
		}
	}
}
int main(int argc, char const *argv[])
{
	int n;
	totalPrice =0;
	scanf("%d %lf %lf",&n,&p,&r);
	fill(isVisted,isVisted+n,false);
	for(int i=0;i<n;i++){
		int k,data;
		scanf("%d",&k);
		if(k!=0)
			for(int j=0;j<k;j++){
				scanf("%d",&data);
				graph[i].push_back(data);
			}
		else {
			scanf("%d",&data);
			amount[i] = data;
		}
	}
	dfs(0,p);
	printf("%.1lf\n",totalPrice );
	return 0;
}
