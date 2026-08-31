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
    cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n+1);
        for(ll i=1; i<=n; i++) cin >> arr[i];
        vector<pair<ll,ll>> st;
        ll cursum = 0;
        ll total = 0;
        for(ll i=n; i>=1; i--){
            while(!st.empty() && st.back().first == arr[i]+1){
                ll idx = st.back().second;
                cursum -= (n-idx+1);
                st.pop_back();
            }
            st.push_back({arr[i],i});
            cursum += (n-i+1);
            total += cursum;
        }
        cout << total << "\n";
    }
} 