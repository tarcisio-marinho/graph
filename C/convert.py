file1 = "grafo2.g"

output = "grafo.graphml"


start_file = """<?xml version="1.0" encoding="UTF-8"?>
<graphml xmlns="http://graphml.graphdrawing.org/xmlns"  
    xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
    xsi:schemaLocation="http://graphml.graphdrawing.org/xmlns
     http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd">
  <graph id="G" edgedefault="directed">\n"""

end_file = """  </graph>
</graphml>"""

new_node = ""

node_declaration = '    <node id="{}"/>\n'

edge_declaration = '    <edge source="{}" target="{}"/>\n'


with open(file1) as f:
    grafo1 = f.read()

grafo1 = grafo1.split("\n")
grafo1.remove('1') # start of the algorithm
grafo1.remove("13 21") # end of the algorithm and number of arestas

complete_file = ""
complete_file +=start_file

i = 1
while(i < 14):
    complete_file += node_declaration.format(i)
    i += 1


for conn in grafo1:
    nodes = conn.split()
    source = nodes[0]
    destination = nodes[1]
    weight = nodes[2]
    complete_file += edge_declaration.format(source, destination)

complete_file += end_file




print(complete_file)