file1 = "grafo2.g"

output = "grafo.graphml"


with open(file1) as f:
    grafo1 = f.read()

grafo1 = grafo1.split("\n")
grafo1.remove('1') # start of the algorithm
grafo1.remove("13 21") # end of the algorithm and number of arestas

for conn in grafo1:
    nodes = conn.split()
    source = nodes[0]
    destination = nodes[1]
    weight = nodes[2]

    print(source, destination, weight)

print(grafo1)


