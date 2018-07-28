#include <stdio.h>
#include <string>
#include  <iostream>
#include <string.h>
#include <stdio.h>
using namespace std;


int main(){

    char str[1000][1000];
    char temp[1000];
    char a[1000],b[1000];
	
    int n,j,t;

    while(cin>>n){

	int i=0;
    if(n==0) break;
  	while(i<n) {
  	scanf("%s",str[i]);i++;}
    

    for(i=n;i>0;i--)
        for(j=0;j<i-1;j++){

        a[0]='\0';
        b[0]='\0';
		strcat(a,str[j]);strcat(a,str[j+1]);
        strcat(b,str[j+1]);strcat(b,str[j]);
		if(strcmp(a,b)<0){
           
		    strcpy(temp,str[j+1]);
            strcpy(str[j+1],str[j]);
            strcpy(str[j],temp);

        }

        }

    for(i=0;i<n;i++) {
    	printf("%s",str[i]);
		if(i==n-1) printf("\n");}
	
    }

    return 0;

}

