#include <iostream>
#include <unordered_map>
#include <vector>

class Graph {
private:
    std::unordered_map<std::string, std::vector<std::string>> adjacencyList;

public:
    // Function to add a vertex to the graph
    void addVertex(const std::string& vertex) {
        if (adjacencyList.find(vertex) == adjacencyList.end()) {
            adjacencyList[vertex] = std::vector<std::string>();
        }
    }

    // Function to add an edge between two vertices
    void addEdge(const std::string& from, const std::string& to) {
        // Ensure that both vertices exist in the graph
        addVertex(from);
        addVertex(to);

        adjacencyList[from].push_back(to);
        adjacencyList[to].push_back(from); // For an undirected graph
    }

    // Function to print the graph
    void printGraph() {
        for (const auto& pair : adjacencyList) {
            const std::string& vertex = pair.first;
            const std::vector<std::string>& neighbors = pair.second;

            std::cout << vertex << " -> ";
            for (const std::string& neighbor : neighbors) {
                std::cout << neighbor << " ";
            }
            std::cout << std::endl;
        }
    }
};

int main() {
    Graph graph;

    graph.addVertex("A");
    graph.addVertex("B");
    graph.addVertex("C");
    graph.addVertex("D");

    graph.addEdge("A", "B");
    graph.addEdge("B", "C");
    graph.addEdge("C", "D");
    graph.addEdge("D", "A");

    graph.printGraph();

    return 0;
}
