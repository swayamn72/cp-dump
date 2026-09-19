#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    while(t--){
        ll n,m,k; cin >> n >> m >> k;
        vector<vi> grid(n,vi(m));
        if((m%k)!=0){
            ll val = 0;
            for(auto &a : grid){
                for(auto &b : a){
                    b = (val%k)+1;
                    val++;
                } 
            }
        }else{
            for(ll i=0; i<n; i++){
                ll val = 0;
                if(i%2) val = 1;
                for(ll j=0; j<m; j++){
                    grid[i][j] = (val%k)+1;
                    val++;
                }
            }
        }
        for(auto &a : grid){
            for(auto &b : a){
                cout << b << " ";
            }
            cout << "\n";
        }
    }
}