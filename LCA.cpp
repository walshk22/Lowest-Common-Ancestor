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
    vector<int> NodeTree = {1,2,3,4,5,6,7,8,9,10,11, 12};
    
    return NodeTree;
}

int findLCA(vector<int> Tree, Node a, Node b)
{
    int LCA;
    bool AonTree = false;
    bool BonTree = false;
    
    
    //EDITTED-- Checking for validity of nodes being checked
    for(int i = 0; i<Tree.size(); i++)
    {
        if(a.getNum() == Tree[i])
        {
            AonTree = true;
        }
        
        if(b.getNum() == Tree[i])
        {
            BonTree = true;
        }
    }
    
    if(BonTree== false || AonTree == false)
    {
        cout << "ERROR: THE NODE REQUESTED IS NOT ON THE TREE" << endl;
        return 0;
    }
    
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

//Check LCA to see if it equals 0; if so the LCA has an error and nothing should be outprinted
bool checkLCA(int LCA)
{
    if(LCA == 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void printLCA(int LCA, bool check)
{
    if(check)
    {
        cout <<  "The LCA between the two nodes is " << LCA << endl;
    }
    
    else
    {
        cout << "LCA is N/A" << endl;
    }
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
    bool checkingLCA = checkLCA(LCA);
    cout << "NODE A = " << a.getNum() << endl;
    cout << "NODE B = " << b.getNum() << endl;
    printLCA(LCA, checkingLCA);
    
    Node c = Node(10);
    Node d = Node(11);
    
    int LCA1 = findLCA(Tree, c, d);
    bool checkingLCA1 = checkLCA(LCA1);
    cout << "NODE C = " << c.getNum() << endl;
    cout << "NODE D = " << d.getNum() << endl;
    printLCA(LCA1, checkingLCA1);
    
    Node e = Node(14);
    Node f= Node(4);
    
    //EDIT ME: LCA is correct but there should be an error because 14 is not on the NODE Tree
    int LCA2 = findLCA(Tree, e, f);
    bool checkingLCA2 = checkLCA(LCA2);
    cout << "NODE E = " << e.getNum() << endl;
    cout << "NODE F = " << f.getNum() << endl;
    printLCA(LCA2, checkingLCA2);
    
    return 0;
}
