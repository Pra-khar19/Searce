#include<bits/stdc++.h>
using namespace std;

typedef long long int LL;

int n;
struct order{
    LL T, L;
}customer[100010];

bool operator < (order a, order b)
{
    return a.T < b.T;
}

bool compare(order a, order b)
{
    return a.L > b.L;
}
priority_queue<order, vector<order>, function<bool(order, order)>> min_heap(compare);

void add_order(order current_order, LL &current_time)
{
    if(min_heap.empty() == true)
        current_time = max(current_time, current_order.T);
    min_heap.push(current_order);
}

LL serve_order(LL &current_time)
{
    order current_order = min_heap.top();
    min_heap.pop();
    current_time += current_order.L;
    return current_time - current_order.T;
}

LL solve(int n)
{
    LL current_time = 0, total_waiting_time = 0;
    for(int i = 1; i<=n; i++)
    {
        if(i == 1 || customer[i].T <= current_time)
            add_order(customer[i], current_time);
        else if(min_heap.empty() == false)
        {
            while(min_heap.empty() == false && customer[i].T > current_time)
                total_waiting_time += serve_order(current_time);
            add_order(customer[i], current_time);
        }
    }
    while(min_heap.empty() == false)
        total_waiting_time += serve_order(current_time);
    return total_waiting_time/n;
}
int main()
{
    cin >> n;
    for(int i = 1; i<=n; i++)
        cin >> customer[i].T >> customer[i].L ;
    sort(customer+1, customer+n+1);
    cout << solve(n) << endl;
    return 0;
}