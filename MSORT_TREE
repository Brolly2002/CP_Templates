int n, q;
vector <int> _next, v;
vector <vector<int>> mergeSortTree;
 
void build (int d, int s, int e) {
    if (s == e) {
        mergeSortTree[d].push_back(_next[s]);
        return;
    }
    int m = (s + e) >> 1;
    build(2 * d + 1, s, m);
    build(2 * d + 2, m + 1, e);
    int left = 0, right = 0;
    while (left < mergeSortTree[2 * d + 1].size() && right < mergeSortTree[2 * d + 2].size()) {
        if (mergeSortTree[2 * d + 1][left] <= mergeSortTree[2 * d + 2][right]) {
            mergeSortTree[d].push_back(mergeSortTree[2 * d + 1][left ++]);
        }
        else {
            mergeSortTree[d].push_back(mergeSortTree[2 * d + 2][right ++]);
        }
    }
    while (left < mergeSortTree[2 * d + 1].size()) {
        mergeSortTree[d].push_back(mergeSortTree[2 * d + 1][left ++]);
    }
    while (right < mergeSortTree[2 * d + 2].size()) {
        mergeSortTree[d].push_back(mergeSortTree[2 * d + 2][right ++]);
    }
}
 
// number of elements > k
int query (int d, int s, int e, int l, int r, int k) {
    if (e < l || r < s) return 0;
    else if (l <= s && e <= r) {
        int left = 0, right = mergeSortTree[d].size() - 1, ans = mergeSortTree[d].size();
        while (left <= right) {
            int mid = (left + right) >> 1;
            if (mergeSortTree[d][mid] > k) ans = mid, right = mid - 1;
            else left = mid + 1;
        }
        ans = mergeSortTree[d].size() - ans;
        return ans;
    }
    else return query(2 * d + 1, s, (s + e) / 2, l, r, k) + query(2 * d + 2, (s + e) / 2 + 1, e, l, r, k);
}
