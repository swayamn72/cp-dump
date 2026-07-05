#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using vi = vector<ll>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll y,w; cin >> y >> w;
    if(w>y) y = w;
    if(y==1){
        cout << "1/1"; 
    }else if(y==2){
        cout << "5/6";
    }else if(y==3){
        cout << "2/3";
    }else if(y==4){
        cout << "1/2";
    }else if(y==5){
        cout << "1/3";
    }else{
        cout << "1/6";
    }
}