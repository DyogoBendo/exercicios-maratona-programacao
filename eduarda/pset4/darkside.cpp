#include <bits/stdc++.h>
using namespace std; 
#define ll long long


int main(){
    int n;
    cin >> n;
    
    vector<ll> sum_total, sum_min, minimum;
    int a, b, c;
    ll sum;
    for(int i = 0; i < n; i++){
        scanf("%d %d %d", &a, &b, &c);
        sum = a + b + c;
        sum_total.push_back(sum);
        int d = max({a, b, c});
        sum_min.push_back(sum - d);
    }

    minimum = sum_min;
    sort(sum_min.begin(), sum_min.end());

    for(int i=0; i<n; i++){
        int it = upper_bound(sum_min.begin(), sum_min.end(), (sum_total[i] - 2)) - sum_min.begin();
        if(minimum[i] <= (sum_total[i] - 2)) it--;
        printf("%d ", it);
    }
}