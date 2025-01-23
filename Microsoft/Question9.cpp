//Qs Link - https://leetcode.com/problems/repeated-dna-sequences/
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> result;
        if (s.length() <= 10) {
            return result;
        }
        
        unordered_map<string, int> substringCount;

        for (int i = 0; i <= s.length() - 10; ++i) {
            string substring = s.substr(i, 10); 
            substringCount[substring]++;     
        }

        for (const auto& pair : substringCount) {
            if (pair.second > 1) {
                result.push_back(pair.first); 
            }
        }
        
        return result;
    }
};
