#include<bits/stdc++.h>
#define ll long long
#define pb push back
using namespace std;
const ll N=1e5+5;
ll a[N],b[N];
ll n,m;
void in(){
	cin>>n>>m;
	for(int i=0;i<=n-1;i++) cin>>a[i];
	for(int i=0;i<=m-1;i++) cin>>b[i];
}
void out(){
	ll dem=0;
	for(int i=0;i<=m-1;i++){
		if(a[0]==b[i] && i+n-1<=m-1)
		{
			ll check=1;
			for(int j=1;j<=n-1;j++) 
				if(b[i+j]!=a[j])
				{
					i=j+1;
					check=0;
					break;
				}
			if(check==1)
			{
				cout<<i<<" ";
				i+=n-1;
				dem++;
			}
		}
	}
	cout<<endl<<dem;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	in();
	out();
	return 0;
};
