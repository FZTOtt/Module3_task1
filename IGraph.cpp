/*#include <vector>
#include <iostream>
#include <queue>

struct IGraph {
	virtual ~IGraph() {}

	// Добавление ребра от from к to.
	virtual void AddEdge(int from, int to) = 0;

	virtual int VerticesCount() const = 0;

	virtual std::vector<int> GetNextVertices(int vertex) const = 0;
	virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};


class ListGraph : public IGraph {
public:

	ListGraph(size_t vertices_count) {
		vertices.resize(vertices_count);
		prev_vertices.resize(vertices_count);
	}

	ListGraph(const IGraph& graph);

	virtual ~ListGraph() {}


	virtual void AddEdge(int from, int to) override {
	
		vertices[from].push_back(to);

	}

	virtual int VerticesCount() const override {
		
		return vertices.size();
	}

	virtual std::vector<int> GetNextVertices(int vertex) const override {

		std::vector<int> result;
		for (int v : vertices[vertex]) {
			result.push_back(v);
		}
		return result;
	}

	virtual std::vector<int> GetPrevVertices(int vertex) const override {
		std::vector<int> result;
		for (int v : prev_vertices[vertex]) {
			result.push_back(v);
		}
		return result;
	}

private:
	std::vector<std::vector<int>> vertices;
	std::vector<std::vector<int>> prev_vertices;
};
*/