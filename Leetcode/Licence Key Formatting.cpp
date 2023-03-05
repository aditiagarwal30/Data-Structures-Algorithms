class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans="";
        string temp="";

        int n= s.size();
        int len=0;
        stack<int> st;

        for(int i=0;i<n;i++){
            if(s[i]!='-'){
                st.push(toupper(s[i]));
            }
        }

        if(st.size()==0) return ans;

        while(!st.empty()){
            if(len<k){
                temp+= st.top();
                st.pop();
                len++;
            }
            else{
                ans+= temp;
                ans+='-';
                temp="";
                len=0;
            }
        }
        
        if(temp!="") ans+=temp;
        else ans.pop_back();

        reverse(ans.begin(), ans.end());
        return ans;
    }
};