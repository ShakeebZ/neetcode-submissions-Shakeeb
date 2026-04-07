/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        if (intervals.size() < 2) return true;
        std::sort(intervals.begin(), intervals.end(),
            [](Interval a, Interval b) {
                return a.start < b.start;
        });
        int earliestStart = intervals.at(0).start;
        int latestEnd = intervals.at(0).end;

        for (int i = 1; i < intervals.size(); i++) {
            if (intervals.at(i).start != earliestStart) {
                earliestStart = intervals.at(i).start;
                if (earliestStart < latestEnd) {
                    return false;
                }
                latestEnd = intervals.at(i).end;
                continue;
            }
            return false;
        }
        return true;
    }
};
