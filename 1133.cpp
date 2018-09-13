#include <bits/stdc++.h>

using namespace std;

struct Node{
	string addr;
	string next;
	int data;
};
int n,k;
void init(){
	string firstAddr;
	cin>>firstAddr>>n>>k;

	string addr,next;
	int data;
	unordered_map<string,Node> link;

	for(int i=0;i<n;i++){
		cin>>addr>>data>>next;
		Node node{addr,next,data};
		link[addr] = node;
	}	

	std::vector<Node> frame1,frame2,frame3;
	string currentAddr=firstAddr;
	string nextAddr;

	while(1){
		if(link[currentAddr].data<0){
			frame1.push_back(link[currentAddr]);
		}else if(link[currentAddr].data>=0&&link[currentAddr].data<=k){
			frame2.push_back(link[currentAddr]);
		}else{
			frame3.push_back(link[currentAddr]);
		}
		currentAddr = link[currentAddr].next;
		if(currentAddr=="-1"){
			break;
		}
	}

	for(unsigned int i=0;i<frame1.size();i++){
		unsigned int j=i+1;
		if(j<frame1.size()){
			frame1[i].next = frame1[j].addr;
		}else{
			if(frame2.size()){
				frame1[i].next = frame2[0].addr;
			}else if(frame3.size()){
				frame1[i].next = frame3[0].addr;
			}else {
				frame1[i].next = "-1";
			}
		}
	}

	for(unsigned int i=0;i<frame2.size();i++){
		unsigned int j = i+1;
		if(j<frame2.size()){
			frame2[i].next = frame2[j].addr;
		}else{
			if(frame3.size()){
				frame2[i].next = frame3[0].addr;
			}else{
				frame2[i].next = "-1";
			}
		}
	}

	for(unsigned int i=0;i<frame3.size();i++){
		unsigned int j = i+1;
		if(j<frame3.size()){
			frame3[i].next = frame3[j].addr;
		}else{
			frame3[i].next = "-1";
		}
	}
	 
	for(auto w:frame1){
		printf("%s %d %s\n",w.addr.c_str(), w.data,w.next.c_str());
	}
	for(auto w:frame2){
		printf("%s %d %s\n",w.addr.c_str(), w.data,w.next.c_str());
	}
	for(auto w:frame3){
		printf("%s %d %s\n",w.addr.c_str(), w.data,w.next.c_str());
	}


}

int main(int argc, char const *argv[])
{
	init();
	return 0;
}
