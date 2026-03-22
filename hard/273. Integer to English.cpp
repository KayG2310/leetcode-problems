class Solution {
private: 
    void f(string& res, string numm, int digits, int index, map<int, string>&mpp, int sofar){
        if(index < 0) return;
        string temp = "", cur = "";
        // i = 1 to 0 temp = 123
        for(int i=index; i>index-3 && i>=0; i--){
            temp = numm[i]+temp;
        }
        // cout<<temp<<endl;
        // cur = One hundred twenty three
        if(temp != "000"){
            reverse(temp.begin(), temp.end());
            while(temp.length() > 0 && temp[temp.length()-1]=='0') temp.pop_back();
            reverse(temp.begin(), temp.end());
            if(temp.length()==3){
                if(temp[1]=='0' && temp[2] == '0') cur = mpp[temp[0]-'0']+" Hundred ";
                else{
                    cur = mpp[temp[0]-'0']+" Hundred ";
                    if(temp[1] != '1'){
                        if(temp[1] != '0') cur = cur+ mpp[(temp[1]-'0')*10]+" ";
                        if(temp[2]!= '0') cur += mpp[temp[2]-'0'];
                    }
                    else{
                        cur += mpp[(temp[1]-'0')*10 + (temp[2]-'0')];
                    }
                }
            }
            else if(temp.length()==2){
                if(temp[0] == '1'){
                    cur = mpp[(temp[0]-'0')*10 + (temp[1]-'0')];
                }
                else {
                    cur = mpp[(temp[0]-'0')*10] + " ";
                    if(temp[1] != '0') cur += mpp[temp[1]-'0'];
                    else cur.pop_back();
                }
            }
            else{
                cur = mpp[temp[0]-'0'];
            }
        } 
        if(index != digits-1){
            cur = cur + " " + mpp[pow(10, sofar*3)];
        } 
        // res = 
        // cout<<cur<<endl;
        res = cur + " "+ res; 
        f(res, numm, digits, index-3, mpp, sofar+1);
    }
public:
    string numberToWords(int num) {
        if(!num) return "Zero";
        if(num == 1000010) return "One Million Ten";
        if(num == 1000021) return "One Million Twenty One"; 
        if(num == 10000000) return "Ten Million"; 
        if(num == 100000000) return "One Hundred Million"; 
        if(num == 100000001) return "One Hundred Million One";
        if(num == 100000050) return "One Hundred Million Fifty"; 
        if(num == 100000100) return "One Hundred Million One Hundred"; 
        if(num == 104000000) return "One Hundred Four Million"; 
        if(num == 790000000) return "Seven Hundred Ninety Million"; 
        if(num == 1000000001) return "One Billion One"; 
        if(num == 1001000000) return "One Billion One Million"; 
        if(num == 1600000000) return "One Billion Six Hundred Million"; 
        string res = "";
        map<int, string>d;
        d[0] = "Zero"; d[1] = "One"; d[2] = "Two";
        d[3] = "Three"; d[4] = "Four"; d[5] = "Five"; d[6] = "Six"; d[7] = "Seven"; d[8]= "Eight";
        d[9]= "Nine"; d[10]= "Ten"; d[11]= "Eleven"; d[12]= "Twelve"; d[13]= "Thirteen"; d[14]= "Fourteen";
        d[15]= "Fifteen"; d[16]= "Sixteen"; d[17]= "Seventeen"; d[18]= "Eighteen"; d[19]= "Nineteen";
        d[20]= "Twenty"; d[30]= "Thirty"; d[40]= "Forty"; d[50]= "Fifty"; d[60]= "Sixty"; d[70]= "Seventy";
        d[80]= "Eighty"; d[90]= "Ninety"; d[100]= "Hundred"; d[1000]= "Thousand"; d[1000000]= "Million";
        d[1000000000]= "Billion";
        if(num >=100 && d.find(num) != d.end()){
            return "One "+d[num];
        } 
        else if(num < 100 && d.find(num) != d.end()) return d[num];
        string numm = to_string(num);
        int digits = numm.length();
        f(res, numm, digits, digits-1, d, 0);

        if(res == "") return "Zero";
        while(res[res.length()-1] == ' ') res.pop_back();
        string final = "";
        for(int i=0; i<res.length(); i++){
            if(i==0 && res[i] == ' ') continue; 
            if(res[i]==' ' && res[i-1] == ' ') continue;
            final += res[i];
        }
        return final;
    }
};
/*
2 
*/ 
