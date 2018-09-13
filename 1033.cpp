#include <bits/stdc++.h>
using namespace std;
struct NODE{
	double p;
	double d;
};
const double INF = 1e7;
bool cmp(const NODE &a,const NODE &b){
	return a.d<b.d;
}
int main(int argc, char const *argv[])
{
	double cmax,d,davg;
	int n;
	scanf("%lf %lf %lf %d",&cmax,&d,&davg,&n);
	std::vector<NODE> station(n+1);
	for(int i=0;i<n;i++){
		scanf("%lf %lf",&station[i].p,&station[i].d);
	}
	station[n].p=0;station[n].d=d;
	sort(station.begin(),station.end(),cmp);
	if(station[0].d!=0){
		printf("The maximum travel distance = 0.00\n");
	}else{
		int now = 0;
		double maxReach = cmax*davg,cost=0,nowTank = 0;
		while(now!=n){
			int k=-1;
			double minPrice = INF;
			for(int i=now+1;i<=n&&(station[i].d- station[now].d )<=maxReach;i++){
				if(station[i].p<minPrice){
					minPrice = station[i].p;
					k=i;
					if(station[i].p<station[now].p){
						break;
					}
				}
			}
			if(k==-1){
				printf("The maximum travel distance = %.2lf\n",station[now].d+maxReach );
				return 0;
			}
			double need = (station[k].d- station[now].d)/davg;
			if(station[k].p<station[now].p){
				if(nowTank < need){
					cost += station[now].p*(need- nowTank);
					nowTank =0;
				}else{
					nowTank -= need;
				}
			}else{
				cost += station[now].p * (cmax - nowTank);
				nowTank = cmax - need; 
			}
			now = k;
		}
		printf("%.2lf\n", cost);
	}
	return 0;
}