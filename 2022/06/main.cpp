#include <bits/stdc++.h>

using namespace std;

typedef struct Directory {
    struct Directory *parent;
    vector<Directory *> directories;
    string name;
    map<string,int> files; 
} Directory;

int calculate_directories_size(vector<tuple<string,int>> &files_vector, Directory *act_dir) {
    int total_size = 0;
    for (pair<string,int> file: act_dir->files)
        total_size += file.second;
    for (auto d : act_dir->directories)
        total_size += calculate_directories_size(files_vector,d);
    files_vector.push_back(make_tuple(act_dir->name,total_size));
    return total_size;
}   

int solve() {
    string s,ss; 
    getline(cin,s);                                 // $ cd /
    Directory *dir_parent = new Directory();
    dir_parent->name = '/';
    dir_parent->parent = NULL;
    Directory *act_dir = dir_parent;
    getline(cin,s);
    while (s.compare("FI") != 0) {
        if (s[2] == 'c') {
            if (s[5] == '.' && s[6] == '.' && act_dir->parent != NULL) {
                act_dir = act_dir->parent;
            }
            else {
                ss = s.substr(5,s.length());
                for (auto d : act_dir -> directories) {
                    if (ss.compare(d -> name) == 0) {
                        act_dir = d;
                    }
                }
            }
            getline(cin,s);
        }
        else {
            getline(cin,s);
            while (s.compare("FI") != 0 && s[0] != '$') {
                if (s[0] == 'd') {
                    ss = s.substr(4,s.length());
                    bool found = false;
                    for (auto d : act_dir->directories)
                        if (ss.compare(d -> name) == 0) found = true;
                    if (!found) {
                        Directory *aux_dir = new Directory();
                        aux_dir -> parent = act_dir;
                        aux_dir -> name = ss;
                        act_dir -> directories.push_back(aux_dir);
                    }
                }
                else {
                    size_t pos = s.find(" ");
                    string filename = s.substr(pos+1,s.length());
                    int filesize = stoi(s.substr(0,pos));
                    act_dir->files.insert({filename,filesize});
                }
                getline(cin,s); 
            }
        }
    }
    // Recorrer des de root
    vector<tuple<string,int>> files_vector;
    vector<int> sizes_vector;
    calculate_directories_size(files_vector,dir_parent);
    int free_space = 70000000 - get<1>(files_vector.back());
    int needed_space = 30000000 - free_space;
    int min = -1;
    for (auto file : files_vector) {
        if (get<1>(file) > needed_space && (min == -1 || get<1>(file) < min)) {
            min = get<1>(file);
        }
    }
    return min;
}

int main() {
    cout << solve() << endl;
    // cout << solve_str() << endl;
    // cout << solve_int() << endl;
    // cout << solve_vec_int() << endl;
    // cout << solve_group_ints_separated_by_line() << endl;
    return 0;
}