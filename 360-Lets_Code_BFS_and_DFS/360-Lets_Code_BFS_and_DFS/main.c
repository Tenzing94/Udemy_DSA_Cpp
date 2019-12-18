//
//  main.c
//  360-Lets_Code_BFS_and_DFS
//
//  Created by Tenzing Rabgyal on 12/8/19.
//  Copyright © 2019 Tenzing Rabgyal. All rights reserved.
//

#include <stdio.h>
#include "queue.h"

void BFS(int G[][7], int start, int n)
{
    int visited[7] = {0};
    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);
    
    while(!isEmpty()) {
        start = dequeue();
        for(int j = 1; j < n; j++) {
            // if there is an edge, and it is not yet visited
            if(G[start][j] == 1 && visited[j] == 0) {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(j);
            }
        }
    }
}

void DFS(int G[][7], int start, int n)
{
    static int visited[7] = {0};
    if(visited[start] == 0) {
        printf("%d ", start);
        visited[start] = 1;
        
        for(int j = 1; j < n; j++) {
            // if there is an edge, and it is not yet visited
            if(G[start][j] == 1 && visited[j] == 0)
                DFS(G,j,n);
        }
    }
}

int main()
{
    // the first column and first row are not used because it is index 0
    int G[7][7]={{0,0,0,0,0,0,0},
                {0,0,1,1,0,0,0},
                {0,1,0,0,1,0,0},
                {0,1,0,0,1,0,0},
                {0,0,1,1,0,1,1},
                {0,0,0,0,1,0,0},
                {0,0,0,0,1,0,0}};
    
    printf("BFS: ");
    BFS(G,5,7);
    printf("\nDFS: ");
    DFS(G,5,7);
    
    return 0;
}
