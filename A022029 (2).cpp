#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){


    int i,j,a=0,z,n,x,temp,flag,u;
    int s[10010],arr[10010];
    cin>>z;
    bool remind[10010][102];
    int p,c;
    while(a++<z){

    cin>>n>>x;

    for(i=1;i<=n;i++){

      cin>>arr[i];

       if(arr[i]<0)arr[i] *=-1;
    }

    for(i=0;i<=x;i++)
       for(j=0;j<102;j++)
        remind[i][j]=false;


    remind[1][arr[1]%x]=true;

    for(i=2;i<=n;i++){



        for(j=0;j<x;j++){

        if(remind[i-1][j]){

          u = arr[i] % x;

          remind[i][(j-u+x)%x] =true;
           remind [i][(j+u)%x] =true;



        }


        }

    }

    if(remind[n][0]==true)cout<<"Divisible"<<endl;
        else { cout<<"Not divisible"<<endl;}



    }

    return 0;

}
