#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin>>n; 
	std::vector<float> v;
	for(int i=0;i<n;i++){
		string input;
		cin>>input;
		int flag = true;
		int dot = 0;
		int pos=0;
		for(auto w:input){
			if((w>='0'&&w<='9')||w=='-'){
				flag = true;
			}else{
				if(w=='.'){
					dot++;
					if(input.size()-pos>3){
						flag= false;
						break;
					}
				}else{
					flag = false;
					break;
				}
			}
			pos++;
		}
		if(flag==false||dot>1){
			cout<<"ERROR: "<<input<<" is not a legal number"<<endl;
		}else{
			float a = stof(input);
			if(a>=-1000&&a<=1000){
				v.push_back(a);
			}
			else{
				cout<<"ERROR: "<<input<<" is not a legal number"<<endl;
			}
		}
	}
	if(v.size()>1){
		float res=0;
		for(auto w:v){
			res += w;
		}
		res = res/v.size()*1.0;
		printf("The average of %d numbers is %.2f\n",v.size(),res); 
	}else if(v.size()==0){
		printf("The average of 0 numbers is Undefined\n");
	}else{
		cout<<"The average of 1 number is "<<v[0]<<endl;
	}
	return 0;
}
