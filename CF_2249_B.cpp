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
        ll n; cin >> n;
        vi arr(n-1); for(auto &x : arr) cin >> x;
        bool isn = false;
        for(auto a : arr){
            if(a==n){
                isn = true;
                break;
            }
        }        
        if(isn){
            cout << 0 << "\n";
            continue;
        }
        if(n==2){
            cout << 2 << "\n";
            continue;
        }
        ll l=0;
        while(l<n-2 && arr[l+1]>=arr[l]) l++;
        ll r = n-2;
        while(r>0 && arr[r-1]>=arr[r]) r--;
        if(r>l+1){
            cout << 0 << "\n";
            continue;
        }
        vector<bool> vis(n+1,false);
        vis[arr[0]] = true;
        bool flag = true;
        for(ll i=1; i<n-1; i++){
            if(arr[i]!=arr[i-1]){
                if(vis[arr[i]]){
                    flag = false;
                    break;
                }
                vis[arr[i]] = true;
            }
        }
        if(!flag){
            cout << 0 << "\n";
            continue;
        }
        ll validc = 0;
        for(ll i=r; i<=l+1; i++){
            if(i>0 && i<n-1){
                if(arr[i-1]==arr[i]) continue;
            }
            validc++;
        }
        vi freq(n+1,0); for(auto a : arr) freq[a]++;
        vi v; 
        for(ll i=1; i<=n; i++){
            for(ll j=0; j<freq[i]; j++){
                v.push_back(i);
            }
        }
        ll res = 1;
        for(ll i=1; i<=n-1; i++){
            ll x = v[i-1];
            if(i==1 || v[i-1]!=v[i-2]){
                if(x<i){
                    res = 0;
                    break;
                }
            }else{
                ll choices = x-i+1;
                if(choices<=0){
                    res = 0;
                    break;
                }
                res = (res*choices)%mod;
            }
        }
        cout << (res*validc)%mod << "\n";
    }
}