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
public:
    NODE(int);
    void setEdgeLeft(int);
    void setEdgeRight(int);
    int getNum();
    int getEdgeRight();
    int getEdgeLeft();
    //vector<NODE> nodeList();
};

#endif /* NODE_hpp */
