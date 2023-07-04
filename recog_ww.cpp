#include<iostream>
using namespace std;

bool turing(string);

// input: S(0|1)*B such as S00110011B
int main(){
	string s;
	cin>>s;
	bool b=turing(s);
	if(b==0) cout<<"reject";
	if(b==1) cout<<"accept";
};

bool turing(string s){
	short status=0;
	short point=0;
	while(1){
		if(status==0&&s[point]=='S'){//left end char
			status=1;
			s[point]='S';
			point++;
		}
		else if(status==1&&s[point]=='B'){
			status=11;
			return 1; 
		}
		else if(status==1&&s[point]=='1'){
			status=2;
			s[point]='a';
			point++;
		}
		else if(status==1&&s[point]=='0'){
			status=2;
			s[point]='c';
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
		else if(status==2&&s[point]=='b'){
			status=3;
			s[point]='b';
			point--;
		}
		else if(status==2&&s[point]=='d'){
			status=3;
			s[point]='d';
			point--;
		}
		else if(status==2&&s[point]=='B'){
			status=3;
			s[point]='B';
			point--;
		}
		else if(status==3&&s[point]=='1'){
			status=4;
			s[point]='b';
			point--;
		}
		else if(status==3&&s[point]=='0'){
			status=4;
			s[point]='d';
			point--;
		}
		else if(status==4&&s[point]=='0'){
			status=4;
			s[point]='0';
			point--;
		}
		else if(status==4&&s[point]=='1'){
			status=4;
			s[point]='1';
			point--;
		}
		else if(status==4&&s[point]=='a'){
			status=1;
			s[point]='a';
			point++;
		}
		else if(status==4&&s[point]=='c'){
			status=1;
			s[point]='c';
			point++;
		}
		else if(status==2&&s[point]=='b'){
			status=-1;
			cout<<s;
			return 0;
		}
		else if(status==2&&s[point]=='d'){
			status=-1;
			cout<<s;
			return 0;
		}
		else if(status==1&&s[point]=='b'){//
			status=5;
			s[point]='b';
			point--;
		}
		else if(status==1&&s[point]=='d'){//
			status=5;
			s[point]='d';
			point--;
		}
		else if(status==3&&s[point]=='a'){//
			status=-1;
			return 0;
		}
		else if(status==3&&s[point]=='c'){//
			status=-1;
			return 0;
		}
		else if(status==5&&s[point]=='a'){//
			status=5;
			s[point]='a';
			point--;
		}
		else if(status==5&&s[point]=='c'){//
			status=5;
			s[point]='c';
			point--;
		}
		else if(status==5&&s[point]=='S'){//
			status=6;
			s[point]='S';
			point++;
		}
		else if(status==6&&s[point]=='a'){//left eliminate
			status=7;
			s[point]='_';
			point++;
		}
		else if(status==7&&s[point]=='a'){//
			status=7;
			s[point]='a';
			point++;
		}
		else if(status==7&&s[point]=='c'){//
			status=7;
			s[point]='c';
			point++;
		}
		else if(status==7&&s[point]=='!'){//
			status=7;
			s[point]='!';
			point++;
		}
		else if(status==7&&s[point]=='b'){//right eliminate
			status=8;
			s[point]='!';
			point--;
		}
		else if(status==7&&s[point]=='d'){//fail to match
			status=-1;
			return 0;
		}
		else if(status==8&&s[point]=='a'){//
			status=8;
			s[point]='a';
			point--;
		}
		else if(status==8&&s[point]=='c'){//
			status=8;
			s[point]='c';
			point--;
		}
		else if(status==8&&s[point]=='!'){//
			status=8;
			s[point]='!';
			point--;
		}
		else if(status==8&&s[point]=='_'){//
			status=6;
			s[point]='_';
			point++;
		}
		else if(status==6&&s[point]=='c'){//left eliminate 
			status=9;
			s[point]='_';
			point++;
		}
		else if(status==9&&s[point]=='a'){//
			status=9;
			s[point]='a';
			point++;
		}
		else if(status==9&&s[point]=='c'){//
			status=9;
			s[point]='c';
			point++;
		}
		else if(status==9&&s[point]=='!'){//
			status=9;
			s[point]='!';
			point++;
		}
		else if(status==9&&s[point]=='d'){//right eliminate 
			status=10;
			s[point]='!';
			point--;
		}
		else if(status==9&&s[point]=='b'){//fail to match
			status=-1;
			return 0;
		}
		else if(status==10&&s[point]=='a'){//
			status=10;
			s[point]='a';
			point--;
		}
		else if(status==10&&s[point]=='c'){//
			status=10;
			s[point]='c';
			point--;
		}
		else if(status==10&&s[point]=='!'){//
			status=10;
			s[point]='!';
			point--;
		}
		else if(status==10&&s[point]=='_'){//
			status=6;
			s[point]='_';
			point++;
		}
		else if(status==6&&s[point]=='!'){//
			status=11;
			return 1; 
		}
		else if(status==7&&s[point]=='B'){//
			status=11;
			return 1; 
		}
		else if(status==9&&s[point]=='B'){//
			status=11;
			return 1; 
		}
	}
}
