//
//  Double_Branch_LCA.cpp
//  Lowest Common Ancestor
//
//  Created by Kaitlyn Walsh on 9/29/18.
//  Copyright © 2018 Kaitlyn Walsh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;


class NODE {
private:
    int num;
    int upperNode;
    int depth;
public:
    NODE(int a) { num = a; };
    int getNum() { return num;};
    void setUpperNode(int a) { upperNode = a;};
    int getUpperNode() { return upperNode; };
    void setDepth(int a) { depth = a;};
    int getDepth() { return depth; };
    
};

vector <NODE> nodeTree;
vector<int> treeDepth = {0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 2, 1, 0};

int findLCA ( NODE a, NODE b);

int main ()
{
    NODE a(1);
    nodeTree.push_back(a);
    a.setDepth(0);
    
    
    NODE b(2);
    nodeTree.push_back(b);
    b.setUpperNode(a.getNum());
    b.setDepth(1);
    
    //Left hand nodes-- depth 2
    NODE d(4);
    nodeTree.push_back(d);
    d.setUpperNode(b.getNum());
    d.setDepth(2);
    
    
    NODE e(5);
    nodeTree.push_back(d);
    e.setUpperNode(b.getNum());
    e.setDepth(2);
    
    NODE c(3);
    nodeTree.push_back(c);
    c.setUpperNode(a.getNum());
    c.setDepth(1);
    
    NODE f(6);
    nodeTree.push_back(f);
    f.setUpperNode(c.getNum());
    f.setDepth(2);
    
    NODE g(7);
    nodeTree.push_back(g);
    g.setUpperNode(c.getNum());
    g.setDepth(2);
    
    
    
    
    
    
    
    int LCA = findLCA( d, e);                    //LCA = 2
    cout << "THE LCA(4,5) IS: " << LCA << endl;
    
    int LCA1 = findLCA(b, c);                        //LCA = 1
    cout << "THE LCA(2,3) IS: " << LCA1 << endl;
    
    int LCA2 = findLCA(g, f);                        //LCA =3
    cout << "THE LCA(7,6) IS: " << LCA2 << endl;
    
    int LCA3 = findLCA(b, f);                        // LCA =1
    cout << "THE LCA(2,6) IS: " << LCA3 << endl;
    
    int LCA4 = findLCA(d, g);                       //LCA = 1
    cout << "THE LCA(4,7) IS: " << LCA4 << endl;
    
    int LCA5 = findLCA(e, f);                       //LCA = 1
    cout << "THE LCA(5,6) IS: " << LCA5 << endl;
    
    
    return 0;
}


int findLCA( NODE a, NODE b)
{
    int LCA;
    
    int depth1 = a.getDepth();
    int depth2 = b.getDepth();
    
    int prevNum1 = a.getUpperNode();
    int prevNum2 = b.getUpperNode();
    
    if(depth1 == depth2)
    {
        if(prevNum1 == prevNum2)
        {
            LCA = prevNum1;
        }
        
        else
        {
            LCA = 1;
        }
    }
    
    else
    {
        LCA = 1;
    }
    
    
    return LCA;
}

