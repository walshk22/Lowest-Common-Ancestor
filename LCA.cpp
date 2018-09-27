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
//void printLCA(int LCA, bool check);
void printLCA(vector<Node> x, vector<bool> check, vector<int> LCA);

int main()
{

    vector<Node> nodes;
    vector<int> LCAs;
    vector<int> Tree = createTree();
   
    //IDEA: Create a vector of bools and then create a function so if the nodes are equal
    // or the node isn't on the tree then it doesn't outprint a LCA
    vector<bool> posError;                          //vector of bools for checkLCA values

    
    Node a = Node(5);
    nodes.push_back(a);
    Node b(8);
    nodes.push_back(b);
   
    
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
    LCAs.push_back(LCA);
    bool checkingLCA = checkLCA(LCA);
    posError.push_back(checkingLCA);
    
    //cout << "NODE A = " << a.getNum() << endl;
    //cout << "NODE B = " << b.getNum() << endl;
    //printLCA(LCA, checkingLCA);
    cout << endl;
    
    Node c = Node(10);
    nodes.push_back(c);
    Node d = Node(11);
    nodes.push_back(d);
    
    int LCA1 = findLCA(Tree, c, d);
    LCAs.push_back(LCA1);
    bool checkingLCA1 = checkLCA(LCA1);
    posError.push_back(checkingLCA1);
    
    //cout << "NODE C = " << c.getNum() << endl;
    //cout << "NODE D = " << d.getNum() << endl;
    //printLCA(LCA1, checkingLCA1);
    cout << endl;

    Node e = Node(14);
    nodes.push_back(e);
    Node f= Node(4);
    nodes.push_back(f);
    
    //EDIT ME: LCA is correct but there should be an error because 14 is not on the NODE Tree
    int LCA2 = findLCA(Tree, e, f);
    LCAs.push_back(LCA2);
    bool checkingLCA2 = checkLCA(LCA2);
    posError.push_back(checkingLCA2);
    
    //cout << "NODE E = " << e.getNum() << endl;
    //cout << "NODE F = " << f.getNum() << endl;
   
    /*
    if(!checkingLCA2)                               //NO output should appear because 14 isn't on tree
    {
        printLCA(LCA2, checkingLCA2);
    }
    cout << endl; */
    
    Node g = 4;
    nodes.push_back(g);
    Node h = 4;
    nodes.push_back(h);
    int LCA3 = findLCA(Tree, g, h);
    LCAs.push_back(LCA3);
    bool checkingLCA3 = checkLCA(LCA3);
    posError.push_back(checkingLCA3);
    //cout << "NODE G = " << g.getNum() << endl;
    //cout << "NODE F = " << f.getNum() << endl;
    //printLCA(LCA3, checkingLCA3);                   //ERROR: PRINTING 4 not 3
    
    int nodCount = 0;
    for(int i=0; i<LCAs.size(); i++)
    {
        cout << "NODE 1: " << nodes[nodCount].getNum() << endl;
        nodCount++;
        
        cout << "NODE 2: " << nodes[nodCount].getNum() << endl;
        nodCount++;
        
        if(posError[i])
        {
            cout << "LCA: " << LCAs[i] << endl;
         }
        
        else
        {
            cout << "ERROR: NO LCA" << endl;
        }
        
        cout << endl;
    }
    
    return 0;
}

vector <int> createTree()
{
    vector<int> NodeTree = {1,2,3,4,5,6,7,8,9,10,11,12};
    
    return NodeTree;
}

int findLCA(vector<int> Tree, Node a, Node b)
{
    int LCA;
    bool AonTree = false;
    bool BonTree = false;
    int aPosition=0, bPosition=0;

    
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
        
        LCA = 0;
    }
    
    if(!BonTree)
    {
        LCA = 0;
    }
    
    
    else
    {
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
            LCA= Tree[bPosition-1];
        }
        
        //DEBUGGING
        //cout << "CODE REACHED HERE" << endl;
          if(aPosition == bPosition)
        {
            LCA = 0;
        }
        
        else
        {
            LCA = Tree[aPosition - 1];
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
//  PRINT FUNCTION 1
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

// TEST PRINT FUNC 2---- FAIL
/*
void printLCA(vector<Node> x, vector<bool> check, vector<int> LCA)
{
    for(int nod = 0; nod<x.size(); nod++)
    {
        if(nod == 0)
        {
        
            cout << "NODE 1: " << x[nod].getNum() << endl;
            cout << "NODE 2: " << x[nod+1].getNum() << endl;
        
            if(check[nod])
            {
                cout << "LCA = " << LCA[nod] << endl;
            }
        }
        
        else {
            cout << "NODE 1: " << x[nod].getNum() << endl;
            cout << "NODE 2: " << x[nod+1].getNum() << endl;
            
            if(check[nod-1])
            {
                cout << "LCA = " << LCA[nod-1];
            }
        }
        
    }
} */








