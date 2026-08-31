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
        vi arr(n); for(auto &x : arr) cin >> x;
        stack<ll> st;
        vi pref(n); 
        for(ll i=0; i<n; i++){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            st.push(i);
            pref[i] = st.size();
        }
        while(!st.empty()) st.pop();
        vi suff(n);
        for(ll i=n-1; i>=0; i--){
            while(!st.empty() && arr[st.top()] <= arr[i]) st.pop();
            st.push(i);
            suff[i] = st.size();
        }
        ll res = 0;
        for(ll i=0; i<n-1; i++) res = max(res,pref[i]+suff[i+1]);
        cout << n-res << "\n";
    }
} 