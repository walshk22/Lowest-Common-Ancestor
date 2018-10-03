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
    
    
    int LCA1 = findLCA(nodeList, 7,3);
    int LCA2 = findLCA(nodeList, 4,7);
    int LCA3 = findLCA(nodeList, 3,6);
    
    cout << "LCA(7,3) : " << LCA1 << endl;
    cout << "LCA(4,7) : " << LCA2 << endl;
    cout << "LCA(3,6) : " << LCA3 << endl;
    
    
    return 0;
}

void createDAGTree(vector<NODE> treeList)
{
    float size = treeList.size();
    //NODE 7
    treeList[size-1].setEdgeRight(4);
    treeList[size-1].setEdgeLeft(6);
    
    //NODE 6
    treeList[size-2].setEdgeLeft(3);
    treeList[size-2].setEdgeRight(7);
    
    //NODE 5
    treeList[size-3].setEdgeRight(3);
    treeList[size-3].setEdgeLeft(0);
    
    //NODE 4
    treeList[size-4].setEdgeLeft(7);
    treeList[size-4].setEdgeRight(2);
    
    //NODE 3
    treeList[size-5].setEdgeRight(1);
    treeList[size-5].setEdgeLeft(5);
    
    //NODE 2
    treeList[1].setEdgeRight(1);
    treeList[1].setEdgeLeft(4);
    
    //NODE 1
    treeList[0].setEdgeRight(0);
    treeList[0].setEdgeLeft(0);
    
    
    //DRAWING TREE
    cout << "\t <--- 2 \t <--- 4 \t <---" << endl;
    cout << "1 \t\t\t\t\t\t\t\t   7" << endl;
    cout << "\t <--- 3 \t <--- 6 \t <---" << endl;
    cout << "\t\t  ^--- 5" << endl;
    
}

int findLCA(vector<NODE> treeList, NODE x, NODE y)
{
    int LCA = 0;
    
    for(int i =0; i<treeList.size(); i++)
    {
        if(x.getNum() == y.getEdgeLeft())
        {
            LCA = x.getEdgeRight();
        }
        
        else if(x.getNum() == y.getEdgeRight())
        {
            LCA = y.getEdgeLeft();
        }
        
        else if(x.getNum() == y.getNum())
        {
            LCA = 0;
        }
    }
    
    return LCA;
}
