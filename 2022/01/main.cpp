#include <bits/stdc++.h>

using namespace std;

int solve_str() {
    string s;
    getline(cin,s);
    
    int r=0;

    for (int i=0; i<s.length(); i++) {
        // cout << s[i] << " ";
        
    }

    return r;
}

int solve_int() {
    int n;
    cin >> n;
    
    int r=0;

    return r;
}

int solve_vec_int() {
    vector<int> v;
    int n = -1;
    while (n != 123) {
        cin >> n;
        v.push_back(n);
    }
    int r=0;

    for (int i=0; i<v.size(); i++) {
        // cout << v[i] << " ";
        
    }

    return r;
}

int solve_vec_str() {
    string s = "---";
    vector<vector<int>> v;
    while (s.compare("FI") != 0) {
        vector<int> vv;
        getline(cin,s);
        try {
            while (s.compare("FI") != 0) {
                vv.push_back(stoi(s));
                getline(cin,s);
            }
        }
        catch (...) {}
        v.push_back(vv);
    }
    int max_1 = -1;
    int max_2 = -1;
    int max_3 = -1;
    vector<int> sums;
    for (int i=0; i<v.size(); i++) {
        sums.push_back(0);
        for (int j=0; j<v[i].size(); j++) {
            sums[i] += v[i][j];
        }
    }
    sort(sums.begin(),sums.end());
    reverse(sums.begin(),sums.end());
    return sums[0] + sums[1] + sums[2];
}

int solve_group_ints_separated_by_line() {
    string s = "---";
    vector<vector<int>> v;
    while (s.compare("FI") != 0) {
        vector<int> vv;
        getline(cin,s);
        try {
            while (s.compare("FI") != 0) {
                vv.push_back(stoi(s));
                getline(cin,s);
            }
        }
        catch (...) {}
        v.push_back(vv);
    }

}


int main() {
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    cout << solve_vec_str() << endl;
    cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}
