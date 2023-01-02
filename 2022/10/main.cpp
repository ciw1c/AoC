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

void show_matrix_char(vector<vector<char>> &matrix) {
    for (auto v : matrix) {
        for (auto e : v) {
            cout << e;
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

vector<vector<char>> init_matrix_char(int n, int m, char value) {
    vector<vector<char>> ret_matrix;
    for (int i=0; i<n; i++) {
        vector<char> row;
        for (int j=0; j<m; j++) {
            row.push_back(value);
        }
        ret_matrix.push_back(row);
    }
    return ret_matrix;
}

void show_snake(int N, int M, vector<int> vec_i, vector<int> vec_j){
    vector<vector<char>> matrix = init_matrix_char(N, M, '.');
    matrix[vec_i[9]][vec_j[9]] = 'T';
    for (int k=8; k>0; k--) {
        matrix[vec_i[k]][vec_j[k]] = char(k + '0');
    }
    matrix[vec_i[0]][vec_j[0]] = 'H';
    show_matrix_char(matrix);
}

int solve() {
    int N=1000;
    int M=1000;
    int start_i = 500;
    int start_j = 500;
    vector<vector<int>> visited = init_matrix(N, M, 0);
    vector<int> vec_i = init_vector(10, start_i);
    vector<int> vec_j = init_vector(10, start_j);
    char direction;
    int distance;
    visited[start_i][start_j] = 1;
    while (scanf(" %c %d", &direction, &distance) != EOF) {
        //  show_snake(N,M,vec_i,vec_j);
        for (distance; distance>0; distance--) {
            int prev_i=vec_i[0], prev_j=vec_j[0];
            switch(direction) {
                case 'U':
                    vec_i[0]--;
                    break;
                case 'D':
                    vec_i[0]++;
                    break;
                case 'L':
                    vec_j[0]--;
                    break;
                case 'R':
                    vec_j[0]++;
                    break;
            }
            for (int i=1; i<10; i++) {
                if (abs(vec_i[i-1]-vec_i[i])>1 || abs(vec_j[i-1]-vec_j[i])>1) {
                    if (vec_i[i-1] == vec_i[i]) {
                        if (vec_j[i-1]>vec_j[i])    vec_j[i]++;
                        else                        vec_j[i]--;
                    }
                    else if (vec_j[i-1] == vec_j[i]) {
                        if (vec_i[i-1]>vec_i[i])    vec_i[i]++;
                        else                        vec_i[i]--;
                    }
                    else {
                        if (vec_i[i-1]>vec_i[i])    vec_i[i]++;
                        else                        vec_i[i]--;
                        if (vec_j[i-1]>vec_j[i])    vec_j[i]++;
                        else                        vec_j[i]--;
                    }
                }
                else break;
            }
            visited[vec_i[9]][vec_j[9]] = 1;
        }
    }
    //  show_snake(N,M,vec_i,vec_j);
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