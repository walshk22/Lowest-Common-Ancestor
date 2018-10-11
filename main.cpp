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
    NODE a(1);
    NODE b(2);
    NODE c(3);
    NODE d(4);
    NODE e(5);
    NODE f(6);
    NODE g(7);
    
    nodeList.push_back(a);
    nodeList.push_back(b);
    nodeList.push_back(c);
    nodeList.push_back(d);
    nodeList.push_back(e);
    nodeList.push_back(f);
    nodeList.push_back(g);
    
    createDAGTree(nodeList);
    cout << endl << endl;
    
    
    int LCA1 = findLCA(nodeList, 7,3);              //LCA = 1
    int LCA2 = findLCA(nodeList, 7, 4);              //LCA = 2
    int LCA3 = findLCA(nodeList,6, 3);              //LCA = 1
    int LCA4 = findLCA(nodeList, 6, 5);             //LCA = 3
    
    cout << "LCA(7,3) : " << LCA1 << endl;          //Resulting in 10...
    cout << "LCA(7, 4) : " << LCA2 << endl;
    cout << "LCA(6, 3) : " << LCA3 << endl;
    cout << "LCA(6, 5) : " << LCA4 << endl;
    
    return 0;
}

void createDAGTree(vector<NODE> treeList)
{
    float size = treeList.size();
    //NODE 7
    treeList[size-1].setEdgeRight(4);
    treeList[size-1].setEdgeLeft(6);
    treeList[size-1].setRow(0);
    
    //NODE 6
    treeList[size-2].setEdgeLeft(3);
    treeList[size-2].setEdgeRight(7);
    treeList[size-2].setRow(1);
    
    //NODE 5
    treeList[size-3].setEdgeRight(3);
    treeList[size-3].setEdgeLeft(0);
    treeList[size-3].setRow(3);
    
    //NODE 4
    treeList[size-4].setEdgeLeft(7);
    treeList[size-4].setEdgeRight(2);
    treeList[size-4].setRow(2);
    
    //NODE 3
    treeList[size-5].setEdgeRight(1);
    treeList[size-5].setEdgeLeft(5);
    treeList[size-5].setRow(1);
    
    //NODE 2
    treeList[1].setEdgeRight(1);
    treeList[1].setEdgeLeft(4);
    treeList[1].setRow(1);
    
    //NODE 1
    treeList[0].setEdgeRight(0);
    treeList[0].setEdgeLeft(0);
    treeList[0].setRow(0);
    
    
    //DRAWING TREE
    cout << "\t <--- 2 \t <--- 4 \t <---" << endl;
    cout << "1 \t\t\t\t\t\t\t\t   7" << endl;
    cout << "\t <--- 3 \t <--- 6 \t <---" << endl;
    cout << "\t\t  ^--- 5" << endl;
    
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
    
    bool xGreaterRow = false;

    if(x.getRow() > y.getRow())
    {
        xGreaterRow = true;
    }
    
    //CASE 1
    if(x.getNum() == y.getNum())
    {
        LCA = 0;
    }
    //CASE 2--
    cout << "X is not equal to Y" << endl;
    //Series of if else statements to cover all possibilities
        //CASE 2.1
       if(xGreater && (y.getRow()==x.getRow()))
        {
            cout << "ROWS EQUAL" << endl;
            LCA = y.getEdgeLeft();
        }
        //CASE 2.2
        else if(xGreater && (y.getRow() != x.getRow()) )
         {
            cout << "MADE IT HERE" << endl;                         // for testing only
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
    /*
    else  {                              //xGreater is false, x is on the before y on tree
            cout << "IN ELSE STATMENT-- yGreater" << endl;
            if(y.getRow() != x.getRow())
            {
                if(y.getRow() == 3 && x.getRow() == 2)
                {
                    cout << "ROWS:" << y.getRow() << " " << x.getRow() << endl;         //testing
                    LCA =1;
                }
                
                else if(y.getRow() == 3 && x.getRow() == 1)
                {
                    LCA = x.getEdgeRight();
                }
                
                else if(x.getRow() ==0  || y.getRow() == 0)
                {
                    cout << "ROWS:" << y.getRow() << " " << x.getRow() << endl;         //testing

                    LCA = 0;
                }
            }
        
            else
            {
                LCA = y.getEdgeRight();
            }
        
        }
    } */
//}
    
    return LCA;
}
