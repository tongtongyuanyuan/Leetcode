//
// Created by Tong Xue on 7/30/19.
//

//Kruscal MST(Union Find). edges

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

struct Edge{
    char u;
    char v;
    int weight;
    Edge(char u, char v, int weight): u(u), v(v), weight(weight){}
};

struct Vertex{
    int index;
    int weight;
    Vertex* next;
    explicit Vertex(int index, int weight = 0) : index(index), weight(weight), next(nullptr){}
};

struct PrimNode{
    int index;
    int weight;
    PrimNode(int index = 0, int weight = INT_MAX): index(index), weight(weight){}
};

// Make Adjacent List
void VertexInsert(Vertex* vertex, int index, int weight){
    Vertex *p = vertex;
    while (p->next) {
        p = p->next;
    }
    p->next = new Vertex(index, weight);
}

void initAdjacentList(vector<Vertex*>& list, vector<Edge>& edges){
    for(auto& e : edges){
        VertexInsert(list[e.u - 'A'], e.v - 'A', e.weight);
        VertexInsert(list[e.v - 'A'], e.u - 'A', e.weight);
    }
}

//Make Adjacent matrix
void initAdjacentMatrix(vector<vector<int>>& matrix, vector<Edge>& edges){
    for(auto& e : edges){
        int row = e.u - 'A';
        int col = e.v - 'A';
        matrix[row][col] = e.weight;
    }
}


//Prim get MST, adjacent list
int minIndex(vector<PrimNode>& D){
    int index = 0;
    int cur_min = INT_MAX;
    for(int i = 0; i < D.size(); i++){
        if(D[i].weight < cur_min && D[i].weight != 0){
            cur_min = D[i].weight;
            index = i;
        }
    }
    return index;
}

void update(vector<PrimNode>& D, Vertex* vertex){
    D[vertex->index].weight = 0;
    Vertex *p = vertex->next;
    while(p){
        if(p->weight < D[p->index].weight){
            D[p->index].index = vertex->index;
            D[p->index].weight = p->weight;
        }
        p = p->next;
    }

}

void MST_Prim_List(vector<Vertex*>& list, int start){
    vector<PrimNode> D(list.size(), INT_MAX);
    update(D, list[start]);
    for(int i = 0; i < list.size() - 1; i++){
        int cur_min_index = minIndex(D);
        char u = D[cur_min_index].index + 'A';
        char v = cur_min_index + 'A';
        cout << u << "-----" << v << endl;
        start = cur_min_index;
        update(D, list[start]);
    }
}

//Prim MST, Adjacent Matrix

void update_matrix(vector<PrimNode>& D, vector<vector<int>>& matrix, int cur){
    D[cur].weight = 0;
    for(int i = 0; i < matrix[0].size(); i++){
        if(matrix[cur][i] < D[i].weight){
            D[i].index = cur;
            D[i].weight = matrix[cur][i];
        }
    }
}

void MST_Prim_Matrix(vector<vector<int>>& matrix, int start){
    vector<PrimNode> D(matrix.size(), INT_MAX);
    update_matrix(D, matrix, start);
    for(int i = 0; i < matrix.size() - 1; i++){
        int cur_min_index = minIndex(D);
        char u = D[cur_min_index].index + 'A';
        char v = cur_min_index + 'A';
        cout << u << "-----" << v << endl;
        start = cur_min_index;
        update_matrix(D, matrix, start);
    }

}


//Kruscal MST(Union Find). edges
class UnionFind{
private:
    vector<int> parents;
public:
    int count;
    explicit UnionFind(int nums): count(0){
        parents.resize(nums, -1);
    }

    int Find(int index){
        if(parents[index] == -1){
            parents[index] = index;
        }
        return parents[index] == index ? index : parents[index] = Find(parents[index]);
    }

    void Union(int index1, int index2){
        int p1 = Find(index1);
        int p2 = Find(index2);
        if(p1 == p2) return;
        count++;
        cout << (char)(index1 + 'A')  << "-----" << (char)(index2 + 'A') << endl;
        parents[p2] = p1;
    }
};

struct cmp{
    bool operator()(Edge& e1, Edge& e2){
        return e1.weight > e2.weight;
    }
};

void Kruscal_MST(vector<Edge>& edges){
    unordered_set<char> count;
    for(auto& e : edges){
        count.insert(e.v);
        count.insert(e.u);
    }
    priority_queue<Edge, vector<Edge>, cmp> que(edges.begin(), edges.end());
    UnionFind uf(count.size());
    while(uf.count < count.size() - 1 && !que.empty()){
        Edge cur = que.top();
        que.pop();
        uf.Union(cur.u - 'A', cur.v - 'A');
    }
}


int main(){
    Edge e1('A', 'B', 6);
    Edge e2('B', 'C', 4);
    Edge e3('C', 'D', 6);
    Edge e4('D', 'E', 8);
    Edge e5('E', 'F', 8);
    Edge e6('B', 'F', 10);
    Edge e7('E', 'C', 5);
    Edge e8('F', 'C', 7);
    Edge e9('B', 'E', 3);
    Edge e10('A', 'F', 1);
    vector<Edge> edges{e1, e2, e3, e4, e5, e6, e7, e8, e9, e10};
    vector<Vertex*> list(6);
    vector<vector<int>> matrix(6, vector<int>(6, INT_MAX));
    for(int i = 0; i < 6; i++){
        list[i] = new Vertex(i);
    }
    initAdjacentList(list, edges);
    cout << "Adjacent List end" << endl;
    initAdjacentMatrix(matrix, edges);
    cout << "Adjacent Matrix end" << endl;
    cout << "Prim Adjacent List result" << endl;
    MST_Prim_List(list, 0);
    cout << "Prim Adjacent Matrix result" << endl;
    MST_Prim_Matrix(matrix ,0);
    cout << "Kruscal Union Find result" << endl;
    Kruscal_MST(edges);

}