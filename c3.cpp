#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int p,q,r,N,M;
int count = 0;
struct NodeStruct{
    int node_num = -1;
    int rootToNode[3] = {-1, -1, -1}; //0: N -> node    1: 1 -> node        2: 2 -> node  
    int isUsed[3] = {0,0,0}; // 0: N    1: 1    2: 2  
};
vector< vector <NodeStruct>> nodeStruct(40001);

void BFS_node(int start);

int main(){
    int node1,node2;
    cin >> p >> q >> r >>N >>M;
    NodeStruct a;
    a.isUsed[0] = 0; a.isUsed[1] = 0; a.isUsed[2] = 0;
    for(int i = 0; i<N + 1; i++){
            nodeStruct[i].push_back(a);
    }

    for(int i = 0; i<M; i++){   
        cin >> node1 >> node2;
        a.node_num = node2;
        nodeStruct[node1].push_back(a);

        a.node_num = node1;
        nodeStruct[node2].push_back(a);
    }
    BFS_node(1);    BFS_node(2);    BFS_node(N);
    int min = (nodeStruct[1][0].rootToNode[0] * p) + (nodeStruct[2][0].rootToNode[0] * q);

    for(int i = 1; i<N; i++){
        count++;
          if(nodeStruct[i][0].rootToNode[0] == -1 || nodeStruct[i][0].rootToNode[1] == -1 || nodeStruct[i][0].rootToNode[2] == -1)
        continue;
        else{
               int temp = (nodeStruct[i][0].rootToNode[1] * p) + (nodeStruct[i][0].rootToNode[2] * q) + (nodeStruct[i][0].rootToNode[0] * r);
                if(min> temp || min == 0)
                min = temp;
        }
    }
    cout<< min << endl;
    cout << count;
}


void BFS_node(int start){
    queue <int> que;
    int rootID;
    if(start == 1 || start == 2)
        rootID = start;
    else
        rootID = 0;
                
    que.push(start);
    nodeStruct[start][0].isUsed[rootID] = 1;
    int rootToNode = 0;
    nodeStruct[start][0].rootToNode[rootID] = rootToNode;

    while(que.empty() != true){
        int popped_num = que.front();
        que.pop();
        rootToNode =  nodeStruct[popped_num][0].rootToNode[rootID] + 1;
        for(int i = 1; i<nodeStruct[popped_num].size(); i++){
            count++;
            int nodeToVisit = nodeStruct[popped_num][i].node_num;

            if(nodeToVisit == N ){
                if(nodeStruct[nodeToVisit][0].isUsed[rootID] == 0){
                nodeStruct[nodeToVisit][0].rootToNode[rootID] = rootToNode;
                nodeStruct[nodeToVisit][0].isUsed[rootID] = 1;
                }
            }

            else if(nodeStruct[nodeToVisit][0].isUsed[rootID] == 0){
                que.push(nodeToVisit);
                nodeStruct[nodeToVisit][0].rootToNode[rootID] = rootToNode;
                nodeStruct[nodeToVisit][0].isUsed[rootID] = 1;
            }
        }
    }

}
