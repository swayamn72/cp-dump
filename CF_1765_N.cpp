#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        string n; cin >> n;
        ll k; cin >> k;
        if(k==0){
            cout << n << "\n";
            continue;
        }
        set<ll> s;
        for(ll i=0; i<k+1; i++){
            s.insert(n[i]-'0');
        }
        ll ch;
        for(auto a : s){
            ch = a;
        }
        for(auto a : s){
            if(a!=0) ch = min(ch,a);
        }
        string res = ""; res += ch+'0';
        for(ll i=k+1; i<n.size();i++) res += n[i];
        cout << res << "\n";
    }
}