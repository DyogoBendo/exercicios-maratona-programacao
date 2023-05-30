#include <bits/stdc++.h>
using namespace std;
 
vector<int> primo;
bool check[50009];
int keep = 1;

void initialise(){
    check[1 ] = 1;
    for(int i = 3; i <= 224; i+=2){
        if(!check[i]){
            for(int j = i*i ; j<= 50000; j+=2*i)
                check[j] = true;
        }
    }
    primo.push_back(2);
    keep=1;
    for(int i = 3 ; i<= 50000 ; i++)
        if(check[i] == false && (i&1))
            primo.push_back(i) , keep++;
}


bool segment[1000009];


int main()
{
    int t;
    cin >> t;
    initialise();
    while(t--)
    {
        long long a , b;
        cin >> a >> b;
        if(b <= 50000){
            if(a <= 2)
                printf("2\n");
            for(int i = a ; i<= b ; i++){
                if(check[i] == false && (i&1))
                    printf("%d\n", i);
            }
            continue;
        }
        memset(segment, 0, sizeof segment);
        for(int i = 0; primo[i]*primo[i] <= b ; i++)
        {
            int begin = a/primo[i];
            begin *= primo[i];
            for(int j = begin ; j<= b ; j+= primo[i]){
                if(j < a)
                    continue;
                segment[j - a] = true;
            }
        }
        for(int i  = 0 ; primo[i]*primo[i] <= b ; i++){
            if(primo[i]>= a && primo[i]<=b)
                printf("%d\n",primo[i]);
        }
        for(int i = a==1 ? 1 : 0 ; i < b-a+1 ; i++)
            if(segment[i]==0)
                printf("%d\n", i+a);
    }
    return 0;
}