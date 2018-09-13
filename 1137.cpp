#include <bits/stdc++.h>

using namespace std;
int P,M,N;

const int MaxLen = 1e4;

struct STU{
	int pro;
	int mid;
	int final;
	int grade;
	string name;
};

std::vector<STU> v;


bool cmp(const STU &a, const STU &b){
	if(a.grade>b.grade) return true;
	else if(a.grade==b.grade){
		if(a.name<b.name){
			return true;
		}else {
			return false;
		}
	}else {
		return false;
	}
}

void init(){
	scanf("%d %d %d",&P,&M,&N);
	string name;
	unordered_map<string,STU> m;
	int pro;
	for(int i=0;i<P;i++){
		cin>>name>>pro;

		STU student;

		if(pro>=200){
			student.name = name;
			student.pro = pro;
			student.mid = -1;
			student.final = -1;
			student.grade = -1;
			m[name]=student;
		}
		
	
	}
	int mid;
	for (int i = 0; i < M; ++i)
	{
		cin>>name>>mid;
		if(m.count(name)){
			m[name].mid = mid;
		}
	}

	int final;
	for(int i=0;i<N;i++){
		cin>>name>>final;
		if(m.count(name)){
			m[name].final = final;
			int grade = (m[name].mid>m[name].final)?(int((1.0*m[name].mid*4+1.0*m[name].final*6)/10+0.5)):(m[name].final);
			if(grade>=60){
				m[name].grade = grade;
				v.push_back(m[name]);
			}

		}
	}

	sort(v.begin(),v.end(),cmp);

	for(auto j:v){
		printf("%s %d %d %d %d\n",j.name.c_str(),j.pro,j.mid,j.final,j.grade );
	}

}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}
