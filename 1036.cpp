#include <bits/stdc++.h>
using namespace std;
struct NODE{
	string name,gender,id;
	int grade;
};

bool cmp(const NODE a,const NODE b){
	return a.grade>b.grade;
}
int main(int argc, char const *argv[])
{
	int n;
	string name,gender,id;
	int grade;
	scanf("%d",&n);
	std::vector<NODE> vm,vf;
	for(int i=0;i<n;i++){
		cin>>name>>gender>>id>>grade;
		NODE node{name,gender,id,grade};
		if(gender=="M"){
			vm.push_back(node);
		}else if(gender=="F"){
			vf.push_back(node);
		}
	}
	sort(vm.begin(),vm.end(),cmp);
	sort(vf.begin(), vf.end(),cmp);
	int vmsize = vm.size();
	int vfsize = vf.size();
	if(vmsize!=0 && vfsize !=0){
		cout<<vf[0].name<<" "<<vf[0].id<<endl;
		cout<<vm[vmsize-1].name<<" "<<vm[vmsize-1].id<<endl;
		cout<<vf[0].grade- vm[vmsize-1].grade<<endl;
	}else if(vmsize==0 && vfsize !=0){
		cout<<vf[0].name<<" "<<vf[0].id<<endl;
		cout<<"Absent"<<endl;
		cout<<"NA"<<endl;
	}else if(vmsize!=0 && vfsize==0){
		cout<<"Absent"<<endl;
		cout<<vm[vmsize-1].name<<" "<<vm[vmsize-1].id<<endl;
		cout<<"NA"<<endl;
	}else{
		cout<<"Absent"<<endl;
		cout<<"Absent"<<endl;
		cout<<"NA"<<endl;
	}
	return 0;
}
