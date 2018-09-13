#include <bits/stdc++.h>
using namespace std;
const int maxLen = 1010;
int n;
std::vector<int> v(maxLen),tree(maxLen,-1);
int num=0;
void inOrder(int root){
	if(root>n) return;
	inOrder(2*root);
	tree[root] = v[num++];
	inOrder(2*root+1);
}
int main(int argc, char const *argv[])
{
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
	}
	sort(v.begin(),v.begin()+n);
	inOrder(1);
	for(int i=1;i<=n;i++){
		if(i==1) printf("%d",tree[i] );
		else {
			if(tree[i]!=-1){
				printf(" %d",tree[i] );
			}
		}
	}
	return 0;
}
