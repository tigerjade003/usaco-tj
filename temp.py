
import sys
import math

def setIO(file=""):
    if file:
        sys.stdin = open(file + ".in", "r")
        sys.stdout = open(file + ".out", "w")
        
def valid(friends):

    for a in range(N):
        for b in range(a+1, N):
            if not friends[a][b]:
                continue
            for c in range(N):
                if c == a or c == b:
                    continue
                if not (friends[a][c] or friends[b][c]):
                    return False
    return True

def solve():
    minops = math.inf
    E = len(all_edges)

    for mask in range(1 << E):

        tempGraph = [row[:] for row in graph]
        changes = 0
        for i in range(E):
            u, v = all_edges[i]

            shouldHaveEdge = ((mask >> i) & 1) == 1
            if tempGraph[u][v] != shouldHaveEdge:
                tempGraph[u][v] = tempGraph[v][u] = shouldHaveEdge
                changes += 1
            if changes > minops:
                break
        if changes > minops:
            continue
        if valid(tempGraph):
            minops = min(minops, changes)
    return minops

def main():
    # setIO() 
    global N, M, graph, all_edges
    data = sys.stdin.read().split()
    it = iter(data)
    
    N = int(next(it))
    M = int(next(it))

    graph = [[False]*N for _ in range(N)]

    seen_edges = set()
    for _ in range(M):
        a = int(next(it)) - 1
        b = int(next(it)) - 1
        graph[a][b] = graph[b][a] = True
        seen_edges.add((a, b))
        seen_edges.add((b, a))

    all_edges = []
    for i in range(N):
        for j in range(i+1, N):
            all_edges.append((i, j))
    
    print(solve())

if __name__ == '__main__':
    main()
