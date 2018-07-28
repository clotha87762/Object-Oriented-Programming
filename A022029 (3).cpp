#include <iostream>
#include<stdio.h>
#include<math.h>
#include<iomanip>
using namespace std;


int main(){


    long long i,j,temp,k,x,a[100];




    while(cin>>x){

        if(x==0)break;
        j=0;
        temp=x;

        for(i=2;i<=x;i++){


           if(x%i==0){
            a[j]=i;
            while(x%i==0){
             x/=i;
            }
            j++;
           }

        }

        //cout<<"aa"<<endl;
       for(i=0;i<j;i++){
            k=a[i];
            temp*=k-1;temp/=k;/*cout<<a[i]<<" "<<temp<<endl;*/}




        if(temp==x)cout<<temp-1<<endl;
        else cout<<temp<<endl;


    }

    return 0;

}
