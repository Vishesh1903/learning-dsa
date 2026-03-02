#include <iostream>

using namespace std;

void printLineSeparator(string text, bool start){
    if(start){
        cout << endl << "================= " + text + " =================" << endl; 
    }else{
        cout << endl << "================= " + text + " END" << " =================" << endl;
    }
}

void printDFS(vector<vector<bool>> v, vector<bool>& visited, int sv, int n){
    cout << sv << " ";
    visited[sv] = true;
    for(int i = 0; i < n;i++){
        if(v[sv][i] && !visited[i]){
            printDFS(v, visited, i, n);
        }else{
            continue;
        }
    }
}

void printBFS(const vector<vector<bool>>& v, vector<bool>& visited, int sv, int n){
    queue<int> q;
    q.push(sv);
    visited[sv] = true;
    while(!q.empty()){
        int front = q.front();
        q.pop();
        cout << front << " ";
        for(int i = 0; i < n; i++){
            if(!visited[i] && v[front][i]){
                visited[i] = true;
                q.push(i);
            }
        }
    }
}

void dfs(const vector<vector<bool>>& v){
    int n = v.size();
    vector<bool> visited(n, false);
    printLineSeparator("DFS", true);
    for(int i = 0; i < n; i++){
        if(visited[i]){
            continue;
        }else{
           printDFS(v, visited, i, n);
        }
    }
    printLineSeparator("DFS", false);
}

void bfs(const vector<vector<bool>>& v){
    int n = v.size();
    vector<bool> visited(n, false);
    printLineSeparator("BFS", true);
    for(int i = 0; i < n; i++){
        if(visited[i]){
            continue;
        }else{
            printBFS(v, visited, i, n);
        }
    }
    printLineSeparator("BFS", false);
}
// 7 8 0 1 0 2 1 3 1 4 2 6 3 5 4 5 6 5 - For connected graph input
// 8 6 0 2 0 4 2 4 2 3 1 5 6 7 - For disconnected graph input
int main(){
    int vertices, edges;
    cout << "Enter the number of vertices you want in the graph" << endl;
    cin >> vertices;
    cout << "Enter the number of edges you in the graph of " << vertices << " vertices" << endl;
    cin >> edges;

    vector<vector<bool>> adj_matrix(vertices, vector<bool>(vertices, false));
    int count = 1;
    while(count <= edges){
        int first_vertice, second_vertice;
        cout << "Enter the first vertice of the edge " << count << endl;
        cin >> first_vertice;
        cout << "Enter the second vertice of the edge " << count << endl;
        cin >> second_vertice;

        if(first_vertice < 0 || second_vertice < 0 || first_vertice >= vertices || second_vertice >= vertices){
            cout << "Invalid vertice entered" << endl;
            continue;
        }
        adj_matrix[first_vertice][second_vertice] = true;
        adj_matrix[second_vertice][first_vertice] = true;
        count++;
    }
    dfs(adj_matrix);
    bfs(adj_matrix);
    return 0;
}