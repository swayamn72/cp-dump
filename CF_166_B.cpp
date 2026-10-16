#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;

ll crossproduct(pair<ll,ll> a, pair<ll,ll> b, pair<ll,ll> c){
    return (b.first-a.first)*(c.second-a.second)-(b.second-a.second)*(c.first-a.first);
}

vector<pair<ll,ll>> convexhull(vector<pair<ll,ll>>& points){
    ll n = points.size();
    if(n <= 2) return points;
    
    ll k = 0;
    vector<pair<ll,ll>> hull(2*n);
    sort(points.begin(),points.end());
    
    // In competitive programming, convex hull problems fall into two categories:

    // Strict Convex Hull: Find only the absolute "corners" of the polygon and 
    // discard any points that lie flat on the edges. (Use <= 0).

    // All Points Convex Hull: Include the corners and all the points that sit 
    // flat along the straight edges of the boundary. (Use < 0).
    
    // lower hull
    for(ll i=0; i<n; i++){
        while(k>=2 && crossproduct(hull[k-2], hull[k-1], points[i])<0) k--;
        hull[k++] = points[i];
    }
    // upper hull
    ll t = k+1;
    for(ll i=n-2; i>=0; i--){
        while(k>=t && crossproduct(hull[k-2], hull[k-1], points[i])<0) k--;
        hull[k++] = points[i];
    }
    hull.resize(k-1);
    return hull;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1; 
    // cin >> t;
    while(t--){
        ll n; cin >> n;
        vector<pair<ll,ll>> points;
        for(ll i=0; i<n; i++){
            ll x,y; cin >> x >> y;
            points.push_back({x,y});
        }
        set<pair<ll,ll>> b;
        ll m; cin >> m;
        for(ll i=0; i<m; i++){
            ll x,y; cin >> x >> y;
            points.push_back({x,y});
            b.insert({x,y});
        }
        vector<pair<ll,ll>> hull = convexhull(points);
        bool flag = true;
        for(auto [x,y] : hull){
            if(b.count({x,y})){
                flag = false;
                break;
            }
        }
        cout << (flag ? "YES" : "NO");
    }
}