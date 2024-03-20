#include <iostream>
#include <vector>

using namespace std;

class Edge {
public:
    int source;
    int destination;
    int weight;

    Edge(int src, int dest, int w) : source(src), destination(dest), weight(w) {}
};

class Graph {
private:
    int Vert; // num of vertices
    vector<vector<int>*> neighbors; // neighbors to edges
    vector<Edge*> edges;

public:
    //constructor
    Graph(int vertices) : Vert(vertices) {
        neighbors.resize(Vert);
        for (int i = 0; i < Vert; ++i)
            neighbors[i] = new vector<int>;
    }

    void addVertex() {
        Vert++;
        //push_back adds vector to end of list
        neighbors.push_back(new vector<int>);
    }

    // adds edges building the neighborhood
    void addEdge(int src, int dest, int weight) {
        neighbors[src]->push_back(dest);
        neighbors[dest]->push_back(src);
        edges.push_back(new Edge(src, dest, weight));
    }

    // Dijkstra's shortest path algorithm
    vector<int> shortestPath(int source, int destination) {
        vector<int> distance(Vert, INT_MAX);
        vector<int> parent(Vert, -1);
        vector<bool> visited(Vert, false);
        distance[source] = 0;

        for (int i = 0; i < Vert - 1; ++i) {
            int curr= minDistance(distance, visited); //index of vertex with shortest dist
            visited[curr] = true;

            for (int adj : *(neighbors[curr])) {
                int weight = getWeight(curr, adj);

                if (!visited[adj] && distance[curr] != INT_MAX && distance[curr] + weight < distance[adj]) {
                    distance[adj] = distance[curr] + weight;//updates shortest dist
                    parent[adj] = curr;
                }
            }
        }

        vector<int> shortestPath;
        int current = destination;
        while (current != -1) {
            shortestPath.push_back(current);
            current = parent[current];
        }
        reverseVector(shortestPath);
        return shortestPath;
    }

    //Kruskal's minimum spanning tree algorithm
    vector<Edge*> minSpanTree() {
    vector<Edge*> result;
    vector<int> parent(Vert, -1);
    int edgesAdded = 0;

    for (Edge* edge : edges) {
        int src = find(parent, edge->source);
        int dst = find(parent, edge->destination);

        if (src != dst) {//cant have an edge between src & src
            result.push_back(edge);
            parent[src] = dst; // combines set
            edgesAdded++;
        }

        if (edgesAdded == Vert - 1)
            break;
    }
    return result;
}
    //deconstruct
    ~Graph() {
        for (vector<int>* vec : neighbors)
            delete vec;
        for (Edge* edge : edges)
            delete edge;
    }

private:
    int minDistance(vector<int>& distance, vector<bool>& visited) {
        int minDist = INT_MAX;
        int minIndex = -1;

        for (int i = 0; i < Vert; ++i) {
            if (!visited[i] && distance[i] <= minDist) {
                minDist = distance[i];
                minIndex = i;
            }
        }
        return minIndex;
    }
    //recursively gets root
    int find(vector<int>& parent, int i) {
        if (parent[i] == -1)
            return i;
        return find(parent, parent[i]);
    }

    int getWeight(int curr, int adj) {
        for (Edge* edge : edges) {
            if ((edge->source == curr && edge->destination == adj) || (edge->source == adj && edge->destination == curr))
                return edge->weight;
        }
        return -1; //edge DNE
    }

    void reverseVector(vector<int>& v) {
        int left = 0;
        int right = v.size() - 1;
        // cout << "right:" << right << endl;
        // cout << "left:" << left << endl;
        while (left < right) {
            swap(v[left], v[right]);
            left++;
            right--;
            // cout << "right:" << right << endl;
            // cout << "left:" << left << endl;
        }
    }
};

int main() {

    Graph graph(10);
    //(source, destination, weight)
    graph.addEdge(1, 6, 10);
    graph.addEdge(1, 2, 3);
    graph.addEdge(2, 6, 5);
    graph.addEdge(5, 6, 1);
    graph.addEdge(4, 5, 2);
    graph.addEdge(4, 5, 2);
    graph.addEdge(5, 2, 5);

    // Create MST
    cout << "Minimum Spanning Tree edges:" << endl;
    vector<Edge*> minSpanTree = graph.minSpanTree();
    //test edges were created
    for (Edge* edge : minSpanTree) {
        cout << edge->source << " - " << edge->destination << " : " << edge->weight << endl;
    }

    // shortest path btwn 5 & 1 should return 5 2 1
    cout << "\nShortest Path from 5 to 1:" << endl;
    vector<int> shortestPath = graph.shortestPath(5,1);
    for (int vertex : shortestPath) {
        cout << vertex << " ";
    }
    return 0;
}