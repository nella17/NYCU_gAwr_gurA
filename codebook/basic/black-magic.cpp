#include <ext/pb_ds/priority_queue.hpp>
#include <ext/pb_ds/assoc_container.hpp> //rb_tree
using namespace __gnu_pbds;
using heap = __gnu_pbds::priority_queue<int>;
// less_equal: multi set
template<typename T, typename U = null_type>
using rkt = tree<T, U, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());
// [0,n), [l,r]
template<typename T> T randint(T l, T r) { return uniform_int_distribution<T>(l,r)(rng); }
template<typename T> T randint(T n) { return randint(T(0),T(n-1)); }
int main() {
  heap h1, h2; h1.push(1), h1.push(3);
  h2.push(2), h2.push(4); h1.join(h2);
  cerr _ h1.size() _ h2.size() _ h1.top(); //4 0 4
  rkt<int> st; for (int x : {0, 2, 3, 4}) st.insert(x);
  cerr _ *st.find_by_order(2) _ st.order_of_key(1);//31
  // shuffle(ALL(v),rng);
} // __int128_t,__float128_t
