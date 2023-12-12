import sys

def dijkstra(graph, start):
    distances = {vertex: sys.maxsize for vertex in graph} 
    distances[start] = 0  
    visited = set() 

    while len(visited) < len(graph):
        
        min_distance = sys.maxsize
        for vertex in graph:
            if vertex not in visited and distances[vertex] < min_distance:
                min_distance = distances[vertex]
                current_vertex = vertex

        visited.add(current_vertex)  

        
        for neighbor, weight in graph[current_vertex].items():
            if neighbor not in visited:
                new_distance = distances[current_vertex] + weight
                if new_distance < distances[neighbor]:
                    distances[neighbor] = new_distance

    return distances



graph = {
    'A': {'B': 5, 'C': 3},
    'B': {'A': 5, 'C': 2, 'D': 1},
    'C': {'A': 3, 'B': 2, 'D': 6},
    'D': {'B': 1, 'C': 6}
}
start_vertex = 'A'

shortest_distances = dijkstra(graph, start_vertex)
for vertex, distance in shortest_distances.items():
    print(f"Shortest distance from {start_vertex} to {vertex}: {distance}")
