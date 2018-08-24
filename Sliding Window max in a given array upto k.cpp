#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void maxInWindow(vector<ll> &v1, ll n, ll k)
{
	ll Max = 0, max_in_window = 0, i = 0;
	for (ll i = 0; i < k; i++)
		Max += v1[i];
	max_in_window = Max;
	for (ll j = k; j < n; j++)
	{
		max_in_window += (v1[j] - v1[j - k]);
		Max = max(Max, max_in_window);
	}
	cout << Max << '\n';
}
int main()
{
	ll t;
	cin >> t;
	while (t--)
	{
		vector<ll> v1;
		ll a, n, k;
		cin >> n >> k;
		for (ll i = 0; i < n; i++)
		{
			cin >> a;
			v1.push_back(a);
		}
		maxInWindow(v1, n, k);
	}
}
