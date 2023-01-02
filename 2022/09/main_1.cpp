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

vector<int> init_vector(int m, int value) {
    vector<int> ret_vector;
    for (int j=0; j<m; j++) {
        ret_vector.push_back(value);
    }
    return ret_vector;
}

vector<vector<int>> init_matrix(int n, int m, int value) {
    vector<vector<int>> ret_matrix;
    for (int i=0; i<n; i++) {
        vector<int> row;
        for (int j=0; j<m; j++) {
            row.push_back(value);
        }
        ret_matrix.push_back(row);
    }
    return ret_matrix;
}

int solve() {
    int M = 1000;
    int N = 1000;
    vector<vector<int>> visited = init_matrix(N, M, 0);
    int h_i=500, h_j=500, t_i=500, t_j=500;
    char direction;
    int distance;
    visited[500][500] = 1;
    while (scanf("%c %d", &direction, &distance) != EOF) {
        switch (direction) {
            case 'U':
                for (distance; distance>0; distance--) {
                    h_i--;
                    if (abs(h_i-t_i)>1) {
                        t_i = h_i+1;
                        t_j = h_j;
                        visited[t_i][t_j] = 1;
                    }
                }
                break;
            case 'D':
                for (distance; distance>0; distance--) {
                    h_i++;
                    if (abs(h_i-t_i)>1) {
                        t_i = h_i-1;
                        t_j = h_j;
                        visited[t_i][t_j] = 1;
                    }
                }
                break;
            case 'L':
                for (distance; distance>0; distance--) {
                    h_j--;
                    if (abs(h_j-t_j)>1) {
                        t_i = h_i;
                        t_j = h_j+1;
                        visited[t_i][t_j] = 1;
                    }
                }
                break;
            case 'R':
                for (distance; distance>0; distance--) {
                    h_j++;
                    if (abs(h_j-t_j)>1) {
                        t_i = h_i;
                        t_j = h_j-1;
                        visited[t_i][t_j] = 1;
                    }               
                }
                break;
        }
    }
    return count_ones(visited);
}

int main() {
    cout << solve() << endl;
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    // cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}