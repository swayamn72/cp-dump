#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
const ll mod = 1e9+7;
struct Point{
    ll x,y;
};
bool comp(Point a, Point b){
    if(a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
ll crossproduct(Point a, Point b, Point c){
    return (b.x-a.x)*(c.y-a.y) - (b.y-a.y)*(c.x-a.x);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    while(t--){
        ll n; cin >> n;
        vector<Point> points(n);
        for(ll i=0; i<n; i++){
            cin >> points[i].x >> points[i].y;
        }
        sort(points.begin(),points.end(),comp);
        // points.erase(unique(points.begin(), points.end(), [](Point a, Point b){
        //     return a.x == b.x && a.y == b.y;
        // }), points.end());
        // n = points.size();
        if(n<=2) {
            cout << n << "\n";
            for(auto p : points) cout << p.x << " " << p.y << "\n";
            continue;
        }
        sort(points.begin(),points.end(),comp);
        vector<Point> hull(2*n);
        ll k = 0;
        for(ll i=0; i<n; i++){
            while(k>=2 && crossproduct(hull[k-2], hull[k-1], points[i])<0) k--;
            hull[k++] = points[i];
        }
        ll temp = k+1;
        for(ll i=n-2; i>=0; i--){
            while(k>=temp && crossproduct(hull[k-2], hull[k-1], points[i])<0) k--;
            hull[k++] = points[i];
        }
        hull.resize(k-1);
        cout << hull.size() << "\n";
        for(auto a : hull) cout << a.x << " " << a.y << "\n";
    }
}