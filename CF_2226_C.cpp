#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<ll> arr(n); for(auto &x : arr) cin >> x;
        multiset<ll> s; for(auto a : arr) s.insert(a);
        multiset<ll> temp = s;
        ll res = 1;
        ll left = 2, right = n;
        while(left<=right){
            ll mid = left + (right-left)/2;
            bool flag = true;
            vector<bool> vis(mid,false);
            for(ll i=0; i<mid; i++){
                auto it = s.find(i);
                if(it!=s.end()){
                    s.erase(it);
                    vis[i] = true;
                }
            }
            for(ll i=0; i<mid; i++){
                if(vis[i]) continue;
                auto it = s.lower_bound(2*i+1);
                if(it==s.end()){
                    flag = false;
                    break;
                }else{
                    s.erase(it);
                }
            }
            if(flag){
                res = mid; 
                left = mid+1;
            }else{
                right = mid-1;
            }
            s = temp;
        }
        cout << res << "\n";
    }
}