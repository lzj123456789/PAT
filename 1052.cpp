#include <bits/stdc++.h>
using namespace std;
struct NODE{
	int key;
	string address,next;
};
std::vector<NODE> v;
int main(int argc, char const *argv[])
{
	int n,key;
	string head,address,next;
	scanf("%d",&n);
	cin>>head;
	for(int i=0;i<n;i++){
		cin>>address>>key>>next;
		NODE node{address,key,next};
		v.push_back(node);
	}
	int valid = 0;
	while()
	return 0;
}