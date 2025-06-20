//O.o?  bug again??????
#include <bits/stdc++.h>
using namespace std;

#define Song4u ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define ll long long
#define pii pair<int,int>
#define tri tuple<int,int,int>
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3fLL

void solve(){
    int n;
    cin>>n;
    int all = n;
    
    ll mi = inf;
    
    vector<ll> a(n);
    
    map<ll,ll> cnt;
    
    vector<vector<int>> gra(n+1);
    for(int i = 0;i<n;i++) cin>>a[i],mi = min(mi,a[i]),cnt[a[i]] ++,gra[a[i]].push_back(i+1);
	
	ll ans = 0;

	sort(a.begin(),a.end());
	a.erase(unique(a.begin(),a.end()),a.end());
	
	n = a.size();
	
	int sum = 0;
	
	for(int i = 0;i<n;i++){
		if(i==0){
			ans+=a[i];
			sum+=cnt[a[i]];
			
			continue;
		}else{
			ans+=(all-sum);
			ans+=(a[i]-1-a[i-1]);
			sum+=cnt[a[i]];
		}
	}
	
	cout<<ans<<'\n';
	
	for(auto x  : a) cout<<x<<endl;
	
	for(int i = 0;i<n;i++){
		if(i==0){
			for(int j = 0;j<a[i];j++){
				cout<<1<<' '<<j<<'\n';
			}
		}else{
			for(int j = i;j<n;j++){
				for(auto x : gra[a[j]]){
					cout<<2<<' '<<x<<'\n';
				}
			}
			
			int x = a[i-1]+1;
			int gap = a[i]-x;
			
			while(gap--){
				cout<<1<<' '<<x<<'\n';
				x++;
			}
		}
	}
    
}

int main()
{
    Song4u
    
    int Test_number = 1;
//    cin>>Test_number;
    while(Test_number--) solve(); 
    return 0;

}

