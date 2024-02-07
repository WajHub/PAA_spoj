import java.util.LinkedList;

public class Graph {
    private Vertex [] vertices;
    private int size;

    public Graph(int size) {
        vertices = new Vertex[size];
        for(int i = 0; i < size; i++) {
            vertices[i] = new Vertex(i+1);
        }
        this.size = size;

    }

    public void addEdge(int from, int to) {
        vertices[from-1].addNeighbour(vertices[to-1]);
    }

    public int getSize() {
        return size;
    }
    public void printGraph() {
        for(int i = 0; i < vertices.length; i++) {
            System.out.print(vertices[i].getId() + " -> ");
            LinkedList<Vertex> neighbours = vertices[i].getNeighbours();
            for(int j = 0; j < neighbours.size(); j++) {
                System.out.print(neighbours.get(j).getId() + " ");
            }
            System.out.println();
        }
    }



    public void dfs(int vertexId, boolean visited[]) {
        visited[vertexId-1] = true;
        System.out.print(vertexId + " ");
        for(Vertex v : vertices[vertexId-1].getNeighbours()) {
            if(!visited[v.getId()-1]) {
                dfs(v.getId(), visited);
            }
        }
    }

    public void bfs(int vertexId) {
        LinkedList<Integer> queue = new LinkedList<Integer>();
        boolean visited[] = new boolean[size];
        queue.push(vertexId);
        visited[vertexId-1] = true;
        while(!queue.isEmpty()){
            int currentVertexId = queue.poll();
            System.out.print(currentVertexId + " ");
            for(Vertex v : vertices[currentVertexId-1].getNeighbours()) {
                if(!visited[v.getId()-1]) {
                    queue.add(v.getId());
                    visited[v.getId()-1] = true;
                }
            }
        }
    }
}
