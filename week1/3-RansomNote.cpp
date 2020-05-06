'''
Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom note can be constructed from the magazines ; otherwise, it will return false.

Each letter in the magazine string can only be used once in your ransom note.

Note:
You may assume that both strings contain only lowercase letters.

canConstruct("a", "b") -> false
canConstruct("aa", "ab") -> false
canConstruct("aa", "aab") -> true

'''

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(ransomNote.length()>magazine.length())
            return false;
        else
        {        
            int count=0;
            for(char a: ransomNote)
            {   for(int i=0;i<magazine.length();i++)
                {
                    if(a==magazine[i])
                    {   count++;
                        magazine.erase(magazine.begin() + i);
                        break;
                    }
                }        
            
            }
        
            if(ransomNote.length()==count)
              return true;
            else 
              return false;
            
         }             
        }
};

''' O(n) time complexity solution '''
class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        
        unordered_map<char,int> m;
        
        for(auto i : magazine)
            m[i]++;
        
        for(auto i: ransomNote)
            if(m[i]--<=0)return false;
        
        return true;
    }
};
