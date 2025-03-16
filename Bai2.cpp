#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
#define f first
#define s second
#define MOD 1000005
using namespace std;
ll n;
struct PS
{
    ll tuso;
    ll mauso;
};
PS a[3];
void in()
{
   for(int i=1;i<=2;i++){
        cin >> a[i].tuso >> a[i].mauso;
        if(a[i].mauso==0){
            cout<<"Mau so khong the bang 0"<<endl;
            exit(0);
        }
    }
}
inline bool Phanso(PS a, PS b){
	ll check1=a.tuso*b.mauso;
	ll check2=b.tuso*a.mauso;
	return ((check1>check2) ? 1 : 0 );
}
void out(){
	if(Phanso(a[1],a[2])==1)
	{
		cout<<a[1].tuso<<" "<<a[1].mauso;	
	}
	else
	{
		cout<<a[2].tuso<<" "<<a[2].mauso;
	}
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    in();
    out();
    return 0;
}
