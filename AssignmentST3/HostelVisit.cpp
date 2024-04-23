#include<bits/stdc++.h>
using namespace std;

int main(){
    long long t, k, cs = 0;
    cin >> t >> k;
    priority_queue<long long, vector<long long>> h;
    for(int i=0;i<t;i++){
        long long a,x,y,num;
        cin >> a;
        if(a == 1){
            cin >> x >> y;
            num = x * x + y * y;
            if(cs < k){
                h.push(num);
                cs++;
            }
            else{
                if(num < h.top()){
                    h.pop();
                    h.push(num);
                }
            }
        }
        else{
            cout << h.top() << endl;
        }
    }
}