#include<iostream>
using namespace std;

void multiply(string);
string form(string);

// input: 0+ such as 00000
int main(){
	string s,sf;
	cin>>s;
	sf=form(s);
	multiply(sf);
};

string form(string s){
	string sf='<'+s+"______________________________________________________________________________________________________________________________________________________________";
	short status=0;
	short point=0;
	while(1){
		if(status==0&&sf[point]=='<'){
			status=1;
			sf[point]='<';
			point++;
		}
		else if(status==1&&sf[point]=='0'){
			status=1;
			sf[point]='0';
			point++;
		}
		else if(status==1&&sf[point]=='_'){
			status=2;
			sf[point]='1';
			point--;
		}
		else if(status==2&&sf[point]=='0'){
			status=2;
			sf[point]='0';
			point--;
		}
		else if(status==2&&sf[point]=='<'){
			status=3;
			sf[point]='<';
			point++;
		}
		else if(status==3&&sf[point]=='0'){
			status=4;
			sf[point]='2';
			point++;
		}
		else if(status==4&&sf[point]=='0'){
			status=4;
			sf[point]='0';
			point++;
		}
		else if(status==4&&sf[point]=='1'){
			status=4;
			sf[point]='1';
			point++;
		}
		else if(status==4&&sf[point]=='_'){
			status=5;
			sf[point]='0';
			point--;
		}
		else if(status==5&&sf[point]=='1'){
			status=5;
			sf[point]='1';
			point--;
		}
		else if(status==5&&sf[point]=='0'){
			status=5;
			sf[point]='0';
			point--;
		}
		else if(status==5&&sf[point]=='2'){
			status=3;
			sf[point]='2';
			point++;
		}
		else if(status==3&&sf[point]=='1'){
			status=6;
			sf[point]='1';
			point--;
		}
		else if(status==6&&sf[point]=='2'){
			status=6;
			sf[point]='0';
			point--;
		}
		else if(status==6&&sf[point]=='<'){
			status=7;
			sf[point]='<';
			return sf;
		}
	}
}

void multiply(string s){
	short status=-1;
	short point=0;
	int times=0;
	while(1){
		if(status==1&&s[point]=='0'){//left end
			status=2;
			s[point]='2';
			point++;
		}
		else if(status==2&&s[point]=='0'){
			status=2;
			s[point]='0';
			point++;
		}
		else if(status==2&&s[point]=='1'){
			status=2;
			s[point]='1';
			point++;
		}
		else if(status==2&&s[point]=='_'){
			status=3;
			s[point]='0';
			point--;
		}
		else if(status==3&&s[point]=='0'){
			status=3;
			s[point]='0';
			point--;
		}
		else if(status==3&&s[point]=='1'){
			status=3;
			s[point]='1';
			point--;
		}
		else if(status==3&&s[point]=='2'){
			status=1;
			s[point]='2';
			point++;
		}
		else if(status==1&&s[point]=='1'){
			status=4;
			s[point]='1';
			point--;
		}
		else if(status==4&&s[point]=='2'){
			status=4;
			s[point]='0';
			point--;
		}
		else if(status==4&&s[point]=='1'){
			status=5;
			s[point]='1';
			point++;
		}
		else if(status==-1&&s[point]=='<'){
			status=0;
			s[point]='<';
			point++;
		}
		else if(status==0&&s[point]=='0'){
			status=6;
			s[point]='_';
			point++;
		}
		else if(status==6&&s[point]=='0'){
			status=6;
			s[point]='0';
			point++;
		}
		else if(status==6&&s[point]=='1'){
			status=13;
			s[point]='1';
			point++;
		}
		else if(status==13&&s[point]=='0'){
			status=13;
			s[point]='0';
			point++;
		}
		else if(status==13&&s[point]=='_'){
			status=14;
			s[point]='1';
			point--;
		}
		else if(status==14&&s[point]=='0'){
			status=14;
			s[point]='0';
			point--;
		}
		else if(status==14&&s[point]=='1'){
			status=1;
			s[point]='1';
			point++;
		}
		else if(status==13&&s[point]=='1'){
			status=14;
			s[point]='1';
			point--;
		}
		else if(status==5&&s[point]=='0'){
			status=7;
			s[point]='0';
			point--;
		}
		else if(status==7&&s[point]=='1'){
			status=8;
			s[point]='1';
			point--;
		}
		else if(status==8&&s[point]=='0'){
			status=9;
			s[point]='0';
			point--;
		}
		else if(status==9&&s[point]=='0'){
			status=9;
			s[point]='0';
			point--;
		}
		else if(status==9&&s[point]=='_'){
			status=0;
			s[point]='_';
			point++;
		}
		else if(status==8&&s[point]=='_'){
			status=10;
			s[point]='_';
			point++;
		}
		else if(status==10&&s[point]=='1'){
			status=11;
			s[point]='_';
			point++;
		}
		else if(status==11&&s[point]=='0'){
			status=11;
			s[point]='_';
			point++;
		}
		else if(status==11&&s[point]=='1'){
			status=12;
			s[point]='_';
			cout<<s;
			return;
		}
	}
}

