#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const ll N=1e5+5;
struct TimeStruct{
	ll day;
	ll month;
	ll year;
};
class sTime{
	private:
		ll minute;
		ll hour;
	public:
		void in(){ cin>>hour>>minute;}
		ll getHour() const { return hour; }
		ll getMinute() const { return minute; }
		bool Accept(){ // gio hop le
			if(minute<0 || minute>=60) return false;
			if(hour<0 || hour>23) return false;
			return true;
		}
};
class Time{
	private:
		ll a[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31};
		ll day;
		ll month;
		ll year;
	public:
		void in(){cin>>day>>month>>year; }
		ll getDay() const { return day; }
  		ll getMonth() const { return month; }
	    ll getYear() const { return year; }
		bool Leap_year_true_false(){
			if((year%100!=0 && year%4==0) || (year%400==0)) return true;
			return false;
		}
		void Leap_year(){
			if(Leap_year_true_false()==1) a[2]=29;
			return;
		}
		bool Accept(){
			if(Leap_year_true_false()==1) Leap_year();
			if(month<1 || month>12) return false;
			if(day<0 || day>a[month]) return false;
			return true;
		}
};
class fly{
	private:
		string ID_fly="";// cin
		Time Birth;  // thoi gian cho ngay
		sTime sBirth; // thoi gian cho gio
		string Home=""; // getline
		string Disnation=""; // getline
		// co them hai bien chuyen thoi gian ve s de tinh toan sap xep
		ll RealTime=0;
		ll sRealTime=0;
	public:
		void updateTime(){
			RealTime=Birth.getYear()*31556926+Birth.getDay()*86400+Birth.getMonth()*2592000;
			sRealTime=sBirth.getHour()*3600+sBirth.getMinute()*60;
		}
		ll getRealTime() const { return RealTime;}
		ll getsRealTime() const { return sRealTime;}
		string getIDfly() const { return ID_fly; }
		string getHome() const { return Home; }
		string getDisnation() const { return Disnation; }
		TimeStruct getBirth(){
			TimeStruct b;
			b.day=Birth.getDay();
			b.month=Birth.getMonth();
			b.year=Birth.getYear();
			return b;
		}
		void fly_in();
		void fly_out();
		bool C_ID_fly();
		bool C_Time();
		bool trip();
		bool Accept();
};
// Check in-put
bool fly::C_ID_fly(){
	if(ID_fly.size()<=5) return true;
	return false;
}
bool fly::C_Time(){
	if(Birth.Accept()==1 && sBirth.Accept()==1) return true;
	return false;
}
bool check(string s){ // ko co chu so va ky tu dat biet
	for(int i=0;i<s.size();i++){
		if((s[i]>='A' && s[i]<='Z') || (s[i]>='a' && s[i]<='z') || s[i]==' ') continue;
			else return false;
	}
	return true;
}
bool fly::trip(){
	if(check(Home)==1 && check(Disnation)==1) return true;
	return false;
}
bool fly::Accept(){
//		bool C_ID_fly();
//		bool C_Time();
//		bool trip();
	if (!C_ID_fly()) {
	    cout << "WRONG TYPE IN_ID!!!" << endl;
	    return false;
	}
	if (!C_Time()) {
	    cout << "WRONG TYPE IN_Time!!!" << endl;
	    return false;
	}
	if (!trip()) {
	    cout << "WRONG TYPE IN_Trip!!!" << endl;
	    return false;
	}
	return true;

}
//Tim kiem theo yeu cau
bool Compare_Name(string s1, string s2){
	//1: Thoa man
	//0:khong thoa man
	// x la thu tu giong nhau day tien cua xau 1 voi xau 2
	// substr(x,m) // m la so luong can lay
	ll n=s1.size();
	ll m=s2.size();
	if(s1<s2) return 0;
		else if(s1==s2 && n==m) return true;
			else{
				string s3="";
				for(int i=0;i<n;i++){
					if(s1[i]==s2[0]){
						if(i+m<=n){
							s3=s1.substr(i,m);
							if(s3==s2) return true;
							}
						}
					}
					return false;
				}
}
void Search_ID(fly Member[],ll quantity, string s){
	ll index=0;
	for(int i=0;i<quantity;i++){
		if(Compare_Name(Member[i].getIDfly(),s)==1){
			Member[i].fly_out();
			index++;
		}
	}
	if(index==0) cout<<"DON'T HAVE INFOMATION"<<flush;
}
void Search_Home(fly Member[],ll quantity, string s){
	ll index=0;
	for(int i=0;i<quantity;i++){
		if(Compare_Name(Member[i].getHome(),s)==1){
			Member[i].fly_out();
			index++;
		}
	}
	if(index==0) cout<<"DON'T HAVE INFOMATION"<<flush;
}
void Search_Disnation(fly Member[],ll quantity, string s){
	ll index=0;
	for(int i=0;i<quantity;i++){
		if(Compare_Name(Member[i].getDisnation(),s)==1){
			Member[i].fly_out();
			index++;
		}
	}
	if(index==0) cout<<"DON'T HAVE INFOMATION"<<flush;
}
// Sap xep theo thoi gian
bool cmp(fly a, fly b){
	if(a.getRealTime()==b.getRealTime()) return a.getsRealTime()<=b.getsRealTime();
	return (a.getRealTime()<b.getRealTime());                                     
}
void Sort_time(fly Member[], ll quantity){
	for(int i=0;i<quantity;i++){
		Member[i].updateTime();
	}
	sort(Member,Member+quantity,cmp);
	for(int i=0;i<quantity;i++){
		Member[i].fly_out();
	}
}
// Tim kiem theo yeu cau
bool Compare_time(Time a, fly c){
	TimeStruct b=c.getBirth();
	if(a.getDay()==b.day && a.getMonth()==b.month && a.getYear()==b.year) return true;
	return false;
}
void Search_Home_Time(fly Member[],ll quantity){
	string local;
	
	cout<<"Search Home: "<<flush;
	getline(cin,local);
	
	Time x;
	cout<<"Search Time (day/month/year): "<<flush;
	x.in();
	for(int i=0;i<quantity;i++){
		if(local==Member[i].getHome()){
			if(Compare_time(x,Member[i])==1) Member[i].fly_out();
		}
	}
}
void Search_Home_Disnation(fly Member[],ll quantity){
	ll Dem=0;
	
	string local_first;
	cout<<"Search local first: "<<flush;
	getline(cin,local_first);
	
	string local_second;
	cout<<"Search local second: "<<flush;
	getline(cin,local_second);
	
	for(int i=0;i<quantity;i++){
		if(local_first==Member[i].getHome()){
			if(local_second==Member[i].getDisnation()) Dem++;
		}
	}
	cout<<"Member in "<<local_first<<" to "<<"local second is "<<flush;
	cout<<Dem<<endl;
}
// Input Out_put
void fly::fly_in(){
    bool valid = false;
    while (!valid) { // Ch? ti?p t?c n?u nh?p sai
        cout<<"IN_fly: "<<flush;
        getline(cin, ID_fly);

        cout<<"IN_time_in (day/month/year): "<<flush;
        Birth.in();
        cout<<"IN_hour_in (hour/minute): "<<flush;
        sBirth.in();
        cin.ignore();

        cout<<"IN_Home: "<<flush;
        getline(cin, Home);

        cout<<"IN_Disnation: "<<flush;
        getline(cin, Disnation);

        if(Accept()) {
            valid = true;
        } 
    }
}
void fly::fly_out(){
	cout<<endl;
	cout<<ID_fly<<endl;
	cout<<Birth.getDay()<<"/"<<Birth.getMonth()<<"/"<<Birth.getYear()<<endl;
	cout<<sBirth.getHour()<<":"<<sBirth.getMinute()<<endl;
	cout<<Home<<" to "<<Disnation<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll quantity;
	cin>>quantity; cin.ignore();
	fly *Member=new fly[quantity];
	for(int i=0;i<quantity;i++) Member[i].fly_in();
	// xuat ra danh sach sap xep theo gio khoi hanh
	cout<<"List fly with time: "<<endl;
	Sort_time(Member, quantity);
	// Tim kiem chuyen bay theo ma
	while(1){
		string in_put;
		cout<<"SEARCH ID (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else if(Again=='Y'){
				cout<<"In_ID: "<<flush;
				cin.ignore(); 
				getline(cin,in_put);
				Search_ID(Member,quantity,in_put);
			}
	}
	while(1){
		string in_put;
		cout<<"SEARCH Home (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else if(Again=='Y'){
				cout<<"In_Home: "<<flush;
				cin.ignore(); 
				getline(cin,in_put);
				Search_Home(Member,quantity,in_put);
			}
				else break;
	}
	while(1){
		string in_put;
		cout<<"SEARCH Disnation (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else if(Again=='Y'){
				cout<<"In_Disnation: "<<flush;
				cin.ignore(); 
				getline(cin,in_put);
				Search_Disnation(Member,quantity,in_put);
			}
				else break;
	}
	while(1){
		string in_put;
		cout<<"Search_Home_Time (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else if(Again=='Y'){
				cin.ignore(); 
				Search_Home_Time(Member,quantity);
			}
				else break;
	}
	while(1){
		string in_put;
		cout<<"Search_Home_to_Disnation (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else{
				cin.ignore(); 
				Search_Home_Disnation(Member,quantity);
			}
	}
	return 0;
}
