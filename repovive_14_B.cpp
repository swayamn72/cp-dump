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
        ll n,m; cin >> n >> m;
        vector<string> arr(m); for(auto &x : arr) cin >> x;
        string s = arr[0];
        for(ll i=1; i<m; i++) s.append(arr[i]);
        // cout << s << "\n";    
        ll longest = 1;
        ll temp = 1;
        vi v;
        for(ll i=1; i<s.size(); i++){
            if(s[i]==s[i-1]){
                temp++;
            }else{
                v.push_back(temp);
                temp = 1;
            }
        }
        
        if(temp>0) v.push_back(temp);
        ll res = v[0];

        vi v2; for(ll i=1; i<v.size(); i++) v2.push_back(v[i]);
        sort(v2.rbegin(),v2.rend());
        // for(auto a : v) cout << a << " ";
        // cout << "\n";

        for(ll i=0; i<m-1; i++){
            if(i<v2.size()) res += v2[i];
        }
        cout << res << "\n";
    }
}