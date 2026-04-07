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
        // Base cases
        if (intervals.size() <= 1) return true;
        
        std::sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        int earliestStart = intervals[0].start;
        int latestEnd = intervals[0].end;
        for (int i = 1; i < intervals.size(); i++) {
            if (earliestStart != intervals[i].start) {
                earliestStart = intervals[i].start;
                if (latestEnd > earliestStart) return false;
                latestEnd = intervals[i].end;
                continue;
            }
            if (intervals[i].start < latestEnd) return false;
            earliestStart = intervals[i].start;
            latestEnd = intervals[i].end;
        }
        return true;
    }
};
