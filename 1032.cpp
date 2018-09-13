#include <bits/stdc++.h>
using namespace std;
unordered_map <int,int> link;
unordered_map<int,int> degreein;
int main(int argc, char const *argv[])
{
	int ina,inb,address,next;
	int n;
	char data;
	scanf("%d%d%d",&ina,&inb,&n);
	for(int i=0;i<n;i++){
		scanf("%d %c %d",&address,&data,&next);
		link[address] = next;
	}
	for(int i = ina;i!=-1;i=link[i]){
		degreein[i] = 1;
	}
	int i;
	for(i = inb;i!=-1;i=link[i]){
		if(degreein.count(i)!=0){
			printf("%05d\n", i);
			break;
		}
	}
	if(i==-1) cout<<-1<<endl;
	return 0;
}
