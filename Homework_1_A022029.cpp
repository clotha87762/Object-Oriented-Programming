#include <iostream>
#include <time.h>
#include <stdlib.h>

using namespace std;

template <class T>
void SortNumber ( T* arr , int x){

	int i,j;
	T temp;


	for(i=0;i<(x-1);i++)
		for (j=0; j<(x-i-1) ;j++){

			if(arr[j]>arr[j+1]) {

				temp = arr[j+1];
				arr[j+1]=arr[j];
				arr[j]=temp;
			}
		}


	for(i=0;i<x;i++){
		cout << arr[i] <<" ";
		if((i+1)%10==0)cout <<endl;
	}

	return ;
}
/*
int main(){
int  val[50];
srand(time(NULL));
for (int i = 0 ; i < 50 ; i++)
{

    val[i] = (rand()%1000)+1;
}

SortNumber(val , 50);
return 0;
}*/
