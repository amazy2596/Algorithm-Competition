#include <bits/stdc++.h>
using intt = long long;
using namespace std;


int main(){
    vector<int>v;
    string s;
    cin>>s;
    int x;cin>>x;
    for(int i=0;i<s.size();i++){
        if(s[i]=='1')
        v.push_back(i);

    }
    for(int i=v.size()-1;i>=0;i--){
        string ss=s.substr(i,s.size());
        if(ss.size()<x) continue;
        int size1=v   .size()-i;
        int size2=ss.size()-size1;
    }
    if()
}