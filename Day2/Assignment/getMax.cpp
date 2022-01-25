stack<int> st;
vector<int> getMax(vector<string> q)
{
    vector<int> ans;
    for(auto i:q)
    {
        if(i[0]=='2')
        {
            st.pop();
        }
        else if(i[0]=='3')
        {
            int m=INT_MIN;
            stack<int> temp;
            while(st.size())
            {
                int c=st.top();
                m=max(m,c);
                temp.push(c);
                st.pop();
            }
            ans.push_back(m);
            while(temp.size())
            {
                st.push(temp.top());
                temp.pop();
            }
        }
        else
        {
            int val=0;
            for(int j=2;j<i.size();j++)
            {
                val=(val*10)+(i[j]-'0');
            }
            st.push(val);
        }
    }
    return ans;
}