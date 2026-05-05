#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll tt; cin >> tt;
    while(tt--){
        ll n; cin >> n;
        string s,t; cin >> s >> t;
        if(s==t){
            cout << "Yes" << "\n";
            cout << 0 << "\n" << "\n";
            continue;
        }
        bool flag = false;
        bool permaflag = true;
        bool same = false;
        vector<ll> res;
        for(ll i=n-1; i>=0; i--){
            if(!flag){
                if(s[i]!=t[i] && s[i]=='0'){
                    break;
                }else if(s[i]!=t[i]){
                    res.push_back(i+1);
                    flag = true;
                    same = true;
                }
            }else{
                if(same && s[i]==t[i]){
                    same = false;
                    res.push_back(i+1);
                }else if(!same && s[i]!=t[i]){
                    same = true;
                    res.push_back(i+1);
                }
            }
        }
        if(!flag){
            cout << "No" << "\n";
            continue;
        }
        cout << "Yes" << "\n";
        cout << res.size() << "\n";
        for(auto a : res) cout << a << " ";
        cout << "\n";

    }
}