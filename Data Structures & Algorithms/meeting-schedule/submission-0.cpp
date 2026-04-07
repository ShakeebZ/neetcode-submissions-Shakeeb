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
        std::unordered_set<int> booked;
        int start, end;
        for (Interval i : intervals) {
            start = i.start;
            end = i.end;
            while (start != end) {
                if (booked.count(start)) {
                    return false;
                }
                booked.insert(start);
                start++;
            }
        }
        return true;
    }
};
