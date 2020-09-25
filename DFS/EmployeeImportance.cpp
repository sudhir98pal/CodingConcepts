/*
// Employee info
class Employee {
public:
    // It's the unique ID of each node.
    // unique id of this employee
    int id;
    // the importance value of this employee
    int importance;
    // the id of direct subordinates
    vector<int> subordinates;
};
*/
class Solution {
public:
    int sum=0;
    int get_index(vector<Employee*>&e,int x)
    {
        for(int i=0;i<e.size();i++)
        {
            if(e[i]->id==x)
            {
                return i;
            }
        }
        
        return -1;
    }
    void dfs(vector<Employee*>&e,int x)
    {
        if(x==-1)
        {
            return ;
        }
        sum+=e[x]->importance;
        for(int i=0;i<e[x]->subordinates.size();i++)
        {
            dfs(e,get_index(e,e[x]->subordinates[i]));
        }
    }
    int getImportance(vector<Employee*> employees, int id)
    {
        int x=get_index(employees,id);
        dfs(employees,x);
        return sum;
    }
};
