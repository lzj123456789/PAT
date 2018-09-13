#include <bits/stdc++.h>
using namespace std;
struct NODE{
	string id;
	int score;
	int finalrank;
	int localnum;
	int localrank;
}Rank[30010];
bool cmp(const NODE &a,const NODE &b){
	return (a.score==b.score)?(a.id<b.id):(a.score>b.score);
}
int main(int argc, char const *argv[])
{
	int n,k;
	scanf("%d",&n);
	int index = 0;
	for(int i=1;i<=n;i++){
		scanf("%d",&k);
		string id;
		int score;
		int beginLocal = index;
		for(int j=0;j<k;j++){
			cin>>id>>score;
			NODE node{id,score,0,i,0};
			Rank[index].id = id;
			Rank[index].score = score;
			Rank[index].finalrank = 0;
			Rank[index].localnum = i;
			Rank[index].localrank = 0;
			index++;
		}
		sort(Rank+beginLocal,Rank+index,cmp);
		Rank[beginLocal].localrank = 1;
		for(int j=beginLocal+1;j<index;j++){
			if(Rank[j].score==Rank[j-1].score){
				Rank[j].localrank = Rank[j-1].localrank;
			}else{
				Rank[j].localrank = j- beginLocal+1;
			}
		}
	}
	sort(Rank,Rank+index,cmp);
	Rank[0].finalrank = 1;
	for(int j=0;j<index;j++){
		if(Rank[j].score==Rank[j-1].score){
			Rank[j].finalrank = Rank[j-1].finalrank;
		}else{
			Rank[j].finalrank = j + 1;
		}
	}
	printf("%d\n", index);
	for(int i=0;i<index;i++){
		cout<<Rank[i].id<<" "<<Rank[i].finalrank<<" "<<Rank[i].localnum<<" "<<Rank[i].localrank<<endl;
	}
	return 0;
}
