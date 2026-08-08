class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> result;
        vector<bool> taken(numCourses, false);

        // Keep looping until we can't take any more courses
        while (result.size() < numCourses) {
            bool progressMade = false;

            for (int course = 0; course < numCourses; course++) {
                // Skip if already taken
                if (taken[course]) continue;

                // Check if ALL prerequisites for this course are already taken
                bool canTake = true;
                for (const auto& pre : prerequisites) {
                    if (pre[0] == course && !taken[pre[1]]) {
                        canTake = false; // Missing a prerequisite!
                        break;
                    }
                }

                // If all prerequisites are satisfied, take the course!
                if (canTake) {
                    taken[course] = true;
                    result.push_back(course);
                    progressMade = true;
                }
            }

            // If we went through a full loop and couldn't take ANY new course, 
            // there is a cycle (impossible to finish).
            if (!progressMade) {
                return {};
            }
        }

        return result;
    }
};
