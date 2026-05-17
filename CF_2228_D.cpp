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
        vector<vector<ll>> arr(n, vector<ll>(2));
        vector<ll> yexists(n+1,0);
        for(ll i=0; i<n; i++){
            ll x,y; cin >> x >> y;
            arr[i][0] = x; arr[i][1] = y;
            yexists[y] = 1;
        }    
        vector<ll> prefy(n+2,0);
        for(ll i=1; i<=n; i++) prefy[i] = prefy[i-1] + yexists[i];

        sort(arr.begin(),arr.end());

        vector<ll> leftfreq(n+1,0), rightfreq(n+1,0);

        ll rightminy = n+1, rightmaxy = -1;
        ll leftminy = n+1, leftmaxy = -1;
        
        for(ll i=0; i<n; i++){
            ll y = arr[i][1];
            rightfreq[y]++;
            if(rightfreq[y]==1){
                
            }
        }
    }
}