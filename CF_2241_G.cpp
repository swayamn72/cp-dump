#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
using ull = unsigned long long;
void print128(__int128 n) {
    if (n == 0) {
        cout << 0 << "\n";
        return;
    }
    string s;
    while (n > 0) {
        s += (char)('0' + (n % 10));
        n /= 10;
    }
    reverse(s.begin(), s.end());
    cout << s << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vi arr(n); for(auto &x : arr) cin >> x;      
        
        vector<ll> index(n,-1);
        stack<ll> st;
        st.push(0);
        for(ll i=1; i<n; i++){
            ll val = arr[i];
            while(!st.empty() && (val%arr[st.top()]!=0)){
                index[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        // for(auto a : index) cout << a << " ";
        // cout << "\n";
        __int128 res = 0;
        for(ll i=0; i<n; i++){
            if(index[i]==-1) continue;
            ll num = n-index[i];
            ll val = arr[index[i]]%arr[i];
            ll val2 = arr[i] - val;
            ll minv = min(abs(val),abs(val2));
            res += (num*minv);
        }
        print128(res);
    }
}