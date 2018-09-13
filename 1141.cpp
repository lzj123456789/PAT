#include <cstdio>
#include <cstdlib>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

int N;
const int Maxlen = 1e5;

struct RANK{
	string school;
	int score;
	int Ns;
}Ran[Maxlen];

bool compare(const RANK &a,const RANK &b){
	if(a.score>b.score){
		return true;
	}else if(a.score==b.score){
		if(a.Ns<b.Ns){
			return true;
		}else if(a.Ns==b.Ns){
			if(a.school<b.school){
				return true;
			}else{
				return false;
			}
		}else{
			return false;
		}
	}else{
		return false;
	}
}

void tolower1(string &str){

	int len = str.size();

	for(int i=0;i<len;i++){
		str[i] = tolower(str[i]);
	}

	/*int len = str.size();

	char tmpa;

	for(int i=0;i<len;i++){
		tmpa = str[i];
		if(int(tmpa)<91){
			tmpa = (char) (int(tmpa) +32);
			str[i] = tmpa;
		}
	//	cout<< str[i]<<endl;
	}*/

}

void init(){
	scanf("%d",&N);
	string id,school;

	struct RANK * Rank = (struct RANK *)malloc(sizeof(struct RANK)*Maxlen);
	Rank = Ran;
	for(int i=0;i<Maxlen;i++){
		Rank[i].score = 0;
		Rank[i].Ns = 0;
	}

	int score;
	int count=0;
	for(int i=0;i<N;i++){
		cin>>id>>score>>school;

		tolower1(school);
		id = id[0];

		if(id=="A"){
			score = score;
		}else if(id=="B"){
			score = score/1.5;
		}else if(id=="T"){
			score = score*1.5;
		}
		int j=0;
		for(j=0;Rank[j].Ns!=0;j++){
			if(Rank[j].school==school){
				//school already exists
				Rank[j].score = Rank[j].score+score;
				Rank[j].Ns++;
				break;
			}
		}
		if(Rank[j].Ns==0){
			Rank[j].school = school;
			Rank[j].score = score;
			Rank[j].Ns++;
		}
		
	}

	int totalNum=0;

	for(int j=0;Rank[j].Ns!=0;j++){
		totalNum++;
	}

	sort(Rank,Rank+totalNum,compare);
	printf("%d\n", totalNum);

	int r=0;

	count = 0;
	for(int i=0;Rank[i].Ns!=0;i++){
		if(i==0){
			r = 1;
			printf("%d %s %d %d\n",r,Rank[i].school.c_str(), Rank[i].score,Rank[i].Ns);
			//cout<< r<<" "<<Rank[i].school<<" "<<Rank[i].score<<" "<<Rank[i].Ns<<endl;
		}
		if(i!=0&&Rank[i].score==Rank[i-1].score){
			r=r;
			count++;
			printf("%d %s %d %d\n",r,Rank[i].school.c_str(), Rank[i].score,Rank[i].Ns);

			//cout<< r<<" "<<Rank[i].school<<" "<<Rank[i].score<<" "<<Rank[i].Ns<<endl;
			
		}else if(i!=0){
			r = r+count+1;
			printf("%d %s %d %d\n",r,Rank[i].school.c_str(), Rank[i].score,Rank[i].Ns);

			//cout<< r<<" "<<Rank[i].school<<" "<<Rank[i].score<<" "<<Rank[i].Ns<<endl;
			count=0;

		}
		
	}	

}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}
