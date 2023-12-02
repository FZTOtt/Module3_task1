#include "SetGraph.h"



SetGraph::SetGraph(size_t vertices_count) {

	vertices.resize(vertices_count);

}

SetGraph::SetGraph(const IGraph& graph) {

	int vertices_count = graph.VerticesCount();
	
	for (int from = 0; from < vertices_count; ++from) {

		for (int to : graph.GetNextVertices(from)) {

			vertices[from].insert(to);

		}
	}
}

void SetGraph::AddEdge(int from, int to) {

	vertices[from].insert(to);

}

int SetGraph::VerticesCount() const {

	return vertices.size();

}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {

	std::vector<int> result;
	
	for (int to : vertices[vertex]) {

		result.push_back(to);

	}
	return result;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {

	std::vector<int> result;
	int from = 0;
	for (int from = 0; from < vertices.size(); from++)
	{

		if (vertices[from].find(vertex) != vertices[from].end())

			result.push_back(from);

	}
	return result;
}



