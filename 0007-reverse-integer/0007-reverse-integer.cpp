class Solution {
public:
    int reverse(int x) {
        string s = std::to_string(x);
        std::reverse(s.begin(), s.end());
        
        if (x < 0) {
            s.pop_back();
            long long z=stoll(s);
            if(-z<INT_MIN){
              return 0;
            }
            x = std::stoi(s);
            x = -x;
        }
        else {
            long long z=stoll(s);
            if(z>INT_MAX){
              return 0;
            }
            x = std::stoi(s);
        }

        return x;
    }
};