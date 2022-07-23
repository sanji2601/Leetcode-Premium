/*
Given an array of meeting time intervals where intervals[i] = [starti, endi], determine if a person could attend all meetings.

 

Example 1:

Input: intervals = [[0,30],[5,10],[15,20]]
Output: false
Example 2:

Input: intervals = [[7,10],[2,4]]
Output: true
 

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti < endi <= 106
*/
class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        vector<int>startpoint;
        vector<int>endpoint;
        
        for(int i=0;i<intervals.size();i++)
        {
            int start = intervals[i][0];
            int end = intervals[i][1];
            
            startpoint.push_back(start);
            endpoint.push_back(end);
        }
        sort(startpoint.begin(),startpoint.end());
        sort(endpoint.begin(),endpoint.end());
        
        int i=0;
        int j=0;
        int counter=0;
        
        while(i<startpoint.size())
        {
            if(startpoint[i]<endpoint[j])//if another meeting gets started within the eneding time of currently running meeting that's startpoint<endpoint
            {
                counter++;
                i++;
            }
            else
            {
               i++;
               j++;
            }
        }
        //cout<<counter;
        return counter>1? false:true;
    }
};
