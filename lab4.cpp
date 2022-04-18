#include<bits/stdc++.h>
using namespace std;
int main()
{
       int sizeofpage;
        cin>>sizeofpage;
        map<int,int>sizeleftinpage;
        vector<map<int,int>>recordfinder;
        vector<map<int,int>>recordposition;
    while (true)
    {
        int n;
        cin >> n;
        if (n == 1)
        {
            int x;
            cin >> x;
            int primarykey;
            cin>>primarykey;
            if(sizeleftinpage.size()==0)
            {
                sizeleftinpage[0]=sizeofpage-16-x-4;
              
                map<int,int>temp;
                temp[primarykey]=1;//just something to initialize as nothing specific is stored;
                map<int,int>tem2;
                tem2[primarykey]=0;
                recordfinder.push_back(temp);
                recordposition.push_back(tem2);

            }
            else
            {
                int inser=0;
                for (auto i = sizeleftinpage.begin(); i !=sizeleftinpage.end(); i++)
                {
                   if(x+4<=i->second)
                   {
                      i->second=i->second-(x+4);
                      recordfinder[i->first][primarykey]=1;
                      recordposition[i->first][primarykey]=recordfinder[i->first].size()-1;
                    //   cout<<i->first<<" "<<recordposition[i->first].size();
                      inser=1;
                      break;
                   }
                }
                if(inser==0)
                {
                    sizeleftinpage[sizeleftinpage.size()]=sizeofpage-16-x-4;
               
                map<int,int>temp;
                temp[primarykey]=1;//just something to initialize as nothing specific is stored;
                map<int,int>tem2;
                tem2[primarykey]=0;
                recordfinder.push_back(temp);
                recordposition.push_back(tem2);
                }
                
            }
           
        }
        if (n == 2)
        {
            cout<<sizeleftinpage.size()<<" ";
            for (auto i = sizeleftinpage.begin(); i !=sizeleftinpage.end(); i++)
            {
               cout<<recordfinder[i->first].size()<<" ";
            }
            cout<<endl;
      
        }
        if (n == 3)
        {
            int key;
            cin>>key;
            int found=0;
          
             for (auto i = sizeleftinpage.begin(); i !=sizeleftinpage.end(); i++)
            {
               if(recordposition[i->first].find(key)!=recordposition[i->first].end())
               {
                   found=1;
                   cout<<i->first<<" "<<recordposition[i->first][key]<<endl;
                   break;
               }
            }
            if(found==0)
            {
                cout<<-1<<" "<<-1<<endl;
            }
            
            
        }
        if (n==4)
        {
            break;
        }
        
    }
}