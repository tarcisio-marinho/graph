if __name__ == "__main__":

    file1 = "grafo2.g"

    output = "grafo2.graphml"


    start_file = """<?xml version="1.0" encoding="UTF-8"?>
    <graphml xmlns="http://graphml.graphdrawing.org/xmlns"  
        xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance"
        xsi:schemaLocation="http://graphml.graphdrawing.org/xmlns
        http://graphml.graphdrawing.org/xmlns/1.0/graphml.xsd">
    <key id="d1" for="edge" attr.name="weight" attr.type="int"/>
    <graph id="G" edgedefault="undirected">"""

    end_file = """  </graph>
</graphml>"""

    new_node = ""

    node_declaration = '        <node id="{}"/>\n'

    edge_declaration = '        <edge source="{}" target="{}">\n'

    key_declaration = '            <data key="d1">{}</data>\n'

    edge_end = '        </edge>\n'


    with open(file1) as f:
        grafo1 = f.read()

    grafo1 = grafo1.split("\n")
    grafo1.remove('1') # start of the algorithm
    grafo1.remove("13 21") # end of the algorithm and number of edges

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
        complete_file += edge_declaration.format(source, destination) + key_declaration.format(weight) + edge_end
                        

    complete_file += end_file


    with open(output, 'w') as f:
        f.write(complete_file)



    print(complete_file)