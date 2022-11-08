#include <stdio.h>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <sstream>

using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int idx = 0;

        unordered_map<int,string> map = {};
        vector <char> vec_end = {')',']','}'};
        vector <char> vec_start = {'(','[','{'};


        if (s.size()%2 == 1) return false;

        if (s.size()==0) return true;
        for (char x : vec_start)
            if (s[s.size()-1] == x)
                return false;

        while (idx < s.size()){
            for(int i=0; i<3;i++){
                cout << idx << ' '<<s.size() << endl;
                if (s[idx] == vec_end[i]){
                    if (idx == 0) 
                        return false;
                    if (s[idx-1] == vec_start[i]){
                        s   = s.erase(idx-1,2);
                        idx = max(0,idx-2);
                        if (s.size()==0) return true;
                        for (char x : vec_start)
                            if (s[s.size()-1] == x)
                                return false;
                    }
                    else 
                        return false;
                }

            }
            idx++;
        }
        return true;
    }
};

int main(){
    Solution s ;
    vector<string> vec = {"()","()[]{}","(]","{[]}","({{{{}}}))","[[[]"};
    for(string str : vec){
        bool ans = s.isValid(str);
        cout << str+": " << ans << endl;
    }

    return 0;
}

class Solution2 {
public:
    bool isValid(string s) {
        stack<char> st;  //taking stack for keep tracking the order of the brackets..
        for(auto i:s)  //iterate over each and every elements
        {
            if(i=='(' or i=='{' or i=='[') st.push(i);  //if current element of the string will be opening bracket then we will just simply push it into the stack
            else  //if control comes to else part, it means that current element is a closing bracket, so check two conditions  current element matches with top of the stack and the stack must not be empty...
            {
                if(st.empty() or (st.top()=='(' and i!=')') or (st.top()=='{' and i!='}')\
                    or (st.top()=='[' and i!=']')) return false;
                st.pop();  //if control reaches to that line, it means we have got the right pair of brackets, so just pop it.
            }
        }
        return st.empty();  //at last, it may possible that we left something into the stack unpair so return checking stack is empty or not..
    }
};