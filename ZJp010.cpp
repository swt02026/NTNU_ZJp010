#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define x first
#define y second
using namespace std;
void searchword(const vector<string>& grid, const string& word) {
	static const pair<int, int> direction[] = { make_pair(0, 1), make_pair(1,
			0), make_pair(-1, 0), make_pair(0, -1), make_pair(1, 1), make_pair(
			1, -1), make_pair(-1, 1), make_pair(-1, -1) };
	for (int SearchLength = 0, i = 0; i < grid.size(); i++)
		for (int j = 0; j < grid[0].length(); j++)
			if (grid[i][j] == word[0]) {
				for (int d = 0; d < 8; d++) {
					SearchLength = 1;
					for (int k = 1; k < word.length(); k++) {
						pair<int, int> position = make_pair(
								j + k * direction[d].x, i + k * direction[d].y);
						if (position.x < 0 || position.x >= grid[0].length()
								|| position.y < 0 || position.y >= grid.size())
							break;
						if (grid[position.y][position.x] == word[k])
							SearchLength++;
						else
							break;
						if (SearchLength == word.size()) {
							cout << i + 1 << ' ' << j + 1 ;
							if(i < (grid.size()-1))cout << endl;
							return;
						}
					}

				}
			}
}

int main() {
	int caseNum;
	cin >> caseNum;
	for (int m, n, k; caseNum--;) {
		vector<string> grid;
		cin >> m >> n;
		for (int i = 0; i < m; i++) {
			string line;
			cin >> line;
			transform(line.begin(), line.end(), line.begin(), ::toupper);
			grid.push_back(line);
		}
		cin >> k;
		for (int i = 0; i < k; i++) {
			string word;
			cin >> word;
			transform(word.begin(), word.end(), word.begin(), ::toupper);
			searchword(grid, word);
		}
		if (caseNum)
			puts("");
	}
	return 0;
}
