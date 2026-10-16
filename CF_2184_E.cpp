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
        vi arr(n); for(auto &x : arr) cin >> x; // 5 1 4 2 3
        vi res(n-1);
        res[0] = n*(n-1)/2;

        map<ll,vi> indices;
        for(ll i=0; i<n-1; i++){
            indices[abs(arr[i]-arr[i+1])].push_back(i); 
        }
        // map 
        // indices[1] = {3}
        // indices[2] = {2}
        // indices[3] = {1}
        // indices[4] = {0}

        // map<ll,ll> mp;
        // mp[n]++;
        // mp[5] = 1

        set<pair<ll,ll>> st;
        st.insert({0,n-1});
        // st = {{0,n-1}}
        ll ans = res[0];
        for(ll i=1; i<n-1; i++){
            for(auto &a : indices[i]){
                // a = 3
                auto it = st.lower_bound({a,0});
                if(it==st.end() || it->first!=a) it--;
                auto [p,q] = *(it); // p = 0 , q = n-1
                // mp[q-p+1]--; // mp[5] = 0
                ll len = q-p+1;
                ans -= (len*(len-1))/2;
                st.erase(it);
                st.insert({p,a}); 
                // mp[a-p+1]++; 
                ll len2 = a-p+1;
                ans += (len2*(len2-1))/2;
                if(a+1<=q){
                    st.insert({a+1,q});
                    // mp[q-a]++;
                    ll len3 = q-a;
                    ans += (len3*(len3-1))/2;
                } 
            }
            // ll ans = 0;
            // for(auto a : mp) ans += a.second*(a.first*(a.first-1))/2;
            res[i] = ans;
        } 
        for(auto a : res) cout << a << " ";
        cout << "\n";
    }
}