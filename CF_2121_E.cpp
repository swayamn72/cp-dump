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
        ll l,r; cin >> l >> r;

        string s1 = to_string(l);
        string s2 = to_string(r);

        ll n = s1.size();
        ll ptr = 0;
        ll res = 0;
        while(ptr<n && s1[ptr]==s2[ptr]){
            ptr++;
            res += 2;
        }
        
        if(ptr<n && (s2[ptr]-s1[ptr]==1)){
            res++;
            ptr++;
            while(ptr<n && s1[ptr]=='9' && s2[ptr]=='0'){
                res++; ptr++;
            }
        }
        cout << res << "\n";
    }
}