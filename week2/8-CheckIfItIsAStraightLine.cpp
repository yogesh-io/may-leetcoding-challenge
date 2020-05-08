'''
Check If It Is a Straight Line
==============================
URL: https://leetcode.com/explore/featured/card/may-leetcoding-challenge/535/week-2-may-8th-may-14th/3323/
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. Check if these points make a straight line in the XY plane.
Example 1:
Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true
Example 2:
Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
'''
class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        
        if(coordinates.size()<=2)
            return true;
        
        float x1 = coordinates[0][0];
        float y1 = coordinates[0][1];
        float x2 = coordinates[1][0];
        float y2 = coordinates[1][1];
        float initialSlope = (y2-y1)/(x2-x1);
        float currSlope;
        
        for(int i=2;i<coordinates.size();i++){
            
            x2 = coordinates[i][0];
            y2 = coordinates[i][1];
            currSlope = (y2-y1)/(x2-x1);
            
            if(currSlope!=initialSlope)
                return false;
        }
        return true;
    }