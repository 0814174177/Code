#include<bits/stdc++.h>
#define ll long long
#define MOD 100005+5
using namespace std;
class list_student{
	private:
		string Name;
		double Maths;
		double Language;
		double English;
	public:
	// get & set	
		double getMaths() const{
			return Maths;
		}
		double getLanguage() const{
			return Language;
		}
		double getEnglish() const{
			return English;			
		}
		string getName() const{
			return Name;
		}
		void setMaths(double m) {
        	Maths = m;
 	    }
    	void setLanguage(double l) {
        	Language = l;
    	}
    	void setEnglish(double e) {
       		English = e;
    	}	
		//constructor
		list_student(){ Maths=0; Language=0; English=0; }
		list_student(double x, double y, double z){
			this->Maths=x;
			this->Language=y;
			this->English=z;
		}
		//nhap
		void in();
		// kiem tra du lieu dau vao
		bool C_Name(); // check ten
		bool Number();
		//tinh diem trung binh
		double Average(){
			return double(2*Maths+Language+English)/4;
		}
		ll Rank_student();	
		// xuat
		void out_Average();
		void out_info();
};
// Nhap_Xuat
void list_student::in(){
	while(1){
		cout << "In_Name: "<<flush;
		getline(cin,Name);
		cout << "In_Maths_Language_English: "<<flush;
		if(!(cin>>Maths>>Language>>English)){
			cin.clear();
			cout<<"WRITE AGAIN, INPUT HAVE PROBLEM !!!"<<flush;
			continue;
		}
		cin.ignore();
		if(C_Name()==1 && Number()==1) return;
		cout<<"WRITE AGAIN, INPUT HAVE PROBLEM !!!"<<flush;
	}
}
void list_student::out_info(){
	cout<<Name<<endl;
	cout<<Maths<<" "<<Language<<" "<<English<<endl;
}
void list_student::out_Average(){
	string quality;
	if(Rank_student()==0) quality="YEU";
	if(Rank_student()==1) quality="TB";
	if(Rank_student()==2) quality="KHA";
	if(Rank_student()==3) quality="GIOI";
	if(Rank_student()==4) quality="XS";
	cout<<Name<<" "<<endl;
	cout<<"Average: "<<Average()<<endl;
	cout<<quality<<endl;
}
//Check_Data_in
bool list_student::C_Name(){
	for(int i=0;i<Name.size();i++){
		if((Name[i]>='a' && Name[i]<='z') || (Name[i]>='A' && Name[i]<='Z') || Name[i]==' ') continue;
			else return false; 
	}
	return true;
}
bool list_student::Number(){
	if(Maths<0 || Maths>10) return false;
	if(Language<0 || Language>10) return false;
	if(English<0 || English>10) return false;
	return true;
}
//Rank_Student
ll list_student::Rank_student(){
		// Gia dinh
		// 0: Yeu <5
		// 1: 	5<= TB <6.5
		//2:  6.5<= Kha < 8
		//3: 8<= Gioi <9
		// 4: <=9 XS<=10
	if (Average() < 5) {
        return 0;
    }
    if (Average() >= 5 && Average() < 6.5) {
        return 1;
    }
    if (Average() >= 6.5 && Average() < 8) {
        return 2;
    }
    if (Average() >= 8 && Average() < 9) {
        return 3;
    }
    if (Average() >= 9 && Average() <= 10) {
        return 4;
    }
    return -1;
}
// sap xep
bool cmp_sort_rank(list_student a, list_student b){
	return (a.Average()<=b.Average());
}
void Sort_rank(list_student Member[],ll quatity){
	sort(Member,Member+quatity,cmp_sort_rank);
}
bool cmp_sort_Manths(list_student a, list_student b){
	return (a.getMaths()<=b.getMaths());
}
void Sort_Manths(list_student Member[],ll quatity){
	sort(Member,Member+quatity,cmp_sort_Manths);
}
// Max_Average
void Assign(list_student &a, list_student b) {
    a.setMaths(b.getMaths());
    a.setLanguage(b.getLanguage());
    a.setEnglish(b.getEnglish());
}
void Top_Average(list_student Member[], ll quatity){
	list_student x(0,0,0);
	ll check=0;
	for(int i=0;i<quatity;i++){
		if(x.Average()<=Member[i].Average()){
			Assign(x,Member[i]);
			check=i;
		}
	}
	cout<<Member[check].getName()<<" ";
	cout<<"Max_Average: "<<Member[check].Average()<<endl;
}
//Search_Name
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
void Search_name(list_student Member[],ll quatity, string s){
	ll soluong=0;
	for(int i=0;i<quatity;i++){
		if(Compare_Name(Member[i].getName(),s)==1){
			soluong++;
			cout<<Member[i].getName()<<endl;
		}
	}
	if(soluong==0){
		cout<<"Don't have NAME "<<flush;
	}
}
//Min_Maths
void Search_Bot_Maths(list_student Member[],ll quatity){
	double mi=11.0;
	stack <ll> q;
	for(int i=0;i<quatity;i++){
		if(Member[i].getMaths()<mi){
			mi=Member[i].getMaths();
			q.push(i);
		}
	}
	cout<<"Min_Maths: "<<endl;
	while(Member[q.top()].getMaths()==mi){
		ll check=q.top();
		q.pop();
		cout<<Member[check].getName()<<" "<<flush;
		cout<<Member[check].getMaths()<<endl;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	ll quatity=3;
	list_student *Member=new list_student[quatity];
	for(int i=0;i<quatity;i++){
		Member[i].in();
	}
	
	for(int i=0;i<quatity;i++){
		Member[i].out_Average();
	}
	
	Top_Average(Member,quatity);
	while(1){
		string in_put;
		cout<<"SEARCH NAME (Y/N): "<<flush;
		char Again;  cin>>Again;
		if(Again=='N') break;
			else{
				cout<<"In_Name "<<flush;
				cin.ignore(); 
				getline(cin,in_put);
				Search_name(Member,quatity,in_put);
			}
	}
	Search_Bot_Maths(Member,quatity);
	return 0;
}
