#include <iostream>
#include <string.h>

using namespace std;

int main(){


    char s1[1000],s2[1000];
    int i,j,temp;
    while(cin>>s1){

        temp=0;
        cin>>s2;
        j=0;
        for(i=0;s2[i]!=NULL;i++){


            if(s2[i]==s1[j]){

                j++;
            }

        }

    if(s1[j]==NULL)temp=1;

    if(temp)cout<<"Yes"<<endl;
        else{cout<<"No"<<endl;}


    }

    return 0;

}

