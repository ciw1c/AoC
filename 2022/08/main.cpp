#include <bits/stdc++.h>

using namespace std;

void show_matrix(vector<vector<int>> &matrix) {
    for (auto v : matrix) {
        for (auto e : v) {
            cout << e << " ";
        }
        cout << endl;
    }
}

int count_ones(vector<vector<int>> &matrix) {
    int total = 0;
    for (auto v : matrix) {
        for (auto e : v) {
            if (e == 1) total++;
        }
    }
    return total;
}

int max_from_matrix(vector<vector<int>> &matrix) {
    int max = -1;
    for (auto v : matrix) {
        for (auto e : v) {
            if (e > max)
                max = e;
        }
    }
    return max;
}

int solve() {
    string s;
    vector<vector<int>> heights;
    getline(cin,s);
    while (!cin.eof()) {
        vector<int> row;
        for (auto c : s) {
            row.push_back(c - '0');
        }
        heights.push_back(row);
        getline(cin,s);
    }
    vector<vector<int>> scores;
    for (int i=0; i<heights.size(); i++) {
        vector<int> score_row;
        for (int j=0; j<heights[i].size(); j++) {
            if (i == 0 || j == 0 || i == heights.size() - 1 || j == heights[i].size() - 1) {
                score_row.push_back(0);
            }
            else {
                int up=1, down=1, right=1, left=1;
                int ii, jj;
                ii = i+1;
                while (ii<heights.size()-1 && heights[ii][j]<heights[i][j]) {
                    down++;
                    ii++;
                }
                ii = i-1;
                while (ii>0 && heights[ii][j]<heights[i][j]) {
                    up++;
                    ii--;
                }
                jj = j+1;
                while (jj<heights[i].size()-1 && heights[i][jj]<heights[i][j]) {
                    right++;
                    jj++;
                }
                jj = j-1;
                while (jj>0 && heights[i][jj]<heights[i][j]) {
                    left++;
                    jj--;
                }
                score_row.push_back(up*down*right*left);
            }
        }
        scores.push_back(score_row);
    }
    int res = max_from_matrix(scores);
    show_matrix(scores);
    return res;
}

int main() {
    cout << solve() << endl;
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    // cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}