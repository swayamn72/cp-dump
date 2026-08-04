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
            cout << "YES" << "\n";
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
        sort(odda.begin(),odda.end());
        sort(oddb.begin(),oddb.end());
        sort(evena.begin(),evena.end());
        sort(evenb.begin(),evenb.end());
        if(odda==oddb && evena==evenb){
            cout << "YES" << "\n";
        }else{
            cout << "NO" << "\n";
        }
    }
}