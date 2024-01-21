//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node *buildTree(string str)
{
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N")
        {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N")
        {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}

// } Driver Code Ends
// User function Template for C++

/*

//Amit Kumar
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    Node *createNodeToParentRelation(Node *root, map<Node *, Node *> &nodeToParent, int &target)
    {

        // level order traverse karte chalenge
        queue<Node *> q;
        q.push(root);
        Node *targetNode = NULL;
        // root ka parent NULL
        nodeToParent[root] = NULL;

        while (!q.empty())
        {
            Node *front = q.front();
            q.pop();

            if (front->data == target)
            {
                targetNode = front;
            }
            if (front->left)
            {
                q.push(front->left);
                nodeToParent[front->left] = front;
            }
            if (front->right)
            {
                q.push(front->right);
                nodeToParent[front->right] = front;
            }
        }

        return targetNode;
    }
    int burningTree(Node *root, map<Node *, Node *> &nodeToParent)
    {
        // map to store visited nodes
        map<Node *, bool> visited;
        // queue for traversal
        queue<Node *> q;

        q.push(root);
        visited[root] = 1;
        bool flag = 0;
        int time = 0;
        while (!q.empty())
        {

            int size = q.size();
            flag = 0;
            for (int i = 0; i < size; i++)
            {

                Node *front = q.front();
                q.pop();

                // if left not visited
                if (front->left && !visited[front->left])
                {
                    flag = 1;
                    q.push(front->left);
                    visited[front->left] = 1;
                }
                // if right not visited
                if (front->right && !visited[front->right])
                {
                    flag = 1;
                    q.push(front->right);
                    visited[front->right] = 1;
                }

                // if parent not visited
                Node *parent = nodeToParent[front];
                if (parent && !visited[parent])
                {
                    flag = 1;
                    q.push(parent);
                    visited[parent] = 1;
                }
            }
            if (flag)
            {
                time++;
            }
        }
        return time;
    }

    int minTime(Node *root, int target)
    {
        // node to parent map
        map<Node *, Node *> nodeToParent;
        Node *targetNode = createNodeToParentRelation(root, nodeToParent, target);

        int time = burningTree(targetNode, nodeToParent);
        return time;
    }
};

//{ Driver Code Starts.

int main()
{
    int tc;
    scanf("%d ", &tc);
    while (tc--)
    {
        string treeString;
        getline(cin, treeString);
        // cout<<treeString<<"\n";
        int target;
        cin >> target;
        // cout<<target<<"\n";

        Node *root = buildTree(treeString);
        Solution obj;
        cout << obj.minTime(root, target) << "\n";

        cin.ignore();
    }

    return 0;
}

// } Driver Code Ends