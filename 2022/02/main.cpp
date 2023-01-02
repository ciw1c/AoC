#include <bits/stdc++.h>

using namespace std;

int solve_vec_str() {
    string s = "---";
    int total = 0;
    getline(cin,s);
    while (s.compare("FI") != 0) {
        vector<int> vv;
        char r = s[0];
        char y = s[2];
        int act = 0;
        if (y == 'X') {
            if (r == 'A') {
                act += 3;
            }
            else if (r == 'B') {
                act += 1;
            }
            else {
                act += 2;                
            }
        }
        else if (y == 'Y') {
            act += 3;
            if (r == 'A') {
                act += 1;
            }
            else if (r == 'B') {
                act += 2;
            }
            else if (r == 'C') {
                act += 3;    
            }
        }
        else if (y == 'Z') {
            act += 6;
            if (r == 'A') {
                act += 2;
            }
            else if (r == 'B') {
                act += 3;
            }
            else if (r == 'C'){
                act += 1;                
            }
        }
        total += act;
        getline(cin,s);
    }
    return total;
}


int main() {
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    cout << solve_vec_str() << endl;
    cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}
