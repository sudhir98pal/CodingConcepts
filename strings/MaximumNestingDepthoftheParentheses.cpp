class Parantheses
{
    public:
    string input;
    Parantheses(string s)
    {
        this->input=s;
    }
    int maxDepthInParantheses();
    
    
};

int Parantheses::maxDepthInParantheses()
{
    int max=0;
    int n=input.size();
    int depth=0;
    for(int i=0;i<n;i++)
    {
        if(input[i]=='(')
        {
            depth++;
            if(depth>max)
            {
                max=depth;
            }
         
        }
        if(input[i]==')')
        {
           
            if(depth>0)
            {
                 depth--;
            }
            else
            {
              return -1;
                // Invalid input case;
            }
        }
    }

    if(depth!=0) return -1;
    return max;
}


class Solution
{
public:
    int maxDepth(string s)
    {
   Parantheses p(s);
        return p.maxDepthInParantheses();
  

  
    }
};
