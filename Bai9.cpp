// ngan han (<6 thang) 
// dai han (>6 thang)
//Khong ky han
#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e5+5;
class Time{
	private:
		ll a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
		ll day;
		ll month;
		ll year;
	public:
		void in(){
			cin>>day>>month>>year;
		}
		// get
		ll getDay() const { return day; }
		ll getMonth() const { return month; }
		ll getYear() const { return year; }
		// set
		void setDay(ll day) { this->day = day; }
		void setMonth(ll month) { this->month = month; }
		void setYear(ll year) { this->year = year; }
		// Check
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
		void out(){
			cout<<day<<"/"<<month<<"/"<<year<<endl;
		}
};
class Save_money{
	private:
		string maso="";
		string type_Save_money=""; 
		string Name="";
		string ID_Card="";
		Time Birth;
		double money;
	public:
		void in();
		void out();
		// get
		string getMaso() const { return maso; }
		string getID_card() const { return ID_Card; }
		string getName() const { return Name; }
		Time getBirth() const {return Birth; }
		double getMoney() const { return money; }
		string getType_Save_money() const { return type_Save_money; }
		// set
		void setMaso(string s) { maso = s; }
		void setID_card(string s) { ID_Card = s; }
		void setName(string s) { Name = s; }
		void setMoney(double x) { money = x; }
		void setType_Save_money(string s) { type_Save_money = s; }
		// Check	
		bool C_maso(); // Done
		bool C_type_Save_money(); // de khong yeu cau
		bool C_Name(); // Done
		bool C_ID_Card(); // Done
		bool C_Birth(); // Done
		bool C_money(); // Done
		bool Accept(); // Done
		// profession
			// nhap vao lai xuat theo phan tram
			// tra ve so tien tuong ung voi so tiet kiem
		double Update_money(double x); 
};
// In_out
void Save_money::in(){
//	string maso;
//	string type_Save_money; 
//	string Name;	
//	string ID_card;
//	Time Birth;
//	double money;
	bool flow=false;
	while(!(flow)){

		cout<<"In_ID: "<<flush;
		cin>>maso;
		
		cout<<"Type_Money (Nganhan/Daihan/Khongkyhan): "<<flush;
		cin>>type_Save_money; 
		
		cin.ignore();
		cout<<"Name: "<<flush;
		getline(cin,Name);
		
		cout<<"In_ID_Card: "<<flush;
		cin>>ID_Card;
		
		cout<<"In_Time (day/month/year): "<<flush;
		Birth.in();
		cout<<"Money: "<<flush;
		cin>>money;
		cin.ignore();
		if(Accept()==1) flow=true;
	}
}
void Save_money::out(){
	//	string maso;
	//	string type_Save_money; 
	//	string Name;	
	//	string ID_card;
	//	Time Birth;
	//	double money;
	cout<<endl;
	cout<<maso<<endl;
	cout<<type_Save_money<<endl;
	cout<<Name<<endl;
	cout<<ID_Card<<endl;
	Birth.out();
	cout<<money<<endl;
}
// Check
bool Save_money::C_Birth(){
	if(Birth.Accept()==1) return true;
	return false;
}
bool Save_money::C_type_Save_money(){ 
	string s1="Nganhan";
	string s2="Daihan";
	string s3="khongkyhan";
	if(type_Save_money.size()<=10){
		if(type_Save_money==s1 || type_Save_money==s2 || type_Save_money==s3) return true;
	} 
	return false;
}
bool Save_money::C_maso(){ // khong co cach
	ll m=maso.size();
	for(int i=0;i<m;i++){
		if(maso[i]>='0' && maso[i]<='9') continue;
			else if(maso[i]>='A' && maso[i]<='Z') continue;
				else if(maso[i]>='a' && maso[i]<='z') continue;
						else return false;
	}
	return true;
}
bool Save_money::C_money(){
	if(money>0) return true;
	return false;
}
bool Save_money::C_ID_Card(){
	if(ID_Card.size()>=9 && ID_Card.size()<=12){
		for(int i=0;i<ID_Card.size();i++) 
			if(ID_Card[i]>='0' && ID_Card[i]<='9') continue;
				else if(ID_Card[i]>='a' && ID_Card[i]<='Z') continue;
					else if(ID_Card[i]>='A' && ID_Card[i]<='Z') continue;
						else return false;		
	}	
	return true;
}
bool Save_money::C_Name(){
	if(Name.size()<=30){
		for(int i=0;i<=Name.size()-1;i++) 
		if((Name[i]>='a' && Name[i]<='z') || (Name[i]>='A' && Name[i]<='Z') || Name[i]==' ') continue;
			else return false;		
	}
	return true;
}
bool Save_money::Accept(){
	if(C_Name()!=1){
		cout<<"Wrong Name: "<<flush;
		return false;
	}
	if(C_ID_Card()!=1){
		cout<<"Wrong ID_Card: "<<flush;
		return false;
	}
	if(C_Birth()!=1){
		cout<<"Wrong day: "<<flush;
		return false;
	}
	if(C_maso()!=1){
		cout<<"Wrong ID: "<<flush;
		return false;
	}
	if(C_money()!=1){
		cout<<"Wrong Money: "<<flush;
		return false;
	}
	if(C_type_Save_money()!=1){
		cout<<"Wrong ID: "<<flush;
		return false;
	}
	return true;
}
		//Search and list
bool Compare_Name(string s1, string s2){
	//1: Thoa man
	//0:khong thoa man
	// x la thu tu giong nhau day tien cua xau 1 voi xau 2
	// substr(x,m) // m la so luong can la
	// s2 la mang nho
	if(s2.size()>s1.size()) swap(s1,s2);
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
void Search_with_ID_Card(Save_money Member[],ll quantity, string s){
	ll index=0;
	for(int i=0;i<quantity;i++){
		if(Compare_Name(s,Member[i].getID_card())==1){
			Member[i].out();
			index++;
		}
	}
	if(index==0) cout<<"Wrong ID Card: "<<endl;
}
void Search_with_maso(Save_money Member[], ll quantity, string s){
	ll index=0;
	for(int i=0;i<quantity;i++){
		if(Compare_Name(s,Member[i].getMaso())==1){
			Member[i].out();
			index++;
		}
	}
	if(index==0) cout<<"Wrong ID: "<<endl;		
}
// liet ke so tiet kiem trong khoang thoi gian xac dinh
bool Before(Time a, Time b){ // kiem tra 2 ngay, xem ngay nao truoc
	// a truoc b thi true
	ll Sumif=3;
	if(a.getYear()<=b.getYear()) Sumif--;
	if(a.getMonth()<=b.getMonth()) Sumif--;
	if(a.getDay()<b.getDay()) Sumif--;
	if(Sumif==0) return true;
	return false;
}
void in_for_time(Save_money Member[], ll quantity){ // xem ai trong khoang thoi gian nay khong
	Time a;
	Time b;
	cout<<"Time_first_check: "<<endl;
	a.in();
	cout<<"Time_second_check: "<<endl;
	b.in();
	ll Number;
	// a<=x && x<=b
	cout<<endl;
	for(int i=0;i<quantity;i++){
		if(Before(a,Member[i].getBirth())==1 && Before(Member[i].getBirth(),b)==1){
			Number++;
			Member[i].out();
		}
	}
	if(Number==0) cout<<"Nobody in this time: "<<endl;
}
// arrange(sapxep)
bool cmp(Save_money a, Save_money b){
	return a.getMoney()<=b.getMoney();
}
void Arrange_money(Save_money Member[], ll quantity){
	sort(Member,Member+quantity,cmp);
	for(int i=0;i<quantity;i++) Member[i].out();
}
bool cmpBirth(Save_money a, Save_money b){
	if(Before(a.getBirth(),b.getBirth())==1) return true;
}
void Arrange_Birth(Save_money Member[], ll quantity){
	sort(Member,Member+quantity,cmpBirth);
	for(int i=0;i<quantity;i++) Member[i].out();
}
int main(){
	ios_base::sync_with_stdio(NULL);
	cin.tie(NULL);
	cout.tie(NULL);
	
//	Cout<<"Today: ";
//	Time Today;
//	Today.in();
	ll quantity;
	cin>>quantity;
	Save_money *Member=new Save_money[quantity];
	for(int i=0;i<quantity;i++) Member[i].in();
	//Tim kiem theo ID_Card
	while(1){
		string in_put;
		cout<<"Search_ID_Card (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else if(Again=='Y'){
				cin.ignore(); 
				getline(cin,in_put); 
				Search_with_ID_Card(Member,quantity,in_put);
			}
	}
	while(1){
		string in_put;
		cout<<"Search ID: (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else{
				cin.ignore();
				getline(cin,in_put); 
				Search_with_maso(Member,quantity,in_put);
			}
	}
	in_for_time(Member,quantity);
	cout<<"Arrange with money: "<<flush;
	Arrange_money(Member,quantity);
	cout<<"Arrange with Time: "<<flush;
	Arrange_Birth(Member,quantity);
	return 0;
}
