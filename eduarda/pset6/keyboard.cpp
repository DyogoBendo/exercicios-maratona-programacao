#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;

    vector<bool> visited(26, false);
    vector<vector<int>> vertices(26);
    //adding values
    for(int i = 0; i < n; i++){
        string input;
        cin >> input;
        int x = input.size();
        int start = 0;
        int end = 1;
        while(x--){
            int a = static_cast<int>(input[start]) - 97;
            int b = static_cast<int>(input[end]) - 97;
            if(b == input.size()){
                break;
            }else{
                vertices[a].push_back(b);
                vertices[b].push_back(a);
            }
            start++, end++;
        }
    }


}


//check if there is a cycle
void dfs(){

}