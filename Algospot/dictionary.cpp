#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>

using namespace std;

#define MAX_WORD 1001

typedef int INDEX;

int graph[MAX_WORD][MAX_WORD];

map<char, INDEX> char_to_index;
map<INDEX, char> index_to_char;

bool visited[MAX_WORD];

vector<int> result;

int node_count;


void init();
void update_graph(string prev, string curr);
int get_index_of_graph(char c);
bool solve();
bool dfs(int);
bool did_include_cycle(int node);
void print_result();


int main() {
    int T;
    cin >> T;

    while (T--) {
        int N;
        cin >> N;

        init();

        string prev;
        string curr;
        cin >> curr;
        for (int i = 0; i < N-1; ++i) {
            prev = curr;
            cin >> curr;
            update_graph(prev, curr);
        }

        if (solve())
            print_result();
        else
            cout << "INVALID HYPOTHESIS" << endl;
    }
    return 0;
}

void init() {
    memset(graph, 0, sizeof(graph));
    char_to_index.clear();
    index_to_char.clear();
    result.clear();

    fill(visited, visited+MAX_WORD, false);

    node_count = 0;
}

void update_graph(string prev, string curr) {
    int idx = 0;
    while (idx < prev.size() && idx < curr.size()) {
        if (prev[idx] == curr[idx]) {
            idx++;
        }
        else {
            int prev_index_of_graph = get_index_of_graph(prev[idx]);
            int curr_index_of_graph = get_index_of_graph(curr[idx]);
            graph[prev_index_of_graph][curr_index_of_graph] = 1;
            break;
        }
    }
}

int get_index_of_graph(char c) {
    if (char_to_index.find(c) != char_to_index.end())
        return char_to_index[c];

    char_to_index[c] = node_count;
    index_to_char[node_count] = c;

    node_count++;
    return char_to_index[c];
}

bool solve() {
    for (int i = 0; i < node_count; ++i) {
        if (!visited[i]) {
            if (!dfs(i))
                return false;
        }
    }
    reverse(result.begin(), result.end());
    return true;
}


bool dfs(int node) {
    visited[node] = true;

    for (int i = 0; i < node_count; ++i) {
        if (!graph[node][i])
            continue;

        if (visited[i]) {
            if (did_include_cycle(i))
                return false;
        }
        else if (!dfs(i))
            return false;
    }

    result.push_back(node);
    return true;
}

bool did_include_cycle(int node) {
    return find(result.begin(), result.end(), node) == result.end();
}

void print_result() {
    int check[26] = {0,};
    for (int i = 0; i < result.size(); ++i) {
        check[index_to_char[result[i]] - 'a'] = 1;
        cout << index_to_char[result[i]];
    }

    for (int i = 0; i < 26; ++i) {
        if (check[i] == 0)
            cout << (char)(i+'a');
    }
    cout << endl;
}
