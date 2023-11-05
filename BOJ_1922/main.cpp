#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;
using UV = pii;
using EUV = pair<ll, UV>;

int N, M;
vector<EUV> edges;

vi root;

int par(int x) {
	if (x == root[x]) {
		return x;
	}

	return root[x] = par(root[x]);
}

void joint(int x, int y) {
	x = par(x);
	y = par(y);

	if (x != y) {
		root[x] = y;
	}
}

ll mst() {
	auto ct = 0;
	auto ret = 0LL;

	for (const auto& [w, uv] : edges) {
		const auto& [u, v] = uv;

		if (par(u) == par(v)) {
			continue;
		}

		ret += w;
		joint(u, v);
		++ct;

		if (N - 1 == ct) {
			return ret;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> N >> M;

	edges = vector<EUV>(M);
	for (auto&& [w, uv] : edges) {
		auto&& [u, v] = uv;
		cin >> u >> v >> w;
	}

	sort(edges.begin(), edges.end());

	root = vi(N + 1, 0);
	for (auto i = 1; i <= N; ++i) {
		root[i] = i;
	}

	cout << mst();

	return 0;
}