//Balance Brackets

#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string s){

    stack<char> st;
    for(char c: s){
        if(c=='[' || c=='{' || c=='(')
            st.push(c);
        else{
            if(st.size() == 0)
                return false;
            char ch = st.top();
            if( ( c==']' && ch == '[' ) ||( c=='}' && ch == '{' ) || ( c==')' && ch == '(' ))
                st.pop();
            else
                return false;
            } 
    }

    return st.empty();

}

int main(){
    string str;
    cout<<"Enter string of brackets: ";
    cin>>str;

    if(isBalanced(str))
        cout<<"The string of brackets is balanced.";
    else
        cout<<"The string of brackets is not balanced!";
}