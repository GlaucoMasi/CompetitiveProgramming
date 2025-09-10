#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
int lmax = 0;
vector<pair<int, int>> v;

bool f(int i, int last, int l, vector<pair<int, int>> &v) {
	vector<pair<int, int>> copia(v);

	for (int i = 0; i < n; i++) {
		int first = v[i].first;
		int second = v[i].second;

		if (first == last || last == -1) {
			l++;
			copia[i] = {-1, -1};
			f(i + 1, second, l, copia);
			l--;
			copia[i] = {first, second};
		}

		if (second == last || last == -1) {
			l++;
			copia[i] = {-1, -1};
			f(i + 1, first, l, copia);
			l--;
			copia[i] = {first, second};
		}
	}

	lmax = max(l, lmax);
	return false;
}

int main() {
	fin.tie(0);
	fin.sync_with_stdio(0);

	fin >> n;
	v.resize(n);

	for (int i = 0; i < n; i++)
		fin >> v[i].first >> v[i].second;

	f(0, -1, 0, v);
	fout << lmax;
}