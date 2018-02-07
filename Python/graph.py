
import Queue

class Graph():
    def __init__(n):
        self.g = {}
        for i in range(n):
            node = raw_input("Node: ")
            conn = raw_input("Destinations: ")
            conn = conn.split()
            if(not node in g):
                g[node] = conn
        
    def dfs(self, graph):
        q = Queue.Queue()
        for node in graph:
            for element in graph.get(node):
                q.put(element) # insert each path in que queue

    def edges(self):
        edges = []
        for node in g:
            for dest in g[node]:
                edges.append((node, dest))
        return edges


if __name__ == "__main__":
    number = int(raw_input("Number of nodes: "))
    graph = Graph(number)
    print graph.edges()

