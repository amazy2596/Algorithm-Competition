//O.o?  bug again??????
#include <bits/stdc++.h>
using namespace std;

#define Song4u ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define pll pair<long long,long long>
#define pdd pair<double,double>
#define tri tuple<int,int,int>
#define fi first
#define se second
#define inf 0x3f3f3f3f 
#define infll 0x3f3f3f3f3f3f3f3fLL

const double EPS = 1e-9;

void solve(){

    int l,r,mid;
    int ans;
    auto check = [&](int mid) -> bool{

    };
    //整数
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }

    //实数
    int times=100;
    while(times--)
    {
        mid=(l+r)/2;
        if(check(mid))
        {
            l=mid;
            ans=mid;
        }
        else
            r=mid;
    }

        //整数
    while(l<=r)
    {
        mid=(l+r)/2;
        if(check(mid)<check(mid+1))
        {
            l=mid+1;
            ans=mid;
        }
        else
            r=mid-1;
    }

    //实数
    int times=100;
    while(times--)
    {
        mid=(l+r)/2;
        if(check(mid)<check(mid+EPS))
        {
            l=mid;
            ans=mid;
        }
        else
            r=mid;
    }
}

int main()
{
    Song4u
    
    int Test_number = 1;
    // cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}


