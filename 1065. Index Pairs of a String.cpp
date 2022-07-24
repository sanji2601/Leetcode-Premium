/*
Given a string text and an array of strings words, return an array of all index pairs [i, j] so that the substring text[i...j] is in words.

Return the pairs [i, j] in sorted order (i.e., sort them by their first coordinate, and in case of ties sort them by their second coordinate).

 

Example 1:

Input: text = "thestoryofleetcodeandme", words = ["story","fleet","leetcode"]
Output: [[3,7],[9,13],[10,17]]
Example 2:

Input: text = "ababa", words = ["aba","ab"]
Output: [[0,1],[0,2],[2,3],[2,4]]
Explanation: Notice that matches can overlap, see "aba" is found in [0,2] and [2,4].
 

Constraints:

1 <= text.length <= 100
1 <= words.length <= 20
1 <= words[i].length <= 50
text and words[i] consist of lowercase English letters.
All the strings of words are unique.
*/
class Solution {
public:
    vector<vector<int>> indexPairs(string text, vector<string>& words) {
       vector<vector<int>>result;
        map<string,int>m;
        for(auto it:words)
        {
            m[it]++;
        }
        for(auto it:m)
        {
           string s;
            s = it.first;
           int sSize = s.size();
           if(sSize==text.size())
           {
               if(s==text){
               int startpoint = 0;
               int endpoint = sSize-1;
               result.push_back({startpoint,endpoint});
               }
           }
            else if(sSize>text.size())
            {
                continue;
            }
            else
            {
                for(int i=0;i<text.size()-s.size()+1;i++)
                {
                    if(text.substr(i,sSize)==s)
                    {
                        int startpoint = i;
                        int endpoint = i+sSize-1;
                        result.push_back({startpoint,endpoint});
                    }
                }
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};