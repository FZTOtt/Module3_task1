#include "IGraph.h"
#include "ListGraph.h"
#include "MatrixGraph.h"


void dfs_aux(int u, const IGraph& graph, std::vector<bool>& visited, void (*callback)(int v)) {

	visited[u] = true;
	callback(u);

	std::vector<int> children = graph.GetNextVertices(u);

	for (int v : children) {
		if (!visited[v]) {
			dfs_aux(v, graph, visited, callback);
		}
	}
	return;
}

int dfs(const IGraph& graph, void (*callback)(int v)) {

	int vertices_count = graph.VerticesCount();
	std::vector<bool> visited;

	visited.assign(vertices_count, false);
	for (int i = 0; i < vertices_count; ++i) {
		if (!visited[i]) {
			dfs_aux(i, graph, visited, callback);
		}
	}
	return 0;
}

void bfs_aux(int u, const IGraph& graph, std::vector<bool>& visited, void (*callback)(int v)) {

	std::queue<int> q;
	q.push(u);
	visited[u] = true;
	while (!q.empty()) {

		int v = q.front();
		q.pop();

		callback(v);

		std::vector<int> children = graph.GetNextVertices(u);
		for (int w : children) {
			if (!visited[w]) {
				visited[w] = true;
				q.push(w);
			}
		}
	}
	return;
}

int bfs(const IGraph& graph, void (*callback)(int v)) {

	int vertices_count = graph.VerticesCount();

	std::vector<bool> visited;

	visited.assign(vertices_count, false);
	for (int i = 0; i < vertices_count; ++i) {
		if (!visited[i]) {
			bfs_aux(i, graph, visited, callback);
		}
	}
	return 0;
}

int main() {

	ListGraph graph(6);

	graph.AddEdge(0, 1);
	graph.AddEdge(1, 0);

	graph.AddEdge(1, 2);
	graph.AddEdge(2, 1);

	graph.AddEdge(2, 3);
	graph.AddEdge(3, 2);

	graph.AddEdge(2, 4);
	graph.AddEdge(4, 2);

	graph.AddEdge(3, 4);
	graph.AddEdge(4, 3);

	dfs(graph, [](int v) {
		std::cout << v << ' ';
		});
	std::cout << std::endl;

	bfs(graph, [](int v) {
		std::cout << v << ' ';
		});
	std::cout << std::endl;

	return 0;
}