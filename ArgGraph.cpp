#include "ArcGraph.h"



ArcGraph::ArcGraph(size_t vertices_count) {

	vertices.resize(vertices_count);

}

ArcGraph::ArcGraph(const IGraph& graph) {

	int vertices_count = graph.VerticesCount();
	vertices.resize(vertices_count);

	for (int i = 0; i < vertices_count; ++i) {

		vertices[i] = graph.GetNextVertices(i);

	}
}

void ArcGraph::AddEdge(int from, int to) {

	vertices[from].push_back(to);

}

int ArcGraph::VerticesCount() const {

	return vertices.size();
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {

	std::vector<int> result;
	for (int v : vertices[vertex]) {
		result.push_back(v);
	}
	return result;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {

	std::vector<int> result;

	for (int from = 0; from < vertices.size(); ++from) {
		for (int to : vertices[from]) {
			if (to == vertex) {
				result.push_back(from);
			}
		}
	}
	return result;
}



