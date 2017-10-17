//  Copyright © 2017 Dougy Ouyang. All rights reserved.

#include <iostream>

using namespace std;

struct tree
{
    int left;
    int data;
    int right;
};
typedef struct tree treenode;
treenode btree[10000];
int lar=0;

void bfs(int loc, int step)
{
    if(!loc){
        lar=max(lar, step);
        return;
    }
    bfs(btree[loc].left, step+1);
    bfs(btree[loc].right, step+1);
}

int main()
{
    int p, cn, d1, d2;
    int i;
    
    cin >> p;
    for(i=0;i<p-1;i++){
        cin >> cn >> d1 >> d2;
        btree[cn].left=d1, btree[cn].right=d2;
    }
    
    bfs(1, 0);
    
    cout << lar << endl;
    
    return 0;
}
