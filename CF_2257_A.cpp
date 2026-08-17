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
        ll n,m; cin >> n >> m;
        set<char> s;
        for(ll i=0; i<n; i++){
            string a; cin >> a;
            s.insert(a[0]);
        }
        bool flag = true;
        for(ll i=0; i<m; i++){
            string a; cin >> a;
            for(auto b : a){
                char ch = tolower(b);
                if(!s.count(ch)){
                    flag = false;
                    break;
                }
                if(!flag) break;
            }
        }
        cout << (flag ? "YES" : "NO") << "\n";
    }
} 