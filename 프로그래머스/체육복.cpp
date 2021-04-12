#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> stock;
    stock.assign(n,1);
    
    for(int i=0 ; i<reserve.size() ; i++)
    {
        stock[reserve[i]]+=1;
    }
    
    for(int i=0;i<lost.size();i++)
    {
        stock[lost[i]]-=1;
    }
    
    for(int i=0; i<stock.size();i++)
    {   
        if(i==0)
        {
            if(stock[0] == 2 && stock[1] == 0 )
            {
                stock[0]-=1;
                stock[1]+=1;
            }
        }
        if(i == stock.size()-1)
        {
            if(stock[i]==2 && stock[i-1] == 0)
            {
                stock[i]-=1;
                stock[i-1]+=1;
                break;
            }
        }
        if(stock[i]==2)
        {
            if(stock[i-1] == 0)
            {
                stock[i]-=1;
                stock[i-1]+=1;
            }
            
            else if(stock[i+1] == 0)
            {
                stock[i]-=1;
                stock[i+1] +=1;
            }
        }  
    }
    for(int i=0; i<stock.size();i++)
    {
        if(stock[i]!=0) answer+=1;
    }
    
    return answer;
}