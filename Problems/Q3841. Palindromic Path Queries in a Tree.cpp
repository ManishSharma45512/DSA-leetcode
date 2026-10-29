class SegmentTree {
    int n;
    vector<int> tree;
public:
    SegmentTree(int n) : n(n), tree(4 * n, 0) {}

    void update(int node, int start, int end, int idx, int val) {
        if (start == end) {
            tree[node] = val;
            return;
        }
        int mid = (start + end) / 2;
        if (idx <= mid)
            update(2 * node, start, mid, idx, val);
        else
            update(2 * node + 1, mid + 1, end, idx, val);
        tree[node] = tree[2 * node] ^ tree[2 * node + 1];
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || end < l)
            return 0;
        if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        return query(2 * node, start, mid, l, r) ^ query(2 * node + 1, mid + 1, end, l, r);
    }
};

class Solution {
    vector<vector<int>> adj;
    vector<int> parent, depth, heavy, head, pos;
    int cur_pos;

    int dfs1(int u, int p, int d, const string& s, vector<int>& sz) {
        parent[u] = p;
        depth[u] = d;
        sz[u] = 1;
        int max_sub = 0;
        for (int v : adj[u]) {
            if (v != p) {
                int sub = dfs1(v, u, d + 1, s, sz);
                sz[u] += sub;
                if (sub > max_sub) {
                    max_sub = sub;
                    heavy[u] = v;
                }
            }
        }
        return sz[u];
    }

    void dfs2(int u, int h) {
        head[u] = h;
        pos[u] = cur_pos++;
        if (heavy[u] != -1) {
            dfs2(heavy[u], h);
        }
        for (int v : adj[u]) {
            if (v != parent[u] && v != heavy[u]) {
                dfs2(v, v);
            }
        }
    }

public:
    // Renamed from palindromicPathQueries to match test harness function signature
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
        adj.assign(n, vector<int>());
        for (const auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        parent.resize(n);
        depth.resize(n);
        heavy.assign(n, -1);
        head.resize(n);
        pos.resize(n);
        vector<int> sz(n);

        dfs1(0, -1, 0, s, sz);
        cur_pos = 0;
        dfs2(0, 0);

        SegmentTree st(n);
        string current_s = s;
        for (int i = 0; i < n; ++i) {
            st.update(1, 0, n - 1, pos[i], 1 << (s[i] - 'a'));
        }

        vector<bool> answer;
        for (const auto& q : queries) {
            if (q[0] == 'u') { // update u c
                int space1 = q.find(' ', 7);
                int u = stoi(q.substr(7, space1 - 7));
                char c = q.back();
                current_s[u] = c;
                st.update(1, 0, n - 1, pos[u], 1 << (c - 'a'));
            } else { // query u v
                int space1 = q.find(' ', 6);
                int space2 = q.find(' ', space1 + 1);
                int u = stoi(q.substr(6, space1 - 6));
                int v = stoi(q.substr(space1 + 1));

                int path_xor = 0;
                while (head[u] != head[v]) {
                    if (depth[head[u]] > depth[head[v]]) {
                        path_xor ^= st.query(1, 0, n - 1, pos[head[u]], pos[u]);
                        u = parent[head[u]];
                    } else {
                        path_xor ^= st.query(1, 0, n - 1, pos[head[v]], pos[v]);
                        v = parent[head[v]];
                    }
                }
                if (depth[u] > depth[v]) {
                    swap(u, v);
                }
                path_xor ^= st.query(1, 0, n - 1, pos[u], pos[v]);

                // Check if path_xor has at most 1 set bit
                if ((path_xor & (path_xor - 1)) == 0) {
                    answer.push_back(true);
                } else {
                    answer.push_back(false);
                }
            }
        }
        return answer;
    }
};
