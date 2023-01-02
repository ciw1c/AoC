#include <bits/stdc++.h>

using namespace std;



string solve() {

    vector<string> v(9,"");
    v[0] = "GBDCPR";
    v[1] = "GVH";
    v[2] = "MPJDQSN";
    v[3] = "MNCDGLSP";
    v[4] = "SLFPCNBJ";
    v[5] = "STGVZDBQ";
    v[6] = "QTFHMZB";
    v[7] = "FBDMC";
    v[8] = "GQCF";

    int p1, p2, p3;
    int ret;
    ret = scanf("move %d from %d to %d\n", &p1, &p2, &p3);
    printf("%d %d %d\n", p1, p2, p3);
    for (auto s : v) {
        cout << s << endl;
    }
    cout <<  endl;
    while (ret > 0) {
        string ss = v[p2-1].substr(0,p1);
        v[p2-1] = v[p2-1].substr(p1,v[p2-1].length());
        // reverse(ss.begin(), ss.end());
        v[p3-1] = ss + v[p3-1];
        ret = scanf("move %d from %d to %d\n", &p1, &p2, &p3);
        printf("%d %d %d\n", p1, p2, p3);
        for (auto s : v) {
            cout << s << endl;
        }
        cout <<  endl;
    }
    string res = "";
    for (auto s : v) {
        res += s[0];
    }
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