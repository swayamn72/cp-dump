#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct matrix{
    ll n; vector<vector<ll>> mat;
    matrix(ll n){
        this->n = n;
        mat.resize(n, vector<ll>(n,0));
    }
};
matrix multiply(matrix &a, matrix &b){
    ll n = a.n;
    matrix res(n);
    for(ll i=0; i<n; i++){
        for(ll k=0; k<n; k++){
            for(ll j=0; j<n; j++){
                res.mat[i][j] = (res.mat[i][j] + a.mat[i][k] * b.mat[k][j])%mod;
            }
        }
    }
    return res;
}
matrix power(matrix &a, ll k){
    ll n = a.n;
    matrix res(n);
    for(ll i=0; i<n; i++) res.mat[i][i] = 1;
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
    ll n; cin >> n;
    matrix a(6);
    for(ll i=0; i<6; i++) a.mat[0][i] = 1;
    for(ll i=1; i<6; i++) a.mat[i][i-1] = 1;
    matrix res = power(a,n);
    cout << res.mat[0][0];
}