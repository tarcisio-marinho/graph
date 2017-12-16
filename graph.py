
import Queue


def create_graph(graph, elements):
    for e in range(elements):
        node = raw_input("Node> ")
        conn = raw_input("connects: ")
        conn = conn.split(" ")
        if(not node in graph):
            graph[node] = conn
        
def dfs(graph):
    q = Queue.Queue()
    for node in graph:
        for element in graph.get(node):
            q.put(element) # insert each path in que queue


if __name__ == "__main__":
    number = int(raw_input("Number of nodes: "))
    graph = {}

    create_graph(graph, number)
    dfs(graph)

