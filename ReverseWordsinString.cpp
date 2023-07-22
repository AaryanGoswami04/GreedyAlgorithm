//Given a String S, reverse the string without reversing its individual words. Words are separated by dots.
 //Function to reverse words in a given string.
//TC:O(S), SC:O(S)
    string reverse(string& s){
        int i=0, j=s.size()-1;
        
        while(i<j){
            swap(s[i],s[j]);
            i++;
            j--;
        }
        return s;
    }
    string reverseWords(string S) 
    { 
        int n=S.size();
        string temp="", res="";
        
        for(int i=n-1; i>=0; i--){
            if(S[i] == '.'){
                res += reverse(temp) + '.';
                temp="";
            }
            
            else temp.push_back(S[i]);
        }
        
        temp = reverse(temp); //To reverse the first word of string S as it is not handled by the loop
        res += temp;
        
        return res;
    } 
