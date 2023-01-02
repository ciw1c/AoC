#include <bits/stdc++.h>

using namespace std;



int solve() {
    vector<string> v;
    int p1, p2, p3, p4;
    char aux;
    int ret = 1;
    int total = 0;
    ret = scanf("%d-%d,%d-%d", &p1, &p2, &p3, &p4);
    while (ret > 0) {
        if (p1 >= p3 && p1 <= p4 || p2 >= p3 && p2 <= p4 || p3 >= p1 && p3 <= p2 || p4 >= p1 && p4 <= p2)
            total++;
        ret = scanf("%d-%d,%d-%d", &p1, &p2, &p3, &p4);
    }
    return total;
}


int main() {
    cout << solve() << endl;
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    // cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}