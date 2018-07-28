#include <iostream>
#include <math.h>
#include<stdio.h>
using namespace std;

int main(){

    int i,base,arr[100],temp;
    long long n;

    while(cin>>n){

        if(n<0)return 0;
		cin>>base;

        for(i=0;n>=1;i++){

        arr[i] = n%base;

        n /= base;
 		}
 
 

        temp = i;
        for(i=0;i<temp;i++){

              if(arr[temp-i-1]<=9){
				printf("%d",arr[temp-i-1]);
				}
                else if(arr[temp-i-1]>=10){
				printf("%c",arr[temp-i-1]+55);
				}

        


        }

        cout<<endl;
		

            }

	return 0;
    }




