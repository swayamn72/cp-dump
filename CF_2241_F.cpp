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
        string s; cin >> s;
        ll val = 0;
        ll idx = 0;
        while(idx<n && s[idx]=='0') idx++;
        ll ones = 0;
        for(ll i=idx; i<n; i++){
            if(s[i]=='1') ones++;
            else val += ones;
        }
        // cout << val << "\n";
        if(val%2){
            cout << "Alice" << "\n";
        }else{
            bool flag = true;
            ones = 0;
            ll zeros = 0;
            ll totalzeros = 0;
            for(auto a : s) if(a=='0') totalzeros++;
            for(ll i=0; i<n; i++){
                if(s[i]=='1'){
                    ll zerosafter = totalzeros - zeros;
                    if(zerosafter%2){
                        flag = false;
                        break;
                    }
                    ones++;
                }else{
                    if(ones%2){
                        flag = false;
                        break;
                    }
                    zeros++;
                }
            }
            if(flag){
                cout << "Bob" << "\n";
            }else{
                cout << "Alice" << "\n";
            }
        }
    }
}