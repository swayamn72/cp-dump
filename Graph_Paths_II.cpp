#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct matrix{
    ll n; vector<vector<ll>> mat;
    matrix(ll n){
        this->n = n;
        mat.resize(n, vector<ll>(n,LLONG_MAX));
    }
};
matrix multiply(matrix &a, matrix &b){
    ll n = a.n;
    matrix res(n);
    for(ll i=0; i<n; i++){
        for(ll k=0; k<n; k++){
            if(a.mat[i][k]==LLONG_MAX) continue;
            for(ll j=0; j<n; j++){
                if(b.mat[k][j]==LLONG_MAX) continue;
                res.mat[i][j] = min(res.mat[i][j],a.mat[i][k] + b.mat[k][j]);
            }
        }
    }
    return res;
}
matrix power(matrix &a, ll k){
    ll n = a.n;
    matrix res(n);
    for(ll i=0; i<n; i++) res.mat[i][i] = 0;
    while(k>0){
        if(k%2) res = multiply(res,a);
        a = multiply(a,a);
        k/=2;
    }
    return res;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    // mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
    ll n,m,k; cin >> n >> m >> k;
    matrix adj(n);
    while(m--){
        ll u,v,c; cin >> u >> v >> c; u--; v--;
        adj.mat[u][v] = min(c,adj.mat[u][v]);
    }
    matrix res = power(adj,k);
    cout << ((res.mat[0][n-1] == LLONG_MAX ) ? -1 : res.mat[0][n-1]);
}