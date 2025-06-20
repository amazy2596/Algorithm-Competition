#include <bits/stdc++.h>
using intt = long long;
using namespace std;
char aa[2001000],bb[2001000];
int main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    
    cin>>aa;
    int n,l,o=0,c,k=1,z;
    cin>>n;
    l=strlen(aa);
    if(l<n)
    {
        cout<<"-1"<<endl;
        return 0;
    }
    if(n==0)
    {
        cout<<aa;
        return 0;
    }
    c=l-n;
    z=c;
    int h=1;
    if(c==0)
    {
        for(int i=0;i<l;i++)
        {
            if(aa[i]=='0')
                h=0;
        }
        if(h==1)
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<l;i++)
    {
         if(aa[i]=='1'&&c==0)
        {
            bb[i]='0';
        }
        if(aa[i]=='1'&&c>0)
        {
            bb[i]='1';
            o++;
            c--;
        }
        if(aa[i]=='0')
        {
            if(o==i&&c>=0)
            {
                bb[i-1]='0';
                bb[i]='1';
                c++;
                o=0;
            }
            else{
                o=0;
                bb[i]='1';
            }
        }
    }
    if(z==0)
    {
        for(int i=0;i<l;i++)
        {
            if(aa[i]=='0')
                h=0;
        }
        if(h==1)
        {
            cout<<0;
            return 0;
        }
    }
    for(int i=0;i<l;i++)
    {
        if(bb[i]=='1')
        {
            k=0;
        }
        if(k==1&&bb[i]=='0')
        {

        }
        else{
            cout<<bb[i];
        }
        
    }
    return 0;
}