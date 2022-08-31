#include<bits/stdc++.h>
using namespace std;

int main(){
        string s = "()";
        map<char,char>mp;
        mp['('] = ')';
        mp['{'] = '}';
        mp['['] = ']';

        stack<int>stack;
        for(int i=0;i<s.size();i++){  
            if(s[i]=='(' || s[i]=='{' || s[i]=='['){
                stack.push(s[i]);
                cout<<s[i]<<" is pushed into the stack"<<endl;
            }
            
            else{
                if(s[i]==mp[stack.top()]){
                    cout<<stack.top()<<" is pop from the stack"<<endl;
                    stack.pop();
                    cout<<stack.top()<<endl;
                }
                else{
                    stack.push(s[i]);
                    cout<<s[i]<<" is pushed into the stack"<<endl;
                }
            }
        }
        if(stack.empty()){
            cout<<"true";
        }
        else{
            cout<<"false";
        }
 }