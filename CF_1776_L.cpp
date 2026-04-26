#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n; cin >> n;
    string s; cin >> s;
    ll plus = 0; ll minus = 0;
    for(auto a : s){
        if(a=='+') plus++;
        else minus++;
    }
    ll q; cin >> q;
    while(q--){
        ll a,b; cin >> a >> b;
        if(a==b && plus==minus){
            cout << "YES" << endl;
            continue;
        }else if(a==b && plus!=minus){
            cout << "NO" << endl;
            continue;
        }
        ll minv = min(a,b);
        ll rem = max(a,b) - min(a,b);
        ll rightside = (minus*minv) - (plus*minv);
        ll absv = abs(rightside);
        if(rem!=0 && absv%rem!=0){
            cout << "NO" << endl;
            continue;
        }
        if(rem!=0){
            absv/=rem; rightside/=rem;
        } 
        if(rightside==0){
            cout << "YES" << endl;
            continue;
        }
        if(rightside>0 && plus>=absv){
            cout << "YES" << endl;
        }else if(rightside<0 && minus>=absv){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
}