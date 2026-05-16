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
        vi arr(n); for(auto &x : arr) cin >> x;
        bool flag = false;
        if(is_sorted(arr.begin(),arr.end())){
            cout << 0 << "\n";
            continue;
        }
        vector<ll> v;
        for(ll i=0; i<n; i++){
            if(arr[i]!=(i+1)) v.push_back(i);
        }        
        bool flag2 = true;
        // if(v.empty()){
        //     cout << 1 << "\n";
        //     continue;
        // }
        for(ll i=1; i<v.size(); i++){
            if(v[i]-v[i-1]!=1){
                flag2 = false;
                break;
            }
        }
        // if(flag2){
        //     if(v[0]!=0 && v[v.size()-1]!=n-1) flag2 = false;
            
        // }

        cout << (flag2 ? 1 : 2) << "\n";
    }
}