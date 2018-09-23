//
//  main.cpp
//  Lowest Common Ancestor
//
//  Created by Kaitlyn Walsh on 9/19/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#include <iostream>
#include "Node.h"
#include <vector>
using namespace std;


vector <int> createTree()
{
    vector<int> NodeTree = {0,1,2,3,4,5,6,7,8,9,10,11};
    
    return NodeTree;
}

int findLCA(vector<int> Tree, Node a, Node b)
{
    int LCA;
    if(a.getNum()==b.getNum())
    {
        LCA= a.getNum();
    }
    
    else
    {
        int aPos, bPos;
        for(int i =0; i<Tree.size(); i++)
        {
            
            if(Tree[i] == a.getNum())
            {
                aPos = i;
            }
            
            if(Tree[i] == b.getNum())
            {
                bPos =i;
            }
        }
        
        if (aPos < bPos)
        {
            LCA= Tree[aPos-1];
        }
        
        else
        {
            LCA = Tree[bPos - 1];
        }
        
    }
    
    return LCA;
}

int main()
{

    Node a = Node(5);
    Node b(8);
    vector<int> Tree = createTree();
    
    //printing binary tree
    for(int i=0; i<Tree.size(); i++)
    {
        if(i+1 == Tree.size())
        {
            cout << Tree[i] << " " << endl;
        }
        
        else
        {
            cout << Tree[i] << "--> ";
        }
    
    }
    
    int LCA = findLCA(Tree, a, b);
    
    cout << "The LCA of " << a.getNum() << " and " << b.getNum() << " is " << LCA << endl;
    
    Node c = Node(10);
    Node d = Node(11);
    
    int LCA1 = findLCA(Tree, c, d);
    cout << "LCA of "<< c.getNum() << " and " << d.getNum() << " is " << LCA1 << endl;
    
    return 0;
}
