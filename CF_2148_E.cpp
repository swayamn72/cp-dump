#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n,k; cin >> n >> k;
        vi arr(n); for(auto &x : arr) cin >> x;
        map<ll,ll> mp;
        for(auto a : arr){
            mp[a]++;
        }        
        bool flag = true;
        for(auto a : mp){
            if(a.second%k!=0){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << 0 << "\n";
            continue;
        }
        ll res = 0;
        ll left = 0;
        map<ll,ll> mp2;
        for(ll i=0; i<n; i++){
            mp2[arr[i]]++;
            ll val = mp2[arr[i]];
            
            while(mp2[arr[i]]>mp[arr[i]]/k){
                mp2[arr[left]]--;
                left++;
            }

            res += (i-left+1);
        }
        cout << res << "\n";
    }
}