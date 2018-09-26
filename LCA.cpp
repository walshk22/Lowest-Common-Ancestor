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


vector <int> createTree();
int findLCA(vector<int> Tree, Node a, Node b);
//Check LCA to see if it equals 0; if so the LCA has an error and nothing should be outprinted
bool checkLCA(int LCA);
void printLCA(int LCA, bool check);

int main()
{

    Node a = Node(5);
    Node b(8);
    vector<int> Tree = createTree();
    
    vector<bool> posError;
    
    cout << "NODE TREE: ";
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
    posError.push_back(checkingLCA);
    
    cout << "NODE A = " << a.getNum() << endl;
    cout << "NODE B = " << b.getNum() << endl;
    printLCA(LCA, checkingLCA);
    cout << endl;
    
    Node c = Node(10);
    Node d = Node(11);
    
    int LCA1 = findLCA(Tree, c, d);
    bool checkingLCA1 = checkLCA(LCA1);
    posError.push_back(checkingLCA1);
    
    cout << "NODE C = " << c.getNum() << endl;
    cout << "NODE D = " << d.getNum() << endl;
    printLCA(LCA1, checkingLCA1);
    cout << endl;

    Node e = Node(14);
    Node f= Node(4);
    
    //EDIT ME: LCA is correct but there should be an error because 14 is not on the NODE Tree
    int LCA2 = findLCA(Tree, e, f);
    bool checkingLCA2 = checkLCA(LCA2);
    posError.push_back(checkingLCA2);
    cout << "NODE E = " << e.getNum() << endl;
    cout << "NODE F = " << f.getNum() << endl;
    printLCA(LCA2, checkingLCA2 );
    cout << endl;
    
    //TEST: WHAT HAPPENS WHEN THE NODE IS THE SAME NODE
    Node g = 4;
    Node h = 4;
    int LCA3 = findLCA(Tree, g, h);
    bool checkingLCA3 = checkLCA(LCA3);
    posError.push_back(checkingLCA3);
    cout << "NODE G = " << g.getNum() << endl;
    cout << "NODE F = " << f.getNum() << endl;
    printLCA(LCA3, checkingLCA3);
    
    
    
    return 0;
}

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
    
    if( AonTree == false)
    {
        
        cout << "ERROR: THE NODE REQUESTED IS NOT ON THE TREE :: NODE "<< a.getNum() << endl;
        return 0;
    }
    
    if(!BonTree)
    {
        cout << "ERROR: THE NODE REQUEST IS NOT ON THE TREE :: NODE " << b.getNum() << endl;
    }
    
    if(a.getNum()==b.getNum())
    {
        LCA= a.getNum();
    }
    
    else
    {
        int aPosition, bPosition;
        for(int i =0; i<Tree.size(); i++)
        {
            
            if(Tree[i] == a.getNum())
            {
                aPosition = i;
            }
            
            if(Tree[i] == b.getNum())
            {
                bPosition =i;
            }
        }
        
        if (aPosition < bPosition)
        {
            LCA= Tree[aPosition-1];
        }
        
        //DEBUGGING
        cout << "CODE REACHED HERE" << endl;
         if(aPosition == bPosition)
        {
            cout << "The nodes are the same." << endl;
            LCA = Tree[aPosition-1];
        }
        
        else
        {
            LCA = Tree[bPosition - 1];
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
        cout <<  endl;
    }
}

