import java.util.LinkedList;

public class Vertex {
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
