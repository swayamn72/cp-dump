#include <bits/stdc++.h>
using namespace std;
using ll = long long;

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
        while(k>=2 && crossproduct(hull[k-2], hull[k-1], points[i])<=0) k--;
        hull[k++] = points[i];
    }
    // upper hull
    ll t = k+1;
    for(ll i=n-2; i>=0; i--){
        while(k>=t && crossproduct(hull[k-2], hull[k-1], points[i])<=0) k--;
        hull[k++] = points[i];
    }
    hull.resize(k-1);
    return hull;
}