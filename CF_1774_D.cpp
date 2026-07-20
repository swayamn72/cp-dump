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
        ll n,m; cin >> n >> m;
        vector<vi> v(n,vi(m));\
        ll ones = 0;
        for(auto &a : v) for(auto &b : a){
            cin >> b; if(b==1) ones++;
        } 
        if(ones%n!=0){
            cout << -1 << "\n";
            continue;
        }
        vector<int> one(n,0);
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++) if(v[i][j]) one[i]++;
        }
        ll val = ones/n;
        vector<vi> res;
        for(int i=0; i<m; i++){
            vi available;
            vi need;
            for(int j=0; j<n; j++){
                if(one[j]<val && v[j][i]==0) need.push_back(j);
                if(one[j]>val && v[j][i]==1) available.push_back(j);
            }
            ll ptr = 0;
            while(ptr<need.size() && ptr<available.size()){
                if(v[need[ptr]][i]==0 && v[available[ptr]][i]==1){
                    res.push_back({need[ptr]+1,available[ptr]+1,i+1});
                    one[need[ptr]]++; one[available[ptr]]--;
                }
                ptr++;
            }
        }

        cout << res.size() << "\n";
        for(auto a : res) cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    }
}