#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+6;
ll local;
class Phan_so{
	private:
		ll tuso;
		ll mauso;
	public:
		void in();
		void Accept(); // loi phan so,rut gon phan so
		Phan_so Plus(Phan_so a, Phan_so b){
			Phan_so c;
			c.tuso=a.tuso*b.mauso+b.tuso*a.mauso;
			c.mauso=a.mauso*b.mauso;
			return c;
		}
		Phan_so Subtraction(Phan_so a, Phan_so b){
			Phan_so c;
			c.tuso=a.tuso*b.mauso-b.tuso*a.mauso;
			c.mauso=a.mauso*b.mauso;
			return c;
		}
		Phan_so Multiplication(Phan_so a, Phan_so b){
			Phan_so c;
			c.tuso=a.tuso*b.tuso;
			c.mauso=a.mauso*b.mauso;
			return c;
		}
		Phan_so divide(Phan_so a, Phan_so b){
			Phan_so c;
			if(b.tuso==0)
			{
				c.tuso=0;
				c.mauso=0;
				return c;
			}
			c.tuso=a.tuso*b.mauso;
			c.mauso=a.mauso*b.tuso;
			return c;
		}
		void out();
};
void Phan_so::in(){  
	cin>>tuso>>mauso;
	if(mauso<0) tuso=-tuso,mauso=-mauso;
	// loi phan so
	if(mauso==0) local=-1;
}
ll UCLN(ll a, ll b){
	if(a==0) return b;
	if(b==0) return a;
	return UCLN(b,a%b);
}
void Phan_so::Accept(){
	// rut gon phan so
	ll ucln=UCLN(tuso,mauso);
	tuso=tuso/ucln;
	mauso=mauso/ucln;
}
void Phan_so::out(){
	cout<<tuso<<"/"<<mauso<<endl;
}
//Phan_so operator+(Phan_so a, Phan_so b){
//	Phan_so c;
//	c.tuso=a.tuso*b.mauso+b.tuso*a.mauso;
//	c.mauso=a.mauso*b.mauso;
//	return c;
//}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	Phan_so Number_1,Number_2,Number;
	Number_1.in();
	Number_2.in();
	if(local!=-1)
	{
		Number=Number.Plus(Number_1,Number_2);
			Number.Accept();	
			Number.out();
		Number=Number.Subtraction(Number_1,Number_2);
			Number.Accept();
			Number.out();
		Number=Number.Multiplication(Number_1,Number_2);
			Number.Accept();
			Number.out();
		Number=Number.divide(Number_1,Number_2);
			Number.Accept();
			Number.out();
	}
	return 0;
}
