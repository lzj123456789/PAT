#include <iostream>
#include <string>
#include<fstream>
#include<vector>
using namespace std;
int main()
{

	std::vector<int> v;
	for(int i=0;i<10;i++){
		v.push_back(i);
	}

	for(auto w:v){
		if(++w){
			cout<<w<<endl;;
		}
	}

	/*string a = "123";
	string b = "456";
	int m = a[0]-'0';
	int n = b[0]-'0';
	printf("%d",m+n);
return 0;*/
}
