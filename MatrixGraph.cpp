#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t vertices_count) {

	vertices.resize(vertices_count);

	for (int i = 0; i < vertices_count; ++i) {

		vertices[i].resize(vertices_count);

		for (int j = 0; j < vertices_count; ++j) {

			vertices[i][j] = 0;

		}
	}
}

MatrixGraph::MatrixGraph(const IGraph& graph) {

	int vertices_count = graph.VerticesCount();
	vertices.resize(vertices_count);

	for (int from = 0; from < vertices_count; ++from) {

		vertices[from].assign(vertices_count, false);

		for (auto to : graph.GetNextVertices(from)) {

		vertices[from][to] = 1;

		}		
	}
}

void MatrixGraph::AddEdge(int from, int to) {

	vertices[from][to] = 1;
	
}

int MatrixGraph::VerticesCount() const {

	return vertices.size();

}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {

	std::vector<int> result;

	for (int to = 0; to < vertices.size(); ++to) {

		if (vertices[vertex][to] == 1) {

			result.push_back(to);

		}
	}
	return result;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {

	std::vector<int> result;
	
	for (int from = 0; from < vertices.size(); ++from) {

		if (vertices[from][vertex] == 1) {

			result.push_back(from);

		}		
	}
	return result;
}