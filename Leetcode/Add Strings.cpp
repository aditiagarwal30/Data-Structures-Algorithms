class Solution {
public:
    string addStrings(string num1, string num2) {
       int n = num1.size()-1;
        int m = num2.size()-1;
        string answer;
        int carry=0;
        while(n>=0 || m>=0 ||carry){
            long sum=0;
            if(n>=0){
                sum+=(num1[n]-'0');
                n--;
            }
            if(m>=0){
                sum+=(num2[m]-'0');
                m--;
            }
            sum+=carry;
            carry=sum/10;
            sum=sum%10;
            sum+=48;
            answer.push_back(sum);
        }
        reverse(answer.begin(),answer.end());
        return answer; 
    }
};