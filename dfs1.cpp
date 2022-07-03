#include<iostream>
#include<list>
#include<vector>
#include<stack>

using namespace std;

class Graph {

    private:

        int nodes;
        list<int> *adjlist;
        vector<bool> visit;

    public:


        Graph (int nodes) {
            adjlist = new list<int> [nodes];
            visit.resize(nodes, false);
            this->nodes = nodes;
        }

        Graph () {
        }

    void edge (int src, int dst) {
            adjlist[src].push_back(dst);
            adjlist[dst].push_back(src);
        }

        void DFS (int src) {
            visit[src] = true;
            cout << src << " ";
            for (auto& adj_node : adjlist[src]) {
                if (!visit[adj_node]) {
                    DFS(adj_node);
                }
            }
        }

       void DFS_Iterative (int src) {

           stack<int> stk;
           visit[src] = true;
           stk.push(src);

           while (!stk.empty()) {
               src = stk.top();
               stk.pop();
               cout << src << " ";
               for (auto &adj_node : adjlist[src]) {
                   if (!visit[adj_node]) {
                       visit[adj_node] = true;
                       stk.push(adj_node);
                   }
               }
           }
       }
};
int main()
{

    Graph g(9);
    g.edge(0,1);
    g.edge(0,2);
    g.edge(1,3);
    g.edge(1,4);
    g.edge(2,3);
    g.edge(3,5);
    g.edge(4,6);
    g.edge(5,6);
    cout << "Depth First Traversal(starting from vertex 2)"<<endl;

    g.DFS(4);

return 0;
}

