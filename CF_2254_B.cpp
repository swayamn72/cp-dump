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
        ll n; cin >> n;
        string s; cin >> s;
        vi v;
        vector<char> c;
        ll temp = 1;
        for(ll i=1; i<n; i++){
            if(s[i]==s[i-1]){
                temp++;
            }else{
                v.push_back(temp);
                c.push_back(s[i-1]);
                temp = 1;
            }
        }        
        v.push_back(temp);
        c.push_back(s[n-1]);
        ll res = v.size();
        bool flag1 = false;
        bool flag2 = false;
        for(ll i=1; i<v.size()-1; i++){
            if(v[i]==1){
                if(c[i-1]==c[i+1]){
                    flag1 = true;
                }else{
                    flag2 = true;
                }
            }
        } 
        if(flag1){
            cout << res-2 << "\n";
        }else if(flag2){
            cout << res-1 << "\n";
        }else{
            cout << res << "\n";
        }
    }
}