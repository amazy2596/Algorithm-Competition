#include <bits/stdc++.h>
#define intt long long
using namespace std;
int main()
{
    char a[1001000];
    intt t;
    cin>>t;
    while(t--)
    {
        scanf("%s",&a);
        intt l,q,w,num;
        l=strlen(a);
        w=0;
        for(int i=0;i<=l-10;i++)
        {
            q=1;
            for(int j=i;j<=i+9;j++)
            {
                if(a[j]!='3')
                {
                    q=0;
                }
            }
            if(q==1)
            {
                w=1;
            }
        }
        num=-1;
        for(int i=0;i<l;i++)
        {
            if(a[i]=='5'||a[i]=='U')
            {
                num=i;
                break;
            }
        }
        if(w==1||num>=90)
        {
            cout<<"invalid"<<endl;
            continue;
        }
        if(num==-1)
        {
            if(l>=90)
            {
                cout<<"invalid"<<endl;
                continue;
            }
            else
            {
                cout<<"valid"<<endl;
                continue;
            }
            
        }
        w=0;
        for(int i=num+1;i<l;i++)
        {
            if(a[i]=='5'||a[i]=='U')
            {
                if(i-num>90)
                {
                    w=1;
                    break;
                }
                if(a[i]=='5'&&a[num]=='5')
                {
                    w=1;
                    break;
                }
                else
                {
                    num=i;
                }
            }
        }
        if(w==1||l-num>90)
        {
          
             cout<<"invalid"<<endl;
            continue;
        }
        else{
            cout<<"valid"<<endl;
        }
    }
    
}

// #include <bits/stdc++.h>
// #define int long long
// using namespace std;

// void solve()
// {
//     string s;
//     cin >> s;
//     bool ok = 1;
//     for (int i = 9; i < s.length(); i++)
//     {
//         bool f = 1;
//         for (int j = i; j >= i - 9; j--)
//         {
//             if (s[j] != '3')
//             {
//                 f = 0;
//                 break;
//             }
//         }
//         if (f)
//         {
//             ok = 0;
//             break;
//         }
//     }
//     for (int i = 89; i < s.length(); i++)
//     {
//         bool f = 1;
//         for (int j = i; j >= i - 89; j--)
//         {
//             if (s[j] == '5' || s[j] == 'U')
//             {
//                 f = 0;
//                 break;
//             }
//         }
//         if (f)
//         {
//             ok = 0;
//             break;
//         }
//     }
//     int n = s.length();
//     s = " " + s;
//     int last = 0;
//     for (int i = 1; i < s.length(); i++)
//     {
//         if (last == 0)
//         {
//             if (s[i] == '5' || s[i] == 'U')
//             {
//                 if (i - last > 90)
//                 {
//                     ok = 0;
//                     last = i;
//                     break;
//                 }
//                 last = i;
//             }
//         }
//         else 
//         {
//             if (s[i] == '5' || s[i] == 'U')
//             {
//                 if ((s[i] == '5' && s[last] == '5') || (i - last + 1) > 90)
//                 {
//                     last = i;
//                     ok = 0;
//                     break;
//                 }
//                 last = i;
//             }
//         }
//     }
//     if (last == 0 && n >= 90)
//         ok = 0;
//     else if (n - last + 1 > 90)
//         ok = 0;
//     cout << (ok ? "valid" : "invalid") << "\n";
// }

// signed main()
// {
//     ios::sync_with_stdio(false);
//     cout.tie(nullptr);
//     cin.tie(nullptr);
//     int t;
//     cin >> t;
//     while (t--)
//         solve();
//     return 0;
// }