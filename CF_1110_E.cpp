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
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        vi b(n); for(auto &x : b) cin >> x;
        map<ll,ll> mp;
        for(ll i=1; i<n; i++) mp[arr[i]-arr[i-1]]++;
        // for(auto a : mp) cout << a.first << " " << a.second << "\n";
        bool flag = true;
        if(arr[0]!=b[0]){
            cout << "No";
            continue;
        }         
        map<ll,ll> mp2;
        for(ll i=1; i<n; i++) mp2[b[i]-b[i-1]]++;
        cout << (mp==mp2 ? "Yes" : "No");
    }
} 