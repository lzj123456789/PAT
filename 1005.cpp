/*
加减零的应用，string处理方便很多。
*/
#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	string data;
	int sum=0;
	cin>>data;
	for(auto &w:data){
		sum += (w-'0');
	}
	string sumstr = to_string(sum);
	string tmp;
	int i=0;
	for(auto w:sumstr){
		if(w-'0'==1){
			tmp = "one";
		}else if(w-'0'==2){
			tmp = "two";
		}else if(w-'0'==3){
			tmp = "three";
		}else if(w-'0'==4){
			tmp = "four";	
		}else if(w-'0'==5){
			tmp = "five";
		}else if(w-'0'==6){
			tmp = "six";
		}else if(w-'0'==7){
			tmp = "seven";
		}else if(w-'0'==8){
			tmp = "eight";
		}else if(w-'0'==9){
			tmp = "nine";
		}else if(w-'0'==0){
			tmp = "zero";
		}

		if(i==0) cout<<tmp;
		else cout<<" "<<tmp;
		i++;
	}
	return 0;
}
