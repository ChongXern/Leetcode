#include <iostream>
#include <vector>
using namespace std;

class AdjListNode {
public:
    int val;
    int dist;
    AdjListNode* next;
    AdjListNode() {
        val = 0;
        dist = 999;
        next = NULL;
    }
    AdjListNode(int n, int d) {
        val = n;
        dist = d;
        next = NULL;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // Create a graph
        vector<AdjListNode*> adjList(n);
        //AdjListNode** adjList = new AdjListNode*[n];
        for (int i = 0; i < n; i++) {
            adjList[i] = new AdjListNode();
            adjList[i]->val = -1;
        }
        
        for (auto flight : flights) {
        
            int from = flight[0];
            int to = flight[1];
            int dist = flight[2];
            AdjListNode* newNode = new AdjListNode(to, dist);
            if (adjList[from]->val == -1) {
                adjList[from]->val = to;
                adjList[from]->dist = dist;
            } else {
                AdjListNode* temp = adjList[from];
                while (temp->next) {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }
        /*for (auto list : adjList) {
            AdjListNode* temp = list;
            while (temp) {
                cout << temp->val << ' ';
            }
            cout << endl;
        }*/
        return 0;
    }
};

int main(){
    int n;
    cout << "n: ";
    cin >> n;
    vector<vector<int>> flights;
    int read;
    cout << "Input graph:\n";
    vector<int> flight;
    for (int total = 0; cin >> read && read != -1; total++) {
        if (total % 3 == 0) {
            flights.push_back(flight);
            flight.clear();
        }
        flight.push_back(read);
    }
    int src, dst, k;
    cout << "Source: ";
    cin >> src;
    cout << "Destination: ";
    cin >> dst;
    cout << "k: ";
    cin >> k;
    Solution solution;
    cout << "SSSP is " << solution.findCheapestPrice(n, flights, src, dst, k) << endl;
}