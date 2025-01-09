//Qs Link - https://leetcode.com/problems/bulls-and-cows/submissions/1502612110/
class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls=0;
        unordered_map<char,int>mp;
        string ng="";
        for(int i=0;i<secret.size();i++){
            if(secret[i]==guess[i]){
                bulls++;
            }
            else{
                ng+=guess[i];
                mp[secret[i]]++;
            }
        }
        int cows=0;
        for(int i=0;i<ng.size();i++){
            if(mp.find(ng[i])!=mp.end()){
                cows++;
                mp[ng[i]]--;
                if(mp[ng[i]]==0){
                    mp.erase(ng[i]);
                }
            }
        }
        string ans="";
        ans+=to_string(bulls);
        ans+='A';
        ans+=to_string(cows);
        ans+='B';
        return ans;
    }
};
