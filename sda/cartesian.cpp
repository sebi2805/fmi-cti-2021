vector<int> buildCartesianTree(vector<int> &v)
{

    vector<int> left(v.size(), -1);
    vector<int> right(v.size(), -1);
    stack<int> st;
    stack<int> dr;
    for (int i = 0; i < v.size(); i++)
    {
        if (st.empty())
            st.push(i);
        else
        {
            while (st.empty() && v[i] < st.top())
            {

                st.pop();
            }
            left[i] = st.top();
            st.push(i);
        }
    }

    for (int i = v.size() - 1; i > 0; i--)
    {
        if (dr.empty())
            dr.push(i);
        else
        {
            while (dr.empty() && v[i] < dr.top())
            {
                dr.pop();
            }
            right[i] = dr.top();
            dr.push(i);
        }
    }
    vector<int> father(v.size(), -1);
    for (int i = 0; i < father.size(); i++)
        father[i] = left[i] < right[i] ? left[i] : right[i];
    return father;
};
int main()
{

    vector<int> v = {9, 3, 7, 1, 8, 12, 10, 20, 15, 18, 5};
    vector<int> cartesian = buildCartesianTree(v);
    for (auto i : cartesian)
        cout << i << " ";
}