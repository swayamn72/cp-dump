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
        ll n,k; cin >> n >> k;
        vi p(n); for(auto &x : p){cin >> x; x--;}
        vi q(n); for(auto &x : q){cin >> x; x--;}
        
        vi cycleid(n,-1), cyclelen(n,0), pos(n,0);
        ll id = 0;
        for(ll i=0; i<n; i++){
            if(cycleid[i]==-1){
                ll curr = i;
                ll curpos = 0;
                vi nodes;
                while(cycleid[curr]==-1){
                    cycleid[curr] = id;
                    pos[curr] = curpos++;
                    nodes.push_back(curr);
                    curr = p[curr];
                }
                ll len = nodes.size();
                for(auto a : nodes){
                    cyclelen[a] = len;
                }
                id++;
            } 
        }
        for(auto a : cycleid) cout << a << " ";
        cout << "\n";
    }
}