struct Node {
    int maxLen = 0;
    int prefLen = 0;
    int suffLen = 0;
    char prefChar = ' ';
    char suffChar = ' ';
    int len = 0;
};

class SegmentTree {
    int n;
    vector<Node> tree;

    Node merge(const Node& left, const Node& right) {
        Node res;
        res.len = left.len + right.len;
        res.prefChar = left.prefChar;
        res.suffChar = right.suffChar;

        // Base max length is the maximum within either child
        res.maxLen = max(left.maxLen, right.maxLen);

        // Standard prefix/suffix propagation
        res.prefLen = left.prefLen;
        res.suffLen = right.suffLen;

        // If middle characters match, merge across boundary!
        if (left.suffChar == right.prefChar) {
            res.maxLen = max(res.maxLen, left.suffLen + right.prefLen);

            if (left.prefLen == left.len) {
                res.prefLen = left.len + right.prefLen;
            }
            if (right.suffLen == right.len) {
                res.suffLen = right.len + left.suffLen;
            }
        }

        return res;
    }

    void build(int node, int start, int end, const string& s) {
        if (start == end) {
            tree[node] = {1, 1, 1, s[start], s[start], 1};
            return;
        }
        int mid = start + (end - start) / 2;
        build(2 * node, start, mid, s);
        build(2 * node + 1, mid + 1, end, s);
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

    void update(int node, int start, int end, int idx, char ch) {
        if (start == end) {
            tree[node] = {1, 1, 1, ch, ch, 1};
            return;
        }
        int mid = start + (end - start) / 2;
        if (idx <= mid) {
            update(2 * node, start, mid, idx, ch);
        } else {
            update(2 * node + 1, mid + 1, end, idx, ch);
        }
        tree[node] = merge(tree[2 * node], tree[2 * node + 1]);
    }

public:
    SegmentTree(const string& s) {
        n = s.length();
        tree.resize(4 * n);
        build(1, 0, n - 1, s);
    }

    void updateChar(int idx, char ch) {
        update(1, 0, n - 1, idx, ch);
    }

    int getMaxLen() {
        return tree[1].maxLen;
    }
};

class Solution {
public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        SegmentTree st(s);
        int k = queryIndices.size();
        vector<int> result(k);

        for (int i = 0; i < k; i++) {
            st.updateChar(queryIndices[i], queryCharacters[i]);
            result[i] = st.getMaxLen();
        }

        return result;
    }
};
