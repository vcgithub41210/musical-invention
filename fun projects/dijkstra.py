class Node():
    def __init__(self,data,num_neigh):
        self.data = data
        self.num_neigh = num_neigh
        self.neighbours
        self.weights
    def enter_neighbours(self,graph):
        node_data = [nd.data for nd in graph]
        for i in range(num_neigh):
            test_data = int(input(f"Enter neighbour {i+1} of node with data {self.data}: "))
            while test_data not in node_data:
            test_data = int(input(f"Enter a valid neighbour {i+1} of node with data {self.data}: "))
            weight = int(input(f"Enter the weight of the edge: ")
            (self.neighbours).append(
if __name__ == "__main__":
    num_nodes = int(input("Enter the number of nodes: "))
    graph = []
    for i in range(num_nodes):
        data = int(input("Enter the data of the node: "))
        nu_neigh = int(input("Enter the number of neighbours: "))
        while  nu_neigh <= 0 or nu_weight > num_nodes:
            nu_neigh = int(input("Enter a valid number for neighbours: "))
        new_nd = Node(data,nu_neigh)
        graph.append(new_nd)

    for node in graph:
        node.enter_neighbours(graph)
