void makeSet(int islands, vector<int> parent){ // initialize parent array with their own indexes to make disjoint sets
                                                // disjoint sets are sets which have no element in common between them
                                                // always pass by reference as copying will increase TC
    for(int i = 1; i <= islands; i++){
        parent[i] = i;
    }
}

int find(int island, vector<int> parent){ //TC:- O(Vertices);
    while(parent[island] != island){
        island = parent[island];
    }
    return island;
}

int Solution::solve(int islands, vector<vector<int>> &bridges) {
    sort(bridges.begin(), bridges.end(), [](auto &x, auto &y) { // Sort the edges on the basis of weights
        return x[2] < y[2];                                     // TC:- O(E log E + log a(v)) = O(E log E) // SC O(E)
    });
    int cost = 0;
    vector<int> parent(islands + 1, 0); // SC:-O(V)
    makeSet(islands, parent);
    for(int i = 0; i < bridges.size(); i++){ // TC 
        int representative_of_start =  find(bridges[i][0], parent); //
        int representative_of_destination =  find(bridges[i][1], parent);
        
        if(representative_of_start != representative_of_destination){
            cost += bridges[i][2];
            parent[representative_of_destination] = representative_of_start;
        }
        
    }
    return cost;
}
