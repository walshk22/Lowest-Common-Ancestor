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

vector <int> nodeTree = { 1, 2, 4, 2, 5, 2, 1, 3, 6, 3, 7, 3, 1};
vector<int> treeDepth = {0, 1, 2, 1, 2, 1, 0, 1, 2, 1, 2, 1, 0};

int findLCA ( int a, int b);

int main ()
{
    
    int LCA = findLCA( 4,5);                    //LCA = 2
    cout << "THE LCA(4,5) IS: " << LCA << endl;
    
    int LCA1 = findLCA(2,3);                        //LCA = 1
    cout << "THE LCA(2,3) IS: " << LCA1 << endl;
    
    int LCA2 = findLCA(7, 6);                        //LCA =3
    cout << "THE LCA(7,6) IS: " << LCA2 << endl;
    
    int LCA3 = findLCA(2,6);                        // LCA =1
    cout << "THE LCA(2,6) IS: " << LCA3 << endl;
    
    int LCA4 = findLCA(4, 7);                       //LCA = 1
    cout << "THE LCA(4,7) IS: " << LCA4 << endl;
    
    
    return 0;
}


int findLCA( int a, int b)
{
    int aDepth, bDepth, LCA=0;
    
    //Finding depth of the
    for(int i =0; i<13; i++)
    {
        if(nodeTree[i] == a)
        {
            aDepth = treeDepth[i];
        }
        
        if(nodeTree[i] == b)
        {
            bDepth = treeDepth[i];
        }
    }
    
    if(aDepth == 1 && bDepth ==1)
    {
        LCA = 1;
    }
    
    else if((aDepth == 1 && bDepth == 2) || (bDepth ==1 && aDepth == 2) )
    {
        LCA = 1;
    }
    
    else{
        int aPos, bPos;                               // place holders for nodes a and b
        
        for(int i =0; i< 13; i++)
        {
            if(nodeTree[i] == a)
            {
                aPos = i;
            }
            
            if(nodeTree[i]== b)
            {
                bPos = i;
            }
        }
            
            int LCAPosition=0;
            if( aPos >bPos)
            {
                LCAPosition = (aPos-1);
                LCA = nodeTree[LCAPosition];
            }
            else if(bPos>aPos)
            {
                LCAPosition = (bPos-1);
                LCA = nodeTree[LCAPosition];
            }
            
            else{
                LCA = 0;
            }
            
        
    }
    
    return LCA;
}

