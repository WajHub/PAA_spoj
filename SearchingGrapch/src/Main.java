import java.util.LinkedList;
import java.util.Scanner;
public class Main {
    public static class Vertex {
        private int id;
        private LinkedList<Vertex> neighbours = new LinkedList<Vertex>();

        public Vertex(int id) {
            this.id = id;
        }
        public void addNeighbour(Vertex v) {
            neighbours.add(v);
        }

        public int getId() {
            return id;
        }

        public LinkedList<Vertex> getNeighbours() {
            return neighbours;
        }

        public boolean isNeighbour(Vertex v) {
            return neighbours.contains(v);
        }
    }

    public static class Graph {
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

        public void dfs(int vertexId, boolean visited[], int firstVertexId) {
            visited[vertexId-1] = true;
            if(vertexId!=firstVertexId) System.out.print(" "+vertexId);
            else System.out.print(vertexId);
            for(Vertex v : vertices[vertexId-1].getNeighbours()) {
                if(!visited[v.getId()-1]) {
                    dfs(v.getId(), visited, firstVertexId);
                }
            }
        }

        public void bfs(int vertexId) {
            LinkedList<Integer> queue = new LinkedList<Integer>();
            boolean visited[] = new boolean[size];
            queue.add(vertexId);
            visited[vertexId-1] = true;
            System.out.print(vertexId);
            while(!queue.isEmpty()){
                int currentVertexId = queue.poll();
                if(vertexId!=currentVertexId) System.out.print(" "+ currentVertexId);
                for(Vertex v : vertices[currentVertexId-1].getNeighbours()) {
                    if(!visited[v.getId()-1]) {
                        queue.add(v.getId());
                        visited[v.getId()-1] = true;
                    }
                }
            }
        }
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int numberOfGraphs = scanner.nextInt();
        for(int i = 0; i < numberOfGraphs; i++) {
            int numberOfVertices = scanner.nextInt();
            Graph graph = new Graph(numberOfVertices);
            for(int j=0; j<numberOfVertices; j++) {
                int from = scanner.nextInt();
                int size = scanner.nextInt();
                for(int k=0; k<size; k++) {
                    int to = scanner.nextInt();
                    graph.addEdge(from, to);
                }
            }
            System.out.println("graph " + (i + 1));
            int vertex = scanner.nextInt();
            int instruction = scanner.nextInt();
            while(vertex!=0) {
            //Wczytujemy numer wierzchlka oraz instrukjce
                if (instruction == 0) {
                    //dfs
                    graph.dfs(vertex, new boolean[graph.getSize()], vertex);
                    System.out.print("\n");
                } else {
                    //bfs
                    graph.bfs(vertex);
                    System.out.print("\n");
                }
                vertex = scanner.nextInt();
                instruction = scanner.nextInt();
            }

        }
    }
}