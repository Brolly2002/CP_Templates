#include <bits/stdc++.h>
using namespace std;


/*

    Persistant Segment Tree:
    Problem Link: https://codeforces.com/contest/813/problem/E

*/


struct Node {

    int value;
    Node *left;
    Node *right;

    Node (int x) : value(x), left(nullptr), right(nullptr) {}

    Node (Node *passedL, Node *passedR) {
        left = passedL;
        right = passedR;
        value = 0;
        if (left != nullptr) value += left -> value;
        if (right != nullptr) value += right -> value;
    }

    Node (Node* copyIt) : value(copyIt -> value), left(copyIt -> left), right (copyIt -> right) {}

};

Node *build (int s, int e) {
    if (s == e) {
        return new Node(0);
    }
    int m = (s + e) >> 1;
    return new Node(build(s, m), build(m + 1, e));
}

Node *update (Node* node, int s, int e, int pos, int val) {
    if (s == e) return new Node(val);
    int m = (s + e) >> 1;
    if (pos <= m) return new Node(update(node -> left, s, m, pos, val), node -> right);
    else return new Node(node -> left, update(node -> right, m + 1, e, pos, val));
}

long long query (Node *node, int s, int e, int l, int r) {
    if (e < l or r < s) return 0ll;
    else if (l <= s and e <= r) return node -> value;
    else return query(node -> left, s, (s + e) / 2, l, r) + query(node -> right, (s + e) / 2 + 1, e, l, r);
}

vector <Node*> roots;

void Solution()
{
    int n, k;
    cin >> n >> k;
    vector <int> v(n);
    for (auto &x : v) cin >> x;
    int mx = *max_element(v.begin(), v.end());
    vector <vector<int>> windows(mx + 1);
    Node* cur = build(0, n - 1);
    roots.push_back(update(cur, 0, n - 1, 0, 1));
    windows[v[0]].push_back(0);
    for (int i = 1; i < n; i ++) {
        windows[v[i]].push_back(i);
        int SIZE = windows[v[i]].size();
        cur = update(roots[i - 1], 0, n - 1, i, 1);
        if (SIZE > k) {
            cur = update(cur, 0, n - 1, windows[v[i]][SIZE - k - 1], 0);
        }
        roots.push_back(cur);
    }
    int q;
    cin >> q;
    int last = 0;
    while (q --) {
        int l, r;
        cin >> l >> r;
        l = ((l + last) % n) + 1;
        r = ((r + last) % n) + 1;
        if (l > r) swap(l, r);
        last = query(roots[r - 1], 0, n - 1, l - 1, r - 1);
        cout << last << '\n';
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);   
    cout.tie(NULL);
    int Test_case = 1;  // cin >> Test_case;
    
    while(Test_case --) Solution();
    
}
