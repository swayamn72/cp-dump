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
        ll n,k; cin >> n >> k;
        string s; cin >> s;
        vector<string> v;
        string temp = ""; temp += s[0];
        for(ll i=1; i<n; i++){
            if(i%k==0){
                v.push_back(temp);
                temp = "";
                temp += s[i];
            }else{
                temp += s[i];
            }
        }        
        v.push_back(temp);
        ll res = 0;
        for(auto a : v){
            bool flag = false;
            for(auto b : a){
                if(b=='0') flag = true;
            }
            if(!flag) res++;
        }
        cout << res << "\n";
    }
} 