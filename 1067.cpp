#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	scanf("%d",&n);
	std::vector<int> v(n);
	std::vector<bool> isok(n);
	int zeroindex;
	int ok=0;
	for(int i=0;i<n;i++){
		scanf("%d",&v[i]);
		if(v[i]==i) {
			isok[i] = true;
			ok++;
		}
		else isok[i] = false;
		if(v[i]==0) zeroindex = i; 
	}
	
	int times=0;
	while(ok!=n-1){
		for(int i=0;i<n;i++){
			if(v[i]==zeroindex){
				swap(v[i],v[zeroindex]);
				times++;
				isok[zeroindex] = true;
				zeroindex = i;
				ok++;
				break;
			}
		}
		if(zeroindex==0&&ok!=n-1){
			for(int i=1;i<n;i++){
				if(isok[v[i]]==false){
					swap(v[zeroindex],v[i]);
					times++;
					break;
				}
			}
		}

	}
	cout<<times<<endl;
	return 0;
}


/*
5
4 0 2 1 3
*/
