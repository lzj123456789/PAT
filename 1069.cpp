#include <bits/stdc++.h>
using namespace std;
bool cmp(char a,char b){
	return a>b;
}
int main(int argc, char const *argv[])
{
	string n;
	cin>>n;
	n.insert(0,4-n.size(),'0');
	string revn=n;
	reverse(revn.begin(),revn.end());
	if(revn==n){
		cout<<n<<" - "<<n<<" = 0000"<<endl;
		return 0; 
	}
	string a,b;
	int inta,intb,intn,flag;
	int j=0;
	while(n!="6174"||j==0){
		j++;
		n.insert(0,4-n.size(),'0');
		a = n;
		b = n;
		sort(a.begin(),a.end());
		sort(b.begin(),b.end(),cmp);
		inta = stoi(a);
		intb = stoi(b);
		if(inta>intb){
			intn = inta-intb;
			n = to_string(intn);
			printf("%04d - %04d = %04d\n", inta,intb,intn);
		}
		else{
			intn = intb- inta;
			n = to_string(intn);
			printf("%04d - %04d = %04d\n", intb,inta,intn);
		}

	}
}
