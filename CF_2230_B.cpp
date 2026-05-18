#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t; cin >> t;
    while(t--){
        string s; cin >> s;
        ll n = s.size();
        ll res = 0;
        ll count2 = 0;
        ll count13 = 0;
        for(auto a : s){
            if(a=='1'||a=='3') count13++;
        }
        res = count13;
        for(ll i=0; i<n; i++){
            if(s[i]=='2') count2++;
            else if(s[i]=='1' || s[i]=='3') count13--;
            res = max(res, count2+count13);
        }
        cout << n-res << "\n";
    }
}
// vi twopref(n,0);
//         if(s[0]=='2') twopref[0] = 1;
//         for(ll i=1; i<n; i++){
//             twopref[i] = twopref[i-1];
//             if(s[i]=='2') twopref[i]++;
//         }

//         vi suff(n,0);
//         if(s[n-1]=='1' || s[n-1]=='3') suff[n-1]=0;