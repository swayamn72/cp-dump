#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // freopen("zyaxxxx.in", "r", stdin);
    // freopen("zyaxxxx.out", "w", stdout);
    ll t=1; 
    // cin >> t;
    while(t--){
        string s; cin >> s;        
        if(s.size()==1){
            cout << "no";
            continue;
        }
        if(s.size()==2){
            if(s=="--") cout << "yes";
            else cout << "no";
            continue;
        }
        ll n = s.size();
        bool flag1 = false;
        if((s[0]=='-' && s[1]=='-')||s.substr(0,3)=="-uu") flag1 = true;
        bool flag2 = false;
        // cout << s.substr(n-2) << "\n";
        if(s.substr(n-2)=="--" || s.substr(n-2)=="-u") flag2 = true;
        if(flag2 && flag1) cout << "yes";
        else cout << "no";
    }
}