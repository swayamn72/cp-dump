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
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;
        
        vi pref(n); 
        pref[0] = arr[0];
        for(ll i=1; i<n; i++) pref[i] = min(arr[i],pref[i-1]);
        
        vi suff(n);
        suff[n-1] = arr[n-1];
        for(ll i=n-2; i>=0; i--) suff[i] = max(arr[i],suff[i+1]);

        bool flag = true;
        for(ll i=1; i<n; i++){
            if(suff[i]<pref[i-1]){
                flag = false;
                break;
            }
        }
        if(!flag){
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";

        vi indices;
        for(ll i=0; i<n; i++){
            if(suff[i]==arr[i]) indices.push_back(i);
        }
        vector<vector<ll>> res;
        ll curr = 0;
        stack<ll> st;
        for(ll i=0; i<n; i++){
            if(arr[i]==suff[i]){
                while(!st.empty()){
                    int val = st.top();
                    st.pop();
                    res.push_back({arr[i],val});
                }
            }else{
                st.push(arr[i]);
            }
        }
        for(ll i=1; i<indices.size(); i++){
            ll val = arr[indices[i]];
            ll val2 = pref[indices[i-1]];
            res.push_back({val,val2});
        }
        for(auto a : res) cout << a[0] << " " << a[1] << "\n";
    }
}