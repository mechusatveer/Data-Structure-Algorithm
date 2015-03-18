#include<iostream>
#include<vector>
#include<map>

#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include<string.h>
#include<stdio.h>


using namespace std;

struct Node
{
    string name;
    bool visited;
    vector<Node*> childs;
};

void ProcessLine(string str1,map<string,Node*> &mp)
{
    char* str = (char*)str1.c_str();
    char* parent = strtok(str,":");

    int len = strlen(parent);
    if(parent[len-1] == ' ')
    parent[len-1] = '\0';


    if(mp[parent] == NULL)
    {
        Node* node = new Node();
        node->name = parent;
        node->visited = false;
        node->childs.clear();
        mp[parent] = node;

    }


    char* temp = strtok(NULL,",");

    while(temp != NULL)
    {
    	if(*temp == ' ')
    	++temp;

         Node *obj = mp[temp];

         if(obj != NULL)
         {
             mp[parent]->childs.push_back(obj);
         }
         else
         {
              Node* node = new Node();
              node->name = temp;
              node->visited = false;
              node->childs.clear();
              mp[temp] = node;
              mp[parent]->childs.push_back(node);

         }
         temp = strtok(NULL,",");
    }

}

void DFSUtil(Node* root)
{


    if(root != NULL && root->visited == false)
    {
        root->visited = true;
        vector<Node*>::iterator it = root->childs.begin();
        for(it = root->childs.begin(); it != root->childs.end(); ++it)
        {
              DFSUtil(*it);
        }
    }
}

int main()
{
    string line;
    map<string,Node*> mp;
    while(getline(cin,line))
    {
        ProcessLine(line,mp);
    }


    DFSUtil(mp["Nick Fury"]);

    map<string,Node*>::iterator it = mp.begin();

     for(it = mp.begin(); it != mp.end(); ++it)
     {
       Node* node = it->second;
       if(node != NULL && node->visited == false)
       {
          cout<<node->name<<", ";
       }
    }
     return 0;
}
