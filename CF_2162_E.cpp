#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n);
        vector<bool> vis(n+1,false);
        vector<bool> vis2(n+1,false);
        for(auto &x : arr){
            cin >> x;
            vis[x] = true;
        } 
        vector<ll> num(3);
        ll ptr = 0;
        bool found = false;
        for(ll i=1; i<=n; i++){
            if(!vis[i]){
                num[ptr++] = i;
            }
            if(ptr==3){
                found = true;
                break;
            }
        }
        vi res;
        if(found){
            for(ll i=0; i<k; i++){
                res.push_back(num[i%3]);
            }
            for(auto a : res) cout << a << " ";
            cout << "\n";
            continue;
        }
        vi v;
        for(ll i=n-1; i>=0; i--){
            if(!vis2[arr[i]]) v.push_back(arr[i]);
            vis2[arr[i]] = true;
        }
        reverse(v.begin(),v.end());
        ll ptr2 = 0;
        while(ptr<3){
            num[ptr++] = v[ptr2++];
        }
        for(ll i=0; i<k; i++){
            res.push_back(num[i%3]);
        }
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}