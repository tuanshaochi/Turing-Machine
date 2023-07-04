#include<iostream>
using namespace std;

bool turing(string);

// input: (0|1)+ such as 00110011
int main(){
	string s;
	cin>>s;
	bool b=turing("<"+s+"_");
	if(b==0) cout<<"reject";
	if(b==1) cout<<"accept";
};

bool turing(string s){
	short status=0;
	short point=0;
	int times=0;
	while(1){
		times++;
		cout<<times;
		cout<<":";
		cout<<s.substr(0,point+1)+"(q";
		cout<<status;
		cout<<")"+s.substr(point+1)<<endl;//output pattern
		if(status==0&&s[point]=='<'){//left end char
			status=0;
			s[point]='<';
			point++;
		}
		else if(status==0&&s[point]=='0'){
			status=1;
			s[point]='X';
			point++;
		}
		else if(status==0&&s[point]=='1'){
			status=5;
			s[point]='1';
			times++;
			cout<<times;
			cout<<":";
			cout<<s.substr(0,point+1)+"(q";
			cout<<status;
			cout<<")"+s.substr(point+1)<<endl;
			return 0;
		}
		else if(status==1&&s[point]=='0'){
			status=1;
			s[point]='0';
			point++;
		}
		else if(status==1&&s[point]=='1'){ 
			status=2;
			s[point]='Y';
			point--;
		}
		else if(status==2&&s[point]=='0'){
			status=2;
			s[point]='0';
			point--;
		}
		else if(status==2&&s[point]=='Y'){
			status=2;
			s[point]='Y';
			point--;
		}
		else if(status==2&&s[point]=='X'){
			status=0;
			s[point]='X';
			point++;
		}
		else if(status==1&&s[point]=='Y'){
			status=1;
			s[point]='Y';
			point++;
		}
		else if(status==0&&s[point]=='Y'){
			status=3;
			s[point]='Y';
			point++;
		}
		else if(status==3&&s[point]=='Y'){
			status=3;
			s[point]='Y';
			point++;
		}
		else if(status==1&&s[point]=='0'){
			status=1;
			s[point]='0';
			point++;
		}
		else if(status==3&&s[point]=='_'){//meet right end and accept
			status=4;
			s[point]='_';
			times++;
			cout<<times;
			cout<<":";
			cout<<s.substr(0,point+1)+"(q";
			cout<<status;
			cout<<")"+s.substr(point+1)<<endl;
			return 1;
		}
		else if(status==3&&s[point]=='1'){//1 is more than 0
			status=5;
			s[point]='1';
			times++;
			cout<<times;
			cout<<":";
			cout<<s.substr(0,point+1)+"(q";
			cout<<status;
			cout<<")"+s.substr(point+1)<<endl;
			return 0;
		}
		else if(status==3&&s[point]=='0'){//there is 0 after 1
			status=5;
			s[point]='0';
			times++;
			cout<<times;
			cout<<":";
			cout<<s.substr(0,point+1)+"(q";
			cout<<status;
			cout<<")"+s.substr(point+1)<<endl;
			return 0;
		}
		else if(status==1&&s[point]=='_'){//0 is more than 1
			status=5;
			s[point]='_';
			times++;
			cout<<times;
			cout<<":";
			cout<<s.substr(0,point+1)+"(q";
			cout<<status;
			cout<<")"+s.substr(point+1)<<endl;
			return 0;
		}
	}
}

