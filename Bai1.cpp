#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class Phanso{
    private:
        ll tuso;
        ll mauso;
    public:
        void in();
        void rutgon();
        void out(); 
};
ll UCLN(ll a, ll b){
    if(a==0) return b;
    if(b==0) return a;
    return UCLN(b,a%b);
}
void Phanso::in(){
    cin>>tuso>>mauso;
    if(mauso==0){
        cout<<"Mau so khong the bang 0"<<endl;
        exit(0);
    }
}
void Phanso::rutgon(){
    ll ucln = UCLN(tuso,mauso);
    tuso/=ucln;
    mauso/=ucln;
}
void Phanso::out(){
    cout<<tuso<<"/"<<mauso<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Phanso a;
    a.in();
    a.rutgon();
    a.out();
    return 0;
}