#include <iostream>
#include <algorithm>

using namespace std;



int main(){

    int n,i,j,len;
    int x1[1001],y1[1001],z1[1001],x2[1001],y2[1002],z2[1001];
    int a,b,c,A,B,C,ans;

    while(cin>>n){

		if(n==0)break;
        for(i=0;i<n;i++){

            cin>>x1[i]>>y1[i]>>z1[i]>>len;
            x2[i]=x1[i]+len;
            y2[i]=y1[i]+len;
            z2[i]=z1[i]+len;

        }
        a=0,b=0,c=0;
        
        for(i=0;i<n;i++){

            if(x1[i]>a) a=x1[i];
            if(y1[i]>b) b=y1[i];
            if(z1[i]>c)  c=z1[i];

        }
        
		A=x2[0];B=y2[0];C=z2[0];
        
		for(i=0;i<n;i++){

            if(x2[i]<A)A=x2[i];
            if(y2[i]<B)B=y2[i];
            if(z2[i]<C)C=z2[i];


        }

        ans = (A-a)*(B-b)*(C-c);
		if(ans<0)ans=0;        

        cout<<ans<<endl;



    }

    return 0;

}

