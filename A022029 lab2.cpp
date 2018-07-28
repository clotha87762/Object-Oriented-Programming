#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;



int comp (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

int main(){

    int temp,x , i=0, arr[10000] ;
    for(i=0;i<10000;i++)arr[i]=0;

    i=0;
	while( cin >>x ){

      arr[i++]=x;

      qsort(arr,i,sizeof(int),com);
	  if(i%2!=0) cout<<arr[((i+1)/2)-1]<<endl;
        else if (i%2==0) {

				temp = (arr[(i/2)-1]+arr[(i/2)])/2;
                cout << temp << endl;

                }


    }

    return 0;

}

