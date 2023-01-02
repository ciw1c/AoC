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
    vector<vector<int>> visibles;
    for (int i=0; i<heights.size(); i++) {
        vector<int> row;
        for (int j=0; j<heights[i].size(); j++) {
            row.push_back(0);
        }
        visibles.push_back(row);
    }
    int max;
    //  De izquierda a derecha
    for (int i=0; i<heights.size(); i++) {
        max = -1;
        for (int j=0; j<heights[i].size(); j++) {
            if (heights[i][j] > max) {
                visibles[i][j] = 1;
                max = heights[i][j];
                if (max == 9)
                    break;
            }
        }
    }
    //  De derecha a izquierda
    for (int i=0; i<heights.size(); i++) {
        max = -1;
        for (int j=heights[i].size()-1; j>=0; j--) {
            if (heights[i][j] > max) {
                visibles[i][j] = 1;
                max = heights[i][j];
                if (max == 9)
                    break;
            }
        }
    }
    //  De arriba a abajo
    for (int j=0; j<heights[0].size(); j++) {
        max = -1;
        for (int i=0; i<heights.size(); i++) {
            if (heights[i][j] > max) {
                visibles[i][j] = 1;
                max = heights[i][j];
                if (max == 9)
                    break;
            }
        }
    }
    //  De abajo a arriba
    for (int j=0; j<heights[0].size(); j++) {
        max = -1;
        for (int i=heights.size()-1; i>=0; i--) {
            if (heights[i][j] > max) {
                visibles[i][j] = 1;
                max = heights[i][j];
                if (max == 9)
                    break;
            }
        }
    }

    int res = count_ones(visibles);
    show_matrix(visibles);
    show_matrix(heights);
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