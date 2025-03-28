#include<iostream>
using namespace std;
int main(){
    int a[10],b[60],c[10]={0};
    int n,i,j,t;
    cin>>n;
    for(i=0;i<n;i++){
        cin>>a[i];
    }

    j=0;
    for(i=0;i<n;i++){
        for(;a[i]>0;j++){
            b[j]=a[i]%10;
            a[i]/=10;
        }
    }
    j--;
    for(;j>=0;j--){
        switch(b[j]){
            case 0:c[0]++;break;
            case 1:c[1]++;break;
            case 2:c[2]++;break;
            case 3:c[3]++;break;
            case 4:c[4]++;break;
            case 5:c[5]++;break;
            case 6:c[6]++;break;
            case 7:c[7]++;break;
            case 8:c[8]++;break;
            case 9:c[9]++;break;
        }
    }
    int max=1;
    for(i=0;i<=9;i++){
        if(max<c[i])
            max=c[i];
    }
    cout<<max<<":";
    for(i=0;i<=9;i++){
        if(c[i]==max)
        cout<<i<<" ";
    } 
}