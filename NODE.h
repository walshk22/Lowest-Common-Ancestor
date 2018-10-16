//
//  NODE.hpp
//  DAG LCA Tree
//
//  Created by Kaitlyn Walsh on 10/3/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#ifndef NODE_hpp
#define NODE_hpp

#include <iostream>
#include <vector>

class NODE {
private:
    int edgeLeft;
    int edgeRight;
    int num;
    int row;               //0 for tips, 1 for left, 2 for right, 3 for branch of left
public:
    NODE(int, int, int);
    void setEdgeLeft(int);
    void setEdgeRight(int);
    int getNum();
    int getEdgeRight();
    int getEdgeLeft();
    void setRow(int);
    int getRow();
};

#endif /* NODE_hpp */
