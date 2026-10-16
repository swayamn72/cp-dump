#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp; for(auto a : arr) mp[a]++;
        sort(arr.begin(),arr.end());
        map<ll,ll> alice,bob;
        for(ll i=0; i<n; i++){
            if(i%2) bob[arr[i]]++;
            else alice[arr[i]]++;
        }     
        ll alicexor = 0;
        while(alice[alicexor]>=k) alicexor++;
        ll bobxor = 0;
        while(bob[bobxor]>=k) bobxor++;
        cout << (alicexor==bobxor ? "NO" : "YES") << "\n";
    }
}