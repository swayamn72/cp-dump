#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using vi = vector<ll>;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ll t; cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<string> arr(n); 
        for(auto &x : arr) cin >> x;

        vector<pair<ll,ll>> edges;
        bool possible = true;

        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(i == j) continue;
                if(arr[i][j] == '1'){
                    bool has_intermediate = false;
                    for(ll k=0; k<n; k++){
                        if(k == i || k == j) continue;
                        if(arr[i][k] == '1' && arr[k][j] == '1'){
                            has_intermediate = true;
                            break;
                        }
                    }
                    if(!has_intermediate){
                        edges.push_back({i, j});
                    }
                }
            }
        }
        if(edges.size() != n-1){
            cout << "No" << "\n";
            continue;
        }
        vector<vector<int>> reach(n, vector<int>(n, 0));
        for(ll i=0; i<n; i++) reach[i][i] = 1;
        for(auto &e : edges) reach[e.first][e.second] = 1;

        for(ll k=0; k<n; k++){
            for(ll i=0; i<n; i++){
                for(ll j=0; j<n; j++){
                    if(reach[i][k] && reach[k][j]) reach[i][j] = 1;
                }
            }
        }
        for(ll i=0; i<n; i++){
            for(ll j=0; j<n; j++){
                if(reach[i][j] != (arr[i][j] - '0')){
                    possible = false;
                    break;
                }
            }
            if(!possible) break;
        }

        if(!possible){
            cout << "No" << "\n";
        } else {
            cout << "Yes" << "\n";
            for(auto &e : edges){
                cout << e.first + 1 << " " << e.second + 1 << "\n";
            }
        }
    }
    return 0;
}