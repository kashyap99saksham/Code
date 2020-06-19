/*
There are given N ropes of different lengths, we need to connect these ropes into one rope. The cost to connect two ropes is equal to sum of their lengths. The task is to connect the ropes with minimum cost.

Input:
The first line of input contains an integer T denoting the number of test cases. The first line of each test case is N where N is the number of ropes. The second line of each test case contains N input L[i],length of ropes.

Output:
For each testcase, print the minimum cost to connect all the ropes.

Constraints:
1 ≤ T ≤ 100
1 ≤ N ≤ 106
1 ≤ L[i] ≤ 106

Example:
Input:
2
4
4 3 2 6
5
4 2 7 6 9

Output:
29
62

Explanation:
For example if we are given 4 ropes of lengths 4, 3, 2 and 6. We can connect the ropes in following ways.
1) First connect ropes of lengths 2 and 3. Now we have three ropes of lengths 4, 6 and 5.
2) Now connect ropes of lengths 4 and 5. Now we have two ropes of lengths 6 and 9.
3) Finally connect the two ropes and all ropes have connected.

Total cost for connecting all ropes is 5 + 9 + 15 = 29. This is the optimized cost for connecting ropes. Other ways of connecting ropes would always have same or more cost. For example, if we connect 4 and 6 first (we get three strings of 3, 2 and 10), then connect 10 and 3 (we get two strings of 13 and 2). Finally we connect 13 and 2. Total cost in this way is 10 + 13 + 15 = 38
*/







#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++) cin>>a[i];

        priority_queue<int, vector<int>, greater<int> > minh; // min heap

        for(int i=0;i<n;i++)
            minh.push(a[i]);

        long long cost=0;
        while(minh.size()>=2){
            int r1=minh.top();
            minh.pop();
            int r2=minh.top();
            minh.pop();
            cost+=r1+r2;
            minh.push(r1+r2);
        }

        cout<<cost<<endl;
    }

return 0;
}
