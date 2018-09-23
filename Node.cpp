//
//  Node.cpp
//  Lowest Common Ancestor
//
//  Created by Kaitlyn Walsh on 9/21/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#include <iostream>
#include "Node.h"
using namespace std;

Node :: Node(int x)
{
    num = x;
}

int Node :: getNum()
{
    return num;
}

int Node :: getLeft()
{
    return left;
}

int Node :: getRight()
{
    return right;
}

