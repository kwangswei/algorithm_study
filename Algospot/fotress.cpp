#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Node {
    public:
        int x;
        int y;
        int r;

        vector<Node> child;

        bool operator<(const Node& rhs) const {
            return r > rhs.r;
        }

        int get_max_distance() {
            int max_distance = get_sum_of_top_two_child_level();

            for (int i = 0; i < child.size(); ++i)
                max_distance = max(max_distance, child[i].get_max_distance());

            return max_distance;
        }

        int get_sum_of_top_two_child_level() {
            vector<int> buf;
            for (int i = 0; i < child.size(); ++i)
                buf.push_back(child[i].get_max_level());
            buf.push_back(0);
            buf.push_back(0);
            sort(buf.begin(), buf.end(), greater<int>());
            return buf[0] + buf[1];
        }

        int get_max_level() {
            if (child.size() == 0)
                return 1;

            int max_level = child[0].get_max_level();
            for (int i = 1; i < child.size(); ++i)
                max_level = max(max_level, child[i].get_max_level());

            return max_level + 1;
        }

        void add(Node& node) {
            for (int i = 0; i < child.size(); ++i) {
                if (child[i].is_my_child(node)) {
                    child[i].add(node);
                    return;
                }
            }
            child.push_back(node);
        }

        bool is_my_child(Node& node) {
            int distance = (x-node.x)*(x-node.x) + (y-node.y)*(y-node.y);
            return distance < r*r;
        }
};

int get_max_distance(vector<Node>& nodes);
Node& make_tree_and_get_root_node(vector<Node>& nodes);

int main() {
    int C;
    cin >> C;

    while (C --> 0) {
        int N;
        cin >> N;

        vector<Node> nodes;

        for (int i = 0; i < N; ++i) {
            Node node;
            cin >> node.x >> node.y >> node.r;
            nodes.push_back(node);
        }

        int max_distance = get_max_distance(nodes);
        cout << max_distance << endl;
    }

    return 0;
}

int get_max_distance(vector<Node>& nodes) {
    Node& node = make_tree_and_get_root_node(nodes);

    return node.get_max_distance();
}

Node& make_tree_and_get_root_node(vector<Node>& nodes) {
    sort(nodes.begin(), nodes.end());
    Node& root_node = nodes[0];

    for (int i = 1; i < nodes.size(); ++i)
        root_node.add(nodes[i]);

    return root_node;
}
