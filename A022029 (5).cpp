#include <iostream>
#include <stdio.h>

using namespace std;


struct fib{

    int num[1100];

};

typedef struct fib FF;
FF F[5010] ;

int main(){

	
    
    F[0].num[0]=0; 
    F[1].num[0]=1; 
    int i,j,x,temp;
  
    for(i=2;i<5010;i++){

        for(j=0;j<1100;j++){

            F[i].num[j] += F[i-1].num[j] + F[i-2].num[j];
            F[i].num[j+1] += F[i].num[j]/10;
            F[i].num[j] = F[i].num[j]%10;
        }
       	
	}


        while(cin>>x){

            int k;
            for(k=1099;k>0;k--){
                if(F[x].num[k]>0){
                
                temp=k;
                break;
				}
            }
            cout<<"The Fibonacci number for "<<x<<" is ";
            for(k=temp;k>=0;k--)cout<<F[x].num[k];

            printf("\n");
        }

    return 0;
   
    }


