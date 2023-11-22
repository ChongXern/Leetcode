#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
using namespace std;

// Use BFS Approach

int minimumPath(vector<vector<int>> graph, int nodeSize, int from, int to) {
	if (from == to) {
		return 0;
	}
	vector<bool> visited(nodeSize + 1, false);
	vector<int> dist(nodeSize + 1, -1);
	queue<int> q;
	visited[from] = true;
	dist[from] = 0;
	q.push(from);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int neighbour : graph[curr]) {
			if (!visited[neighbour]) {
				cout << "NOT PRINTED";
				visited[neighbour] = true;
				dist[neighbour] = dist[curr] + 1;
				q.push(neighbour);
			}
			if (neighbour == to) {
				break;
				//return dist[neighbour];
			}
		}
		/*ListNode* temp = adjList[curr];
		//cout << "Hello World" << endl;
		while (temp) {
		int neighbour = temp->val;
		cout << "neighbor = " << neighbour << endl;
		if (!visited[neighbour]) {
		cout << "NOT PRINTED";
		visited[neighbour] = true;
		dist[neighbour] = dist[curr] + 1;
		q.push(neighbour);
		}
		if (neighbour == to) {
		break;
		//return dist[neighbour];
		}
		temp = temp->next;
		}*/
	}
	for (int d : dist) cout << d << ' ';
	cout << endl;
	return dist[to];
}

int main() {
	int nodeSize;
	cin >> nodeSize;
	//vector<ListNode*> adjList(nodeSize + 1, nullptr);
	vector<vector<int>> graph(nodeSize + 1, vector<int> (nodeSize + 1, -1));
	for (int i = 1; i <= nodeSize; i++) {
		vector<int> neighbours;
		//ListNode* head = nullptr;
		//ListNode* temp = head;
		cin.ignore();
		string line;
		getline(cin, line);
		istringstream iss(line);
		int neighbor;
		while (iss >> neighbor) {
			neighbours.push_back(neighbor);
			/*ListNode* newNode = new ListNode(neighbor);
			  if (!head) {
			  head = newNode;
			  temp = head;
			  } else {
			  temp->next = newNode;
			  temp = temp->next;
			  }
			  }*/
        }
		graph.push_back(neighbours);
		//adjList[i] = head;
	}
	int from, to;
	cin >> from;
	cin >> to;
	int shortest = minimumPath(graph, nodeSize, from, to);
	cout << "Shortest: " << shortest << endl;
}

