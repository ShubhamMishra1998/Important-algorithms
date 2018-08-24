#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void maxInWindow(vector<ll> &v1, ll n, ll k)
{
	deque<ll> dq;
	ll i;
	for (i = 0; i < k; i++)
	{
		while (!dq.empty() && v1[i] >= v1[dq.back()])
			dq.pop_back();
		dq.push_back(i);
	}
	for (ll j = i; j < n; j++)
	{
		cout << v1[dq.front()] << ' ';
		while (!dq.empty() && dq.front() <= j - k)
			dq.pop_front();
		while (!dq.empty() && v1[j] >= v1[dq.back()])
			dq.pop_back();
		dq.push_back(j);
	}
	cout << v1[dq.front()] << ' ';

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
		cout << '\n';
	}
}
