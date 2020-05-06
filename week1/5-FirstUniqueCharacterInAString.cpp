'''
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
'''
class Solution {
public:
    int firstUniqChar(string s) {
       ios_base::sync_with_stdio(false);//fast execution time
       cin.tie(NULL); //fast execution time
       int map[26]={0};
       int i=0;
        for (; i < s.size(); i++) {
            map[s[i] - 'a']++;
        }
        for (i = 0; i < s.size(); i++) {
            if (map[s[i] - 'a'] == 1) return i;
        }
        return -1;
        
    }
};

''' brute force approach '''
class Solution {
public:
    int firstUniqChar(string s) {
        if (s.size() == 0) return -1;
        int j = 0;
        for (int i = 0; i < s.size(); i++) {
        for (j = 0; j < s.size(); j++) {
            if (i == j) continue;
            if (s[i] == s[j]) break;
        }
        if (j == s.size()) return i;
     }
     return -1;
     }
};