#include<bits/stdc++.h>
using namespace std;
struct NODE{
	long int up;
	long int down;
	long int integer;
};
long int gcd(long int a,long int b){
	return b?gcd(b,a%b):a;
}
NODE reduction(NODE a){
	if(a.down<0){
		a.up = -a.up;a.down = -a.down;
	}
	if(a.up==0){
		a.down = 1;
	}else{
		long int g = gcd(abs(a.up),abs(a.down));
		a.up = a.up/g;
		a.down = a.down/g;
	}
	return a;
}
NODE add(NODE a,NODE b){
	NODE res;
	res.up = a.up*b.down+a.down*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}
NODE diff(NODE a,NODE b){
	NODE res;
	res.up = a.up*b.down-a.down*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}
NODE product(NODE a,NODE b){
	NODE res;
	res.up = a.up*b.up;
	res.down = a.down*b.down;
	return reduction(res);
}
NODE quotient(NODE a,NODE b){
	NODE res;
	res.up = a.up*b.down;
	res.down = a.down*b.up;
	return reduction(res);
}
string to_ration(NODE a){
	string res="";
	a.integer = a.up/a.down;
	if(a.up<0&&a.integer!=0) a.up = -a.up;
	a.up = a.up%a.down;
	if(a.integer==0&&a.up!=0){//2/3
		res = to_string(a.up)+"/"+to_string(a.down);
	}else if(a.up==0){
		res = to_string(a.integer);
	}else{
		res = to_string(a.integer)+" "+to_string(a.up)+"/"+to_string(a.down);
	}
	if(a.integer<0||a.up<0){
		res.insert(0,1,'(');
		res.insert(res.size(),1,')');
	}
	return res;
}
string sign[4] = {"+","-","*","/"};
void print(NODE a,NODE b,NODE res,int tag)
{
	string p="";
	string strb = to_ration(b);
	if(tag==3&&strb=="0"){
		p = to_ration(a)+" "+sign[tag]+" "+strb+" = Inf";
		cout<<p<<endl;
		return;
	}
	p = to_ration(a)+" "+sign[tag]+" "+strb+" = "+to_ration(res);
	cout<<p<<endl;
}
int main(int argc, char const *argv[])
{
	NODE a,b,tmp1,tmp2,tmp3,tmp4,tmpa,tmpb;
	scanf("%ld/%ld %ld/%ld",&a.up,&a.down,&b.up,&b.down);
	a = reduction(a);
	b = reduction(b); 
	print(a,b,add(a,b),0);
	print(a,b,diff(a,b),1);
	print(a,b,product(a,b),2);
	print(a,b,quotient(a,b),3);

	return 0;
}
