class Solution {
public:

    void solve(int idx,string& digits,string& temp,
    vector<string>& result,unordered_map<char,string>& mp){
      if(idx>=digits.size()){
        result.push_back(temp);
        return;
      }

      char ch=digits[idx];
      string s=mp[ch];

      for(int i=0;i<s.size();i++){
        //do
        temp.push_back(s[i]);
        //explore
        solve(idx+1,digits,temp,result,mp);
        //undo
        temp.pop_back();
      }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0){
          return {};
        }

        vector<string> result;

        unordered_map<char,string> mp;

        mp['2']="abc";
        mp['3']="def";
        mp['4']="ghi";
        mp['5']="jkl";
        mp['6']="mno";
        mp['7']="pqrs";
        mp['8']="tuv";
        mp['9']="wxyz";
        string temp="";

        solve(0,digits,temp,result,mp);

        return result;
    }
};