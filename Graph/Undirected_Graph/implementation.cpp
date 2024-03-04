#include <iostream>
#include <vector>
using namespace std;
struct Node
{
    int data;
    vector<Node *> neighbours;
};
class undirectedGraph
{
public:
    vector<Node *> undGraph;

    void insertNode(Node *newNode, int val)
    {
        newNode->data = val;
        this->undGraph.push_back(newNode);
    }

    void insertEdge(Node *source, Node *destination)
    {
        source->neighbours.push_back(destination);
    }
    void displayGraph()
    {

        for (auto i : undGraph)
        {
            cout << i->data << " : ";
            for (auto neigbour : i->neighbours)
            {
                cout << neigbour->data << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    undirectedGraph g1;
    Node *node1 = new Node();
    g1.insertNode(node1, 12);
    Node *node2 = new Node();
    g1.insertNode(node2, 40);
    g1.insertEdge(node1, node2);
    g1.displayGraph();
}