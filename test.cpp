#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
	ll n; cin >> n;
	vector<ll> arr(n); for(auto &x : arr) cin >> x;
	vector<ll> dp(n);
	auto check = [&](vector<ll>&temp)->bool{
        bool flag = true;
        ll ptr1 = 0, ptr2 = temp.size()-1;
        while(ptr1<ptr2){
            if(temp[ptr1]==temp[ptr2]){
                ptr1++; ptr2--;
            }else{
                flag = false;
                break;
            }
        }
        return flag;
	};
	for(ll i=0; i<n; i++){
	    vector<ll> temp;
	    temp.push_back(arr[i]);
	    dp[i] = i+1;
	    for(ll j=i+1; j<n; j++){
	        temp.push_back(arr[j]);
	        if(check(temp)){
	            dp[i] = j+1;
	        }
	    }
	}
	ll res = 1;
	ll curr = dp[0];
	while(curr<n){
	    curr = dp[curr];
	    res++;
	}
	cout << res << "\n";
}
