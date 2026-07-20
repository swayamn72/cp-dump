#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;

template<typename T>
using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template<typename T> // use timer
using omset = tree<pair<T, ll>, null_type, less<pair<T, ll>>, rb_tree_tag, tree_order_statistics_node_update>;

// kth smallest (0-indexed)
// auto it = s.find_by_order(2);

// count less than k
// ll a = s.order_of_key(10);
// ll a = s.order_of_key({10,-1})

// ll c = s.size() - s.order_of_key({10, 1e9}); // Count strictly > 10