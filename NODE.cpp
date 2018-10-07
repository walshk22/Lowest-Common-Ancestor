//
//  NODE.cpp
//  DAG LCA Tree
//
//  Created by Kaitlyn Walsh on 10/3/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#include "NODE.h"
using namespace std;

NODE :: NODE(int n)
{
    num = n;
}

void NODE:: setEdgeLeft(int left)
{
    edgeLeft = left;
}

void NODE:: setEdgeRight(int right)
{
    edgeRight = right;
}

int NODE:: getNum()
{
    return num;
}

int NODE :: getEdgeLeft()
{
    return edgeLeft;
}

int NODE :: getEdgeRight()
{
    return edgeRight;
}

void NODE:: setSide(int x)
{
    side = x;
}

int NODE:: getSide()
{
    return side;
}







