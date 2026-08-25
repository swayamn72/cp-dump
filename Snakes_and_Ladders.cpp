#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
ll mod = 1e9+7;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    cin >> t;
    ll tc = 1;
    while(t--){
        ll n; cin >> n;
        vi jump(101,0);
        for(ll i=0; i<101; i++) jump[i] = i;
        for(ll i=0; i<n; i++){
            ll u,v; cin >> u >> v;
            jump[u] = v;
        }
        vector<vector<double>> mat(101,vector<double>(102,0.0));
        for(ll i=1; i<=100; i++){
            mat[i][i] = 1.0;
            mat[i][101] = 1.0;
            for(int roll=1; roll<=6; roll++){
                ll next = i+roll;
                if(next>100) next = i;
                ll finalcell = jump[next];
                mat[i][finalcell] -= 1.0/6.0;
            }
        }
        mat[100][100] = 1.0;
        mat[100][101] = 0.0;
        for(ll col=1; col<=100; col++){
            ll pivotrow = col;
            for(ll i=col+1; i<=100; i++){
                if(abs(mat[i][col]) > abs(mat[pivotrow][col])){
                    pivotrow = i;
                }
            }
            swap(mat[col],mat[pivotrow]);
            double pivotval = mat[col][col];
            for(ll j=col; j<=101; j++){
                mat[col][j] /= pivotval;
            }
            for(ll i=1; i<=100; i++){
                if(i!=col){
                    double factor = mat[i][col];
                    for(ll j=col; j<=101; j++){
                        mat[i][j] -= factor * mat[col][j];
                    }
                }
            }
        }
        cout << "Case " << tc++ << ": " << fixed << setprecision(10) << mat[1][101] << "\n";
    }
} 