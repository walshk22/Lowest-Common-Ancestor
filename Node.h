//
//  Node.h
//  Lowest Common Ancestor
//
//  Created by Kaitlyn Walsh on 9/21/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
private:
    int left;
    int right;
    int num;
public:
    Node(int);
    int getNum();
    int getLeft();
    int getRight();
    void fillLeftRight(vector <int>);
};
