#include<iostream>
using namespace std;
int main(){
	string s;
	while(getline(cin,s)&&s.compare("ENDOFINPUT")!=0){
		if(s.compare("START")!=0&&s.compare("END")!=0){
			for(unsigned i=0;i<s.length();i++){
				if(s[i]>='A'&&s[i]<='E'){
					s[i]+=21;
				}
				else if(s[i]>='E'&&s[i]<='Z'){
					s[i]-=5;
				}
				cout<<s[i]; 
			}	
		}
	}
	return 0;
}
