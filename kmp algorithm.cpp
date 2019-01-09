#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
void computePi(vector<ll> &pi, ll m, string pat)
{
	ll i = 0, j = 1;
	pi[0] = 0;
	while (j < m) {
		while ((j < m) && (pat[i] == pat[j])) {
			i++;
			pi[j] = i;
			j++;
		}
		if (i != 0)
			i = pi[i - 1];
		else
		{
			pi[j] = 0;
			j++;
		}

	}
}
void pattern(string text, string pat, ll n, ll m, vector<ll> &pi) {
	ll i = 0, j = 0;
	while (i < n) {
		while ((i < n) && (pat[j] == text[i])) {
			i++;
			j++;
		}
		if (j == m) {
			cout << (i - j) << endl;
			j = pi[j - 1];
		}
		else if (i < n&&pat[j] != text[i]) {
			if (j != 0)
				j = pi[j - 1];
			else
				i++;
		}
	}
}
int main() {
	ll t;
	cin >> t;
	while (t--) {
		string pat, text;
		cin >> text >> pat;
		ll n = text.length(), m = pat.length();
		vector<ll> pi(m + 1);
		computePi(pi, m,pat);
		pattern(text, pat, n, m, pi);
	}
}
