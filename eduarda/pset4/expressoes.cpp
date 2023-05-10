#include <bits/stdc++.h>
using namespace std;

bool cadeia(string expressions){
    stack<char> stackers;
    for(int i = 0; i < expressions.size(); i++){
        if(expressions[i] == '(' || expressions[i] == '[' || expressions[i] == '{'){
            stackers.push(expressions[i]);
        }else if (expressions[i] == ')' || expressions[i] == ']' || expressions[i] == '}'){
            if(stackers.empty()){
                return false;
            }else{
                char top = stackers.top();
                if(
                    (expressions[i] == ')' && top != '(') ||
                    (expressions[i] == '}' && top != '{') ||
                    (expressions[i] == ']' && top != '[')
                ){
                    return false;
                }else{
                    stackers.pop();
                }
            }
        }
    }
    return true;
}

int main(){
    int n;
    cin >> n;

    vector<char> result;
    for(int i = 0; i < n; i++){
        string expressions;
        cin >> expressions;
        cadeia(expressions) ? result.push_back('S') : result.push_back('N');
    }

    for(int i = 0; i < n; i ++){
        cout << result[i] << endl;
    }
}