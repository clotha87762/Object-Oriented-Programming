#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int abs(int x){ if (x>0)return x; else {return (x*(-1));}}

int main(){

	char  s[1010];
	int x[2000] ;

	cin >> s ;
	while(s!=NULL){

		//cout << "test" ;
		if (!strcmp(s,"0"))break;

		int i,a=0,b=0;
		for(i=0;i<2000;i++)x[i]=0;

		for(i=0;i<strlen(s);i++){

			x[i]= ( s[strlen(s)-i-1] - 48 );
		}

		for(i=0;i<strlen(s);i++){

		if((i+1)%2==0){
			b+=x[i];
			}
			else
			{a+=x[i];}

		}

		if((abs(a-b))%11==0){
			cout << s << " is a multiple of 11." <<endl;
		}
		else{
			cout << s << " is not a multiple of 11." <<endl ;
		}

		cin >> s ;
	}


	return 0 ;


}
