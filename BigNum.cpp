#include "BigNum.h"
#include <string.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
char* add(char a[256],char b[256]);
char* cutt(char w[256],char ww[256],char temp[256]);
char* mutiply(char u[256],char uu[256],char temp[256]);
bool compare(char* a, char* b);

BigNum::BigNum(){

	strcpy(val,"");
}

BigNum::BigNum(const Number &v){

	strcpy(val,v.val);

}

BigNum::BigNum(const char *ptr){

	strcpy(val,ptr);

}

const Number &BigNum::operator= (const Number &v){

	strcpy(val,v.val);
	return *this;
}

const Number &BigNum::operator= (const BigNum &v){

	strcpy(val,v.val);

	return *this;



}

const Number &BigNum::operator+ (const Number &v){

	static BigNum Big;
	char temp[256],temp1[256],temp2[256],carry=0;
	int i,m,a,b;
	for(i=0;i<256;i++){temp[i]=0;temp1[i]=0;temp2[i]=0;}
	strcpy(temp1,val);
	strcpy(temp2,v.val);
	a=strlen(temp1);
	b=strlen(temp2);
	if(!strcmp(temp1,"0")&&!strcmp(temp2,"0")){temp[0]='0';strcpy(Big.val,temp);return Big;}
	m=max(strlen(temp1),strlen(temp2));

	reverse(temp1,temp1+strlen(temp1));
	reverse(temp2,temp2+strlen(temp2));

	for(i=0;i<a;i++)temp1[i]-=48;
	for(i=0;i<b;i++)temp2[i]-=48;




	for(i=0;i<m;i++){

	temp[i]=((carry+temp1[i]+temp2[i])%10)+48;

	carry =(temp1[i]+temp2[i]+carry)/10;


	}

	if(carry!=0)temp[i]=48+carry;
	reverse(temp,temp+strlen(temp));

	strcpy(Big.val,temp);
	return Big;

}

const Number &BigNum::operator- (const Number &v){

	static BigNum Big;

	char temp[256],a[256],b[256],carry=0;

	int i,m,x,y,j;
	for(i=0;i<256;i++){
			temp[i]=0;
			a[i]=0;
			b[i]=0;}
	strcpy(a,val);
	strcpy(b,v.val);
	if((!strcmp(a,"0")&&!strcmp(b,"0"))||!strcmp(a,b)){temp[0]='0';strcpy(Big.val,temp);return Big;}
	m=max(strlen(a),strlen(b));
	x=strlen(a);
	y=strlen(b);
	reverse(a,a+x);
	reverse(b,b+y);

	for(i=0;i<x;i++)a[i]-=48;
	for(i=0;i<y;i++)b[i]-=48;

	for(i=0;i<m;i++){

		temp[i]=a[i]-b[i];

		if(temp[i]<0){
		temp[i]+=10;
		a[i+1]-=1;

		}

	j=255;


	}
	while(temp[j]==0)j--;

	j++;
	reverse(temp,temp+j);
	for(i=0;i<j;i++)temp[i]+=48;

	strcpy(Big.val,temp);

	return Big;

}

const Number &BigNum::operator* (const Number &v){

	static BigNum Big;
	char temp[256],a[256],b[256],carry=0;
	int arr[500];
	int i,m,x,y,j,z;

	for(i=0;i<500;i++)arr[i]=0;
	for(i=0;i<256;i++){
			temp[i]=0;
			a[i]=0;
			b[i]=0;}
	strcpy(a,val);
	strcpy(b,v.val);
	if(!strcmp(a,"0")||!strcmp(b,"0")){temp[0]='0';strcpy(Big.val,temp);return Big;}


	// 這邊要改喔喔喔喔!!!!!!!!!
	x=strlen(a);
	y=strlen(b);
	reverse(a,a+x);
	reverse(b,b+y);

	for(i=0;i<x;i++)a[i]-=48;
	for(i=0;i<y;i++)b[i]-=48;



	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
	arr[i+j] += a[i]*b[j];

	z=x+y;
	for(i=0;i<z;i++){



	arr[i+1]+=arr[i]/10;

	arr[i]%=10;


	}

	j=255;
	while(arr[j]==0)j--;

	j++;
	for(i=0;i<j;i++)temp[i]=arr[j-1-i]+48;

	strcpy(Big.val,temp);

	return Big;


}

const Number &BigNum::operator/ (const Number &v){

	static BigNum Big;
	string a;

	char temp[256],b[256],t[256],mul[256],cut[256],transfer[256],carry=0;
	char* ptr ;
	int arr[500];
	int i,m,x,y,j,z,len,k,flag;


	for(i=0;i<500;i++)arr[i]=0;
	for(i=0;i<256;i++){
			temp[i]=0;
			b[i]=0;
			}

	a.erase(0,256);

	strcpy(transfer,val);

	a=transfer;

	a.insert(0,"0");

	strcpy(b,v.val);

	x=a.size();
	y=strlen(b);

	len=strlen(b)+1;
	char sub[256];

	for(j=0;j<x-y;j++){  //淦這邊問題超大

	flag=0;
	for(k=0;a[k]!=NULL;k++)
		if(a[k]!='0')flag=1;

	if(flag==0){temp[j]='0';}

	memset( t , 0 , sizeof( t ) );
	memset( sub , 0 , sizeof( sub ) );
	for(i=0;i<len;i++){
			sub[i]=a[i+j];
			}


	for(i=9;i>=0;i--){
	t[0]=i+48;

	 ptr=sub;
	//int flag=0;
	while(*ptr=='0')ptr++;

	mutiply(b,t,mul);

	if(strlen(ptr)<strlen(mul)){continue;}
	if(!(strlen(ptr)>strlen(mul)))
	if(strcmp(mul,ptr)>0){continue;}



	cutt(sub,mul,cut);
	strcpy(sub,cut);
	temp[j]=i+48;

	a.erase(0,len+j);
	a.insert(0,sub);		// sub2要把0補回去
	while(a.size()<x)
		a.insert(0,"0");

	k=0;
	break;


	}

	}
	k=0;
	ptr=temp;
	while(*ptr=='0')
		ptr++;
	strcpy(temp,ptr);


	strcpy(Big.val,temp);

	return Big;

}


char* cutt(char w[256],char ww[256],char temp[256]){


	char a[256],b[256],carry=0;

	int i,m,x,y,j;
	for(i=0;i<256;i++){
			temp[i]=0;
			a[i]=0;
			b[i]=0;}
	strcpy(a,w);
	strcpy(b,ww);
	if((!strcmp(a,"0")&&!strcmp(b,"0"))||!strcmp(a,b))
		{
		temp[0]='0';

		return temp;
		}
	m=max(strlen(a),strlen(b));
	x=strlen(a);
	y=strlen(b);
	reverse(a,a+x);
	reverse(b,b+y);

	for(i=0;i<x;i++)a[i]-=48;
	for(i=0;i<y;i++)b[i]-=48;

	for(i=0;i<m;i++){

		temp[i]=a[i]-b[i];

		if(temp[i]<0){
		temp[i]+=10;
		a[i+1]-=1;

		}

	j=255;


	}
	while(temp[j]==0)j--;

	j++;
	reverse(temp,temp+j);
	for(i=0;i<j;i++)temp[i]+=48;


}

char* mutiply(char u[256],char uu[256],char temp[256]){

	char a[256],b[256],carry=0;
	int arr[500];
	int i,m,x,y,j,z;



	for(i=0;i<500;i++)arr[i]=0;
	for(i=0;i<256;i++){
			temp[i]=0;
			a[i]=0;
			b[i]=0;}
	strcpy(a,u);
	strcpy(b,uu);
	//cin>>a;
	//cin>>b;
	if(!strcmp(a,"0")||!strcmp(b,"0")){temp[0]='0';return temp;}// 這邊要改喔喔喔喔!!!!!!!!!
	x=strlen(a);
	y=strlen(b);
	reverse(a,a+x);
	reverse(b,b+y);

	for(i=0;i<x;i++)a[i]-=48;
	for(i=0;i<y;i++)b[i]-=48;



	for(i=0;i<x;i++)
		for(j=0;j<y;j++)
	arr[i+j] += a[i]*b[j];

	z=x+y;
	for(i=0;i<z;i++){



	arr[i+1]+=arr[i]/10;

	arr[i]%=10;


	}

	j=255;
	while(arr[j]==0)j--;

	j++;
	for(i=0;i<j;i++)temp[i]=arr[j-1-i]+48;

	return temp;
}




