/*
Question: 

(((abc))) --> abc
(ab(c)) --> ab(c)
(abc09%(c)) --> abc09%(c)
ab(c) --> ab(c)
(ab)c --> (ab)c
abc(c)) → INVALID
(abc)(def) --> (abc)(def)
(abc)typ(def) --> (abc)typ(def)
((abc)(def)) --> (abc)(def)

Tags - Amazon

Question - https://www.careercup.com/question?id=5743979809734656

Solution - Time Complexity O(n)
           Space Complexity O(n) ( Can be reduced further )

*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
    
    string expression;
    cin>>expression;
    string s=expression;
    stack <int> exp_idx;
    bool is_invalid = 0;
    
    /*if while iterating i get a ')' and the top of the stack is '(' the bracket pair is redundant, so we place '$' signs in those places
    */
    for(int i=0;i<expression.length();i++)
    {
        if(expression[i]==')')
        {
            if(!exp_idx.empty() and expression[exp_idx.top()]=='(')
            {
                expression[exp_idx.top()]='$';
                expression[i]='$';
                exp_idx.pop();
            }
            else
            {
            
                while(!exp_idx.empty() and expression[exp_idx.top()]!='(')
                    exp_idx.pop();
                if(exp_idx.empty())
                {
                    i=expression.length();
                    is_invalid=1;
                }
                else
                {
                    exp_idx.pop();
                }
            }
            
        }
        else
            exp_idx.push(i);
        
    }
    
    //special check for the removal of first and last bracket
    
    int front=0,back=expression.length()-1;
    
    while(front<expression.length() and expression[front]=='$')
        front++;
    while(back>=0 and expression[back]=='$')
        back--;
        
    
    if(front<back and expression[front]=='(' and expression[back]==')')
    {
        int i=front;
        int bracket_balance=0;
        while(i<back)
        {
            if(expression[i]=='(')
                bracket_balance++;
            else if(expression[i]==')')
            {
                bracket_balance--;
                if(bracket_balance==0)
                    break;
            }
            i++;
        }
        if(i==back)
            expression[front]=expression[back]='$';
    }
    // special check ends
    
    if(is_invalid)
        cout<<"INVALID EXPRESSION";
    else
        for(auto it:expression)
            if(it!='$') cout<<it;
    
    return 0;    
}