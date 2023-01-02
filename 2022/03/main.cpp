#include <bits/stdc++.h>

using namespace std;

int solve_vec_str() {
    vector<string> v;
    string s;
    getline(cin,s);
    while (s.compare("FI") != 0) {
        v.push_back(s);
        getline(cin,s);
    }
    int total = 0;
    for (int i=0; i<v.size(); i++) {
        if (i % 3 == 2 && i > 0) {
            vector<set <char>> v_sets(3);
            set<char> seti, setaux;
            for (int j=0; j<3; j++) {
                for (auto kk : v[i-j])
                    v_sets[j].insert(kk);
            }    
            set_intersection(v_sets[0].begin(), v_sets[0].end(), v_sets[1].begin(), v_sets[1].end(), inserter(setaux, setaux.begin()));
            if (setaux.size() > 0)
            {
                set_intersection(v_sets[2].begin(), v_sets[2].end(), setaux.begin(), setaux.end(), inserter(seti, seti.begin()));
                for (auto i : seti) {
                    if (i >= 'a' && i <= 'z')
                        total += i - 'a' + 1;
                    else 
                        total += i - 'A' + 27;
                }
            }
        }
    }
    return total;
}


int main() {
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    cout << solve_vec_str() << endl;
    // cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}