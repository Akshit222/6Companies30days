//Qs Link - https://leetcode.com/problems/bulls-and-cows/description/
class Solution {
public:
    string getHint(string secret, string guess) {
        int Bulls = 0, Cows = 0;
        unordered_map<char, int> countMap;

        // Step 1: Count bulls and record unmatched characters
        for (int i = 0; i < secret.size(); i++) {
            if (secret[i] == guess[i]) {
                Bulls++;
            } else {
                countMap[secret[i]]++; // Track frequency of unmatched characters in secret
            }
        }

        // Step 2: Count cows
        for (int i = 0; i < guess.size(); i++) {
            if (secret[i] != guess[i] && countMap[guess[i]] > 0) {
                Cows++;
                countMap[guess[i]]--; // Decrement count for matched cow character
            }
        }

        // Step 3: Construct result string
        return to_string(Bulls) + "A" + to_string(Cows) + "B";
    }
};
