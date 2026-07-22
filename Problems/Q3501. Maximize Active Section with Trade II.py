import math

class Solution:
    def maxActiveSectionsAfterTrade(self, s: str, queries: list[list[int]]) -> list[int]:
        n = len(s)

        # Decompose s into maximal 0-runs: idxs[i] = [start, length]
        # lookup[i] = index of the last 0-run ending at or before i
        #             (its own run if s[i]=='0', else the previous one, or -1)
        idxs = []
        lookup = [-1] * n
        cnt1 = 0
        for i, ch in enumerate(s):
            if ch == '0':
                if i > 0 and s[i - 1] == '0':
                    idxs[-1][1] += 1
                else:
                    idxs.append([i, 1])
            else:
                cnt1 += 1
            lookup[i] = len(idxs) - 1

        if not idxs:                      # no zeros -> no trade ever helps
            return [cnt1] * len(queries)

        # pair[i] = combined size of two adjacent 0-runs (merged by deleting
        # the 1-run between them)
        m = len(idxs)
        pair = [idxs[i][1] + idxs[i + 1][1] for i in range(m - 1)]

        # Sparse table for O(1) range-max on `pair` (s never changes)
        st = [pair[:]]
        j = 1
        while (1 << j) <= len(pair):
            prev, half = st[-1], 1 << (j - 1)
            st.append([max(prev[i], prev[i + half]) for i in range(len(pair) - (1 << j) + 1)])
            j += 1

        def range_max(l, r):
            if l > r:
                return -math.inf
            k = (r - l + 1).bit_length() - 1
            return max(st[k][l], st[k][r - (1 << k) + 1])

        ans = []
        for l, r in queries:
            best = cnt1  # baseline: no trade

            left  = lookup[l] + 1                                  # first fully-inside run
            right = lookup[r] - (1 if s[r] == '0' else 0)          # last fully-inside run

            left_cnt  = (idxs[lookup[l]][1] - (l - idxs[lookup[l]][0]) if lookup[l] != -1 else -1)
            right_cnt = (r - idxs[lookup[r]][0] + 1 if lookup[r] != -1 else -1)

            # A: two full runs strictly inside (l, r)
            if left <= right - 1:
                best = max(best, cnt1 + range_max(left, right - 1))
            # B: l and r both sit on 0-runs that are directly adjacent
            if s[l] == '0' and s[r] == '0' and lookup[l] + 1 == lookup[r]:
                best = max(best, cnt1 + left_cnt + right_cnt)
            # C: l sits on a 0-run; merge with the next full run
            if s[l] == '0' and lookup[l] + 1 <= right:
                best = max(best, cnt1 + left_cnt + idxs[lookup[l] + 1][1])
            # D: r sits on a 0-run; merge with the previous full run
            if s[r] == '0' and left <= lookup[r] - 1:
                best = max(best, cnt1 + right_cnt + idxs[lookup[r] - 1][1])

            ans.append(best)
        return ans
