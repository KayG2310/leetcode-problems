class Solution {
public:
    string intToRoman(int num) {
        unordered_map<char, int>mpp;
        mpp['I'] = 1;
        mpp['V'] = 5;
        mpp['X'] = 10;
        mpp['L'] = 50;
        mpp['C'] = 100;
        mpp['D'] = 500;
        mpp['M'] = 1000;
        vector<int>expanded;
        int place = 0;
        while(num > 0){
            int x = num%10;
            expanded.push_back(x*pow(10, place));
            num = num/10;
            place++;
        }
        reverse(expanded.begin(), expanded.end());
        // eg 3749 = 3000 + 700 + 40 + 9
        string ans = "";
        for(int n : expanded){
            if(n>=1000){
                int r = n/1000;
                while(r--){
                    ans += 'M';
                }
            }
            else if(n==900) ans += "CM";
            else if(n==400) ans += "CD";
            else if(n==500) ans += 'D';
            else if(n>=100 && n<400){
                int r = n/100;
                while(r--){
                    ans += 'C';
                }
            }
            else if(n > 500 && n<1000){
                ans += 'D';
                n = n-500;
                int r = n/100;
                while(r--){
                    ans += 'C';
                }
            }
            else if(n==90) ans += "XC";
            else if(n==40) ans += "XL";
            else if(n==50) ans += 'L';
            else if(n>=10 && n<40){
                int r = n/10;
                while(r--){
                    ans += 'X';
                }
            }
            else if(n > 50 && n<100){
                ans += 'L';
                n = n-50;
                int r = n/10;
                while(r--){
                    ans += 'X';
                }
            }
            else if(n==9) ans += "IX";
            else if(n==4) ans += "IV";
            else if(n==5) ans += 'V';
            else if(n>=1 && n<4){
                while(n--){
                    ans += 'I';
                }
            }
            else if(n > 5 && n<10){
                ans += 'V';
                n = n-5;
                while(n--){
                    ans += 'I';
                }
            }
        }
        return ans;
    }
};
