#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

int extode(string num){
	int a;
	int nnum;
	int t;
	for(int i=0;i<num.length();i++){
		if(num[i]>='0'&&num[i]<='9') t=num[i]-48;
		else if (num[i]>='A'&&num[i]<='F') t=num[i]-55;
		else if (num[i]>='a'&&num[i]<='f') t=num[i]-87;
		else cout<<"Inserisci un numero valido"<<endl;
		nnum+=(t*(pow(16,num.length()-1-i)));
	}
	return nnum;
}
string detobi(int num){
	string nnum="";
	int t;
	while(num>0){
		t=num%2;
		stringstream ss;
		ss<<t;
		nnum=ss.str()+nnum;
		num=num/2;
	}
	return nnum;
}
string detoex(int num){
	string nnum="";
	int t;
	while(num>0){
		t=num%16;
		 stringstream ss;
		if(t>=0&&t<10){
	       ss<<t;	
		}
		else{
		  char a=t+55;
		  ss<<a;	
		}
	
		nnum=ss.str()+nnum;
		num=num/16;
	}
	return nnum;
}
int bitode(string num){
	int nnum;
	for(int i=0;i<num.length();i++){
		int t=num[i]-48;
		nnum+=t*(pow(2,num.length()-1-i));
	}
	return nnum;
}
string deton(int num,int bf){
	string nnum="";
	int t;
	while(num>0){
		t=num%bf;
		stringstream ss;
		if(t>=0&&t<10){
	       ss<<t;	
		}
		else{
		  char a=t+55;
		  ss<<a;	
		}
	
		nnum=ss.str()+nnum;
		num=num/bf;
	}
	return nnum;
}
int ntode(string num,int bp){
		int nnum;
	int t;
	for(int i=0;i<num.length();i++){
		if(num[i]>='0'&&num[i]<='9') t=num[i]-48;
		else if (num[i]>='A'&&num[i]<='Z') t=num[i]-55;
		else if (num[i]>='a'&&num[i]<='z') t=num[i]-87;
		else cout<<"Inserisci un numero valido"<<endl;
		nnum+=(t*(pow(bp,num.length()-1-i)));
	}
	return nnum;
}

int main(){
while(true){

  cout<<"Inserisci base di partenza e base che vuoi ottenere"<<endl;
  int bp,bf;
  cin>>bp;
  cin>>bf;
  while((bp<2||bp>36)||(bf<2||bf>36)) {
  	cout<<"Inserisci basi valide"<<endl;
  	cin>>bp;
  	cin>>bf;
  }
  if(bp==2&&bf==10){
  	cout<<"Inserisci numero"<<endl;
  	string n;
  	cin>>n;
  	cout<<"Il numero convertito in decimale e' : "<<bitode(n)<<endl;
  }
  else if(bp==2&&bf==16){
  	cout<<"Inserisci numero"<<endl;
  	string n;
  	cin>>n;
  	int m=bitode(n);
  	cout<<"Il numero convertito in esadecimale e' : "<<detoex(m)<<endl;
  }
  else if(bp==10&&bf==2){
  	int n;
  	cout<<"Inserisci numero"<<endl;
  	cin>>n;
  	cout<<"Il numero convertito in binario e': "<<detobi(n)<<endl;
  }
  else if(bp==10&&bf==16){
  	int n;
  	cout<<"Inserisci numero"<<endl;
  	cin>>n;
  	cout<<"Il numero convertito in esadecimale e': "<<detoex(n)<<endl;
  }
  else if(bp==16&&bf==2){
  	cout<<"Inserisci numero"<<endl;
  	string n;
  	cin>>n;
  	int m=extode(n);
  	cout<<"Il numero convertito in binario e' : "<<detobi(m)<<endl;
  }
  else if(bp==16&&bf==10){
  	cout<<"Inserisci numero"<<endl;
  	string n;
  	cin>>n;
  	cout<<"Il numero convertito in decimale e' : "<<extode(n)<<endl;
  }
  else if(bp==10){
  	cout<<"Inserisci numero"<<endl;
  	int n;
  	cin>>n;
  	cout<<"Il numero convertito in base "<<bf<<" e' : "<<deton(n,bf)<<endl;
  }
  else if(bf==10){
  	cout<<"Inserisci numero"<<endl;
  	string n;
  	cin>>n;
  	cout<<"Il numero convertito in decimale e' : "<<ntode(n,bp)<<endl;
  }
  else{
  	cout<<"Inserisci numero"<<endl;
  	string n;
  	cin>>n;
  	int m=ntode(n,bp);
  	cout<<"Il numero convertito in base "<<bf<<" e' : "<<deton(m,bf)<<endl;
  }
}
}