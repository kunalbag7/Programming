import java.util.*;
import java.io.*;

class dijkstra {
    int adjmat[][];
    boolean status[];
    final int INFINITY = 999;
    int cost[];
    int path[];

    dijkstra(int n) {
        Scanner sc = new Scanner(System.in);
        // Random r= new Random();
        adjmat = new int[n][n];
        status = new boolean[n];
        cost = new int[n];
        path = new int[n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                System.out.print("Vertex " + i + "th to " + j + "th vertex-->");
                adjmat[i][j] = sc.nextInt();
                adjmat[j][i] = adjmat[i][j];
                adjmat[i][i] = 0;
            }
        System.out.println("\nThe matrix is\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(adjmat[i][j] + "\t");
            }
            System.out.println("\n");
        }
        for (int i = 0; i < n; i++) {
            cost[i] = INFINITY;
            status[i] = false;
            path[i] = -2;
        }
    }

    int shortest_value(int v) {
        int temp = 0;
        int index = 0;
        for (int i = 0; i < v; i++)

        {
            if (!status[i]) {
                temp = cost[i];
                index = i;
                break;
            }
        }
        for (int i = 0; i < v; i++) {
            if (!status[i])
                if (cost[i] < temp) {
                    temp = cost[i];
                    index = i;
                }

        }
        return index;
    }

    boolean complete(int v) {
        for (int i = 0; i < v; i++) {
            if (status[i] == false)
                return false;
        }
        return true;
    }

    void disktra_main(int vstart, int v) {
        int temp, lowest_vertex;
        cost[vstart] = 0;
        path[vstart] = -1;
        while (!complete(v)) {
            lowest_vertex = shortest_value(v);
            for (int i = 0; i < v; i++) {
                if (!status[i]) {
                    if (adjmat[lowest_vertex][i] != 0) {
                        temp = adjmat[lowest_vertex][i] + cost[lowest_vertex];
                        if (cost[i] > temp) {
                            cost[i] = temp;
                            path[i] = lowest_vertex;
                        }
                    }

                }
            }
            status[lowest_vertex] = true;
        }

    }

    void path_print(int s, int v) {
        int j = 0;
        for (int i = 0; i < v; i++) {
            System.out.println("Distance from the vertex " + s + " to " + i + " is :" + cost[i]);
        }
        for (int i = 0; i < v; i++) {
            if (i != s)
                j = i;
            String pth = "V" + i;
            while (j != s) {
                pth = pth + " -> ";
                int temp = path[j];
                pth = pth + "V" + temp;
                j = temp;
            }
            System.out.println(pth);
        }
    }

    public static void main(String args[]) {
        int vertex, vstart;
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter number of vertices: ");
        vertex = sc.nextInt();
        dijkstra ob = new dijkstra(vertex);
        System.out.println("Enter Start vertex: ");
        System.out.print("Enter vertex number between 0 to " + (vertex - 1) + "--> ");
        vstart = sc.nextInt();
        ob.disktra_main(vstart, vertex);
        ob.path_print(vstart, vertex);
    }
}