#include "string"
#include "map"
using namespace std;

class Solution_1 {
public:
    bool isAnagram(string s, string t) 
    {   
        map<char, int> source;
        for (int i = 0; i < s.size(); i++) {
            if (source.find(s[i]) == source.end()) {
                source.insert(pair<char, int>(s[i], 1));
            }
            else {
                auto iter = source.find(s[i]);
                iter->second++;
            }
        }
        for (int i = 0; i < t.size(); i++) {
            if (source.find(t[i]) == source.end()) {
                return false;
            }
            else {
                auto iter = source.find(t[i]);
                iter->second--;
                if (iter->second == 0) {
                    source.erase(iter);
                }
            }
        }
        return source.empty();
    }
};

class Solution_2 {
public:
    bool isAnagram(string s, string t) 
    {
        int record[26] = {0};
        
        for(int i =0; i < s.size(); i++)
        {
            record[s[i] - 'a']++;
        }
        
        for(int i = 0; i < t.size(); i++)
        {
            record[t[i] - 'a']--;
        }
        
        for(int i = 0; i < 26; i++)
        {
            if(record[i] != 0)
            {
                return false; 
            }
            
        }
       return true;
    }
};