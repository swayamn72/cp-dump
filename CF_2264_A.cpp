#include <algorithm>
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n+1);
        for(ll i=1; i<=n; i++) cin >> arr[i];
        vi v;
        for(ll i=1; i<=n; i++){
            if(arr[i]!=i) v.push_back(arr[i]);
        }    
        reverse(v.begin(),v.end());
        if(is_sorted(v.begin(),v.end())){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
} 