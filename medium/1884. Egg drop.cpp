class Solution {
public:
    int twoEggDrop(int n) {
        int steps = 0, i=1, j = 0;
        int x = n;
        while(x>0){
            x = n-i-j;
            j += i;
            i++;
            steps++;
        }
        return steps;
    }
};
