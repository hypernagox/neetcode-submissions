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
    bool canAttendMeetings(vector<Interval>& intervals)
    {
        sort(intervals.begin(),intervals.end(),[](const auto a, const auto b){
            return a.end < b.end;
        });
        int cur_e = 0;
        for(const auto [s, e] : intervals)
        {
            if(cur_e > s)return false;
            cur_e = e;
        }
        return true;
    }
};
