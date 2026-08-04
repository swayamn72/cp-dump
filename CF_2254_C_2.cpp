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
        string a,b; cin >> a >> b;
        if(a==b){
            cout << 0 << "\n";
            continue;
        }        
        vi odda, evena, oddb, evenb;
        for(ll i=0; i<n; i++){
            if(i%2){
                odda.push_back(a[i]);
                oddb.push_back(b[i]);
            }else{
                evena.push_back(a[i]);
                evenb.push_back(b[i]);
            }
        }

        vi posevena, posevenb;
        for(ll i=0; i<evena.size(); i++){
            if(evena[i]=='1') posevena.push_back(i);
            if(evenb[i]=='1') posevenb.push_back(i);
        }
        vi posodda, posoddb;
        for(ll i=0; i<odda.size(); i++){
            if(odda[i]=='1') posodda.push_back(i);
            if(oddb[i]=='1') posoddb.push_back(i);
        }
        bool flag = true;
        if(posevena.size()!=posevenb.size()) flag = false;
        if(posodda.size()!=posoddb.size()) flag = false;
        if(!flag){
            cout << -1 << "\n";
            continue;
        }
        ll res = 0;
        for(ll i=0; i<posodda.size(); i++){
            res += abs(posodda[i]-posoddb[i]);
        }
        for(ll i=0; i<posevena.size(); i++){
            res += abs(posevena[i]-posevenb[i]);
        }
        cout << res << "\n";
    }
}