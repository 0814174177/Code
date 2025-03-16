#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n=10,dau,x;
void in(){
	cin>>x;
}
ll giaithua(ll i){
	if(i==0) return 1;
	ll sum=1;
	for(int j=1;j<=i;j++) sum*=j;
	return sum; 
}
void out(){
	ll i=0;
	ll luythua;
	double sin_x=0;
	while(i<=n){
		if(i%2==0) dau=1;
			else dau=-1;
		luythua=pow(x,2*i+1);
		sin_x+=(double)(dau*luythua)/giaithua(2*i+1);
		i++;
	}
	cout<<fixed<<setprecision(5);
	cout<<sin_x;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	in();
	out();
	return 0;
}
