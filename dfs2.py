from collections import defaultdict


class Graph:


	def __init__(self):
		self.graph = defaultdict(list)

	def addEdge(self, u, v):
		self.graph[u].append(v)

	def DFS(self, v, visit):
		visit .add(v)
		print(v, end=' ')
		for i in self.graph[v]:
			if i not in visit:
				self.DFS(i, visit)

	def DFS(self, v):
		visit = set()
		self.DFS(v, visit)


d = Graph()
d.addEdge(1, 4)
d.addEdge(6, 5)
d.addEdge(2, 5)
d.addEdge(7, 6)
d.addEdge(3, 9)
d.addEdge(4, 7)

d.DFS(2)
