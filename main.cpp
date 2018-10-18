//
//  main.cpp
//  DAG LCA Tree
//
//  Created by Kaitlyn Walsh on 10/3/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#include <iostream>
#include "NODE.h"
#include <vector>
using namespace std;

void createDAGTree(vector<NODE> treeList);
int findLCA(vector<NODE> treeList, NODE x, NODE y);


int main() {
    vector<NODE> nodeList;
    NODE a(1, 3, 2);
    NODE b(2, 1, 4);
    NODE c(3, 1, 5);
    NODE c2(3,1,6);
    NODE d(4, 2, 7);
    NODE e(5,3,8);
    NODE z(8, 5, 0);
    NODE f(6,3,7);
    NODE g(7,6,4);
    
    
    
    nodeList.push_back(a);
    nodeList.push_back(b);
    nodeList.push_back(c);
    nodeList.push_back(d);
    nodeList.push_back(e);
    nodeList.push_back(f);
    nodeList.push_back(g);
    nodeList.push_back(z);
    
    
    createDAGTree(nodeList);
    cout << endl << endl;
    
    /*
    //TESTING EDGES    ----- FAILED ALL EDGES 0---
    cout << "NODE 1: " <<a.getEdgeLeft() << endl;
    cout << "NODE 2: " << b.getEdgeRight() << endl;
    cout <<  " NODE 7: " << g.getEdgeLeft() << endl; */
    
    //XGREATER
    int LCA1 = findLCA(nodeList, g, c);              //LCA = 1
    int LCA2 = findLCA(nodeList, g, d);              //LCA = 2
    int LCA3 = findLCA(nodeList,f,c2);              //LCA = 1
    int LCA4 = findLCA(nodeList, f,e);             //LCA = 3
    int LCA5 = findLCA(nodeList, f,d);              //LCA =1
    
    cout << "LCA(7,3) : " << LCA1 << endl;          //Resulting in 10...
    cout << "LCA(7, 4) : " << LCA2 << endl;
    cout << "LCA(6, 3) : " << LCA3 << endl;
    cout << "LCA(6, 5) : " << LCA4 << endl;
    cout << "LCA(6, 4) :" << LCA5 << endl;
    
    
    
    //TESTING !XGREATER
    int lca1 = findLCA(nodeList, b, c);             // lca = 1
    int lca2 = findLCA(nodeList, c2, f);            // lca = 1
    int lca3 = findLCA(nodeList, b, g);             // lca = 1
    int lca4 = findLCA(nodeList, b, f);             // lca =1
    int lca5 = findLCA(nodeList, f, g);             //lca = 3
    int lca6 = findLCA(nodeList, d,f);              //lca =1
    
    cout << endl << "LCAS FOR YGREATER" << endl;
    cout << "LCA (2,3) :" << lca1 << endl;
    cout << "LCA (3,6) :" << lca2 << endl;
    cout << "LCA (2,7) :" << lca3 << endl;
    cout << "LCA (2,6) :" << lca4 << endl;
    cout << "LCA (6,7) :" << lca5 << endl;
    cout << "LCA (4,6) :" << lca6 << endl;
    
    int lca7 = findLCA(nodeList, z, c);
    int lca8 = findLCA(nodeList, d, z);
    int lca9 = findLCA(nodeList, g, z);
    int lca10 = findLCA(nodeList, z, e);
    cout << "LCA (8,3) :" << lca7 << endl;              //lca = 1
    cout << "LCA (4,8) :" << lca8 << endl;              //lca = 1
    cout << "LCA (7,8) :" << lca9 << endl;              // lca =3
    cout << "LCA (8,5) :" << lca10 << endl;             //lca = 3
    
    
    return 0;
}

void createDAGTree(vector<NODE> treeList)
{
    float size = treeList.size();
    //NODE 7
    treeList[size-1].setRow(0);
    
    //NODE 6
    treeList[size-2].setRow(1);
    
    //NODE 5
    treeList[size-3].setRow(3);
    
    //NODE 4
    treeList[size-4].setRow(2);
    
    //NODE 3
    treeList[size-5].setRow(1);
    
    treeList[size-4].setRow(3);
    
    //NODE 2
    treeList[1].setRow(1);
    
    //NODE 1
    treeList[0].setRow(0);
    
    
    //DRAWING TREE
    cout << "\t <--- 2 \t <--- 4 \t <---" << endl;
    cout << "1 \t\t\t\t\t\t\t\t   7" << endl;
    cout << "\t <--- 3 \t <--- 6 \t <---" << endl;
    cout << "\t\t  ^--- 5 <---8" << endl;
    
}

int findLCA(vector<NODE> treeList, NODE x, NODE y)
{
    int LCA;
    bool xGreater = false;                      //Assume y is the greater number
    
    //Checking to see which number is greater--- larger numbers are at bottom of DAG tree
    if(x.getNum() > y.getNum())
    {
        //cout << "MADE IT HERE 1" << endl;         //Testing Only
        xGreater = true;
    }
    
    //CASE 1
    if(x.getNum() == y.getNum())
    {
        LCA = 0;
    }
    //CASE 2--
    //Series of if else statements to cover all possibilities
        //CASE 2.1
    if(xGreater && (y.getRow()==x.getRow()))
    {
//        cout << "ROWS EQUAL" << endl;
        LCA = y.getEdgeLeft();
    }
    //CASE 2.2
    else if(xGreater && (y.getRow() != x.getRow()) )
    {
        //CASE 2.2.1
        if(y.getRow() > x.getRow())
        {
            if(y.getRow() == 3 && x.getRow() == 2)
            {
                LCA = treeList[0].getNum();
            }
                
            else if(y.getRow() == 3 && x.getRow() == 1)
            {
                if(y.getEdgeRight() == x.getNum())
                {
                    LCA =1;
                }
                else
                {
                        LCA = 3;
                }
            }
            
            else
            {
                LCA = 1;
            }
        }
    }

    //CASE 2.3
    else if(y.getRow() < x.getRow())
    {
        if(y.getRow() == 2 && x.getRow() == 3)
        {
            LCA = 1;                                //converge at top of tree
        }
        else if(y.getRow() == 1 && x.getRow() == 3)
        {
            if(x.getNum() == y.getEdgeRight())
            {
                LCA = 1;
            }
            else
            {
                LCA = 3;
            }
        }
        else if(y.getRow() == 1 && x.getRow()==2)
        {
            LCA = 1;
        }
        
        else
        {
            LCA = 0;                //ERROR IF NO LCA FOUND
        }
    }
    
    else {
        LCA = 1;
    }
    
    /*else {
        LCA = y.getEdgeLeft();
    } */
 
    if(!xGreater)  {                         //xGreater is false, x is on the before y on tree
        if(y.getRow() != x.getRow())
        {
            if(y.getRow() == 3 && x.getRow() == 2)
            {
                LCA =1;
            }
            else if(y.getRow() == 3 && x.getRow() == 1)
            {
                LCA = x.getEdgeLeft();
            }
            else if(x.getRow() ==0  || y.getRow() == 0)
            {
                cout << "ROWS:" << y.getRow() << " " << x.getRow() << endl;         //testing
                LCA = 0;
            }
            else{
                LCA = 1;
            }
        }
        
        else
        {
            LCA = x.getEdgeLeft();
        }
    }
    
        
    return LCA;
}
