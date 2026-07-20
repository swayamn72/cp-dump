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
        if(is_sorted(arr.begin(),arr.end())){
            cout << 0 << "\n";
            continue;
        }   
        vi v = arr;
        sort(v.begin(),v.end());
        ll val = 2;     
        while(val<n){
            bool flag = true;
            multiset<ll> s1, s2;
            ll temp = 0;
            for(ll i=0; i<n; i++){
                temp++;
                s1.insert(arr[i]);
                s2.insert(v[i]);
                if(temp==val || i==n-1){
                    temp = 0;
                    if(s1!=s2){
                        flag = false;
                        break;
                    }
                    s1.clear();
                    s2.clear();
                }
            }
            if(flag) break;
            val*=2;
        }
        
        cout << val/2 << "\n";
        
    }
}