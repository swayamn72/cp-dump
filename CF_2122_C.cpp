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
        ll n; cin >> n;
        vector<vi> v;
        for(ll i=0; i<n; i++){
            ll a,b; cin >> a >> b;
            v.push_back({a,b,i+1});
        } 
        vi idx(n), idy(n);
        for(ll i=0; i<n; i++){
            idx[i] = i;
            idy[i] = i;
        }     
        sort(idx.begin(),idx.end(),[&](int a, int b){
            return v[a][0] < v[b][0];
        });
        sort(idy.begin(),idy.end(),[&](int a, int b){
            return v[a][1] < v[b][1];
        });
        vector<bool> isright(n,false), istop(n,false);
        for(ll i=n/2; i<n; i++){
            isright[idx[i]] = true;
            istop[idy[i]] = true;
        }
        vi q1,q2,q3,q4;
        for(ll i=0; i<n; i++){
            if(isright[i]&&istop[i]){
                q1.push_back(v[i][2]);
            }else if(isright[i]){
                q4.push_back(v[i][2]);
            }else if(istop[i]){
                q2.push_back(v[i][2]);
            }else{
                q3.push_back(v[i][2]);
            }
        }
        for(ll i=0; i<q1.size(); i++) cout << q1[i] << " " << q3[i] << "\n";
        for(ll i=0; i<q4.size(); i++) cout << q2[i] << " " << q4[i] << "\n";
    }
}