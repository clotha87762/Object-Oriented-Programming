#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
using namespace std;
struct tt{

    tt(){time=0;}

    int time;
    string s;

};
bool cmp(string a,string b){
    int w=0;
    for(w=0;w<min(a.size(),b.size());w++){

        if(b[w]>a[w])return true;
        if(a[w]>b[w])
            return false;

    }

}
typedef struct tt t;
int main(){

    int i,j,k,n,flag,f,ff,p,first=1,y=0;
    t text[10010];
    string temp;

    string out[10010];
    i=0;
    while(cin>>n){
        if(!first)cout<<endl;
        for(k=0;k<i;k++){text[k].time=0;text[k].s.clear();}
        for(k=0;k<i;k++) out[k].clear();
        f=0;i=0;j=0;k=0;


		while(cin>>temp){
            ff=0;
            y=0;
            //if(temp[0]=='-')continue;
            if(temp=="EndOfText")break;
            for(k=0;k<temp.size();k++)if((temp[k]<=90&&temp[k]>=65)||(temp[0]>=97&&temp[0]<=122))y=1;
            if(!y)continue;
            for(k=1;k<temp.size();k++)if(temp[k]=='-'){ff=1;break;}

            flag=0;

            if(ff==0){

            for(k=0;k<temp.size();k++){

                if(temp[k]<=90&&temp[k]>=65)temp[k]+=32;

            }
            while(!(temp[temp.size()-1]>=97&&temp[temp.size()-1]<=122)) temp.erase(temp.size()-1,1);
            while(!(temp[0]>=97&&temp[0]<=122))temp.erase(0,1);

            for(j=0;j<i;j++){
                    if(text[j].s==temp){
                    text[j].time++;

                    flag=1;
                    }
            }

            if(!flag){

                text[i].s=temp;
                text[i].time++;
                i++;
            }
            }
            else if(ff==1){

                for(k=0;k<temp.size();k++){

                if(temp[k]<=90&&temp[k]>=65)temp[k]+=32;

                }
                if(!(temp[temp.size()-1]>=97&&temp[temp.size()-1]<=122)) temp.erase(temp.size()-1,1);
                if(!(temp[0]>=97&&temp[0]<=122))temp.erase(0,1);
                //cout<<"fff"<<endl;
                while(temp.size()>0){

                    flag=0;
                    string ttt;

                    for(p=0;p<temp.size();p++){
                            if(temp[p]=='-')break;

                    }
                    ttt.assign(temp,0,p);
                    //cout<<ttt<<endl;
                    temp.erase(0,p+1);



                        for(j=0;j<i;j++){
                                if(text[j].s==ttt){
                                text[j].time++;

                                flag=1;
                                }
                        }

                        if(!flag){

                            text[i].s=ttt;
                            text[i].time++;
                            i++;
                        }
                 ttt.clear();

                }

            }
        }

        j=0;
        for(k=0;k<i;k++){
            if(text[k].time==n){out[j++]=text[k].s;f=1;}
        }
        if(!f)cout<<"There is no such word."<<endl;
        sort(out,out+j, cmp);
        for(k=0;k<j;k++)cout<<out[k]<<endl;
         first=0;

    }

    return 0;
}

