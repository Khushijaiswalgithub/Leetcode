class Solution {
public:
    int minMaxDifference(int num) {
        string s1=to_string(num);
        string s2=s1;
        int ind=s1.find_first_not_of('9');
        if(ind!=string::npos){
            char ch=s1[ind];
            replace(begin(s1),end(s1),ch,'9');
        }
        char x=s2[0];
        replace(begin(s2),end(s2),x,'0');
        return stoi(s1)-stoi(s2);
    }
};