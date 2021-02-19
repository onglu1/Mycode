#include <iostream>
#include <queue>
#define int long long
using namespace std;

int n, ans, maxd;
vector<int> a[100009];
priority_queue<int> q;
signed main()
{
	while(cin >> n) {
		ans = 0; maxd = 0;
		while(q.size()) q.pop();
		for(int i = 1; i <= n; i++) {
			int p, d;
			cin >> p >> d;
			a[d].push_back(p);
			maxd = max(maxd, d);
		}
		for(int i = maxd; i; i--) {
			for(int j = 0; j < a[i].size(); j++) {
				q.push(a[i][j]);
			}
			a[i].clear();
			if(q.size()) {
				ans += q.top();
				q.pop();
			}
		}
		cout << ans << endl;
	}
	return 0;
}
