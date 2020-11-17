import java.util.*;
import java.io.*;

class kruskal {
    int adjmat[][];
    int parent[];
    final int infinity = 999;

    kruskal(int n) {
        Scanner sc = new Scanner(System.in);
        // Random r= new Random();
        adjmat = new int[n][n];
        parent = new int[n];
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
                if (adjmat[i][j] == 0)
                    adjmat[i][j] = infinity;

            }
            System.out.println("\n");
        }
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }

    }

    int find(int i) {
        while (parent[i] != i)
            i = parent[i];
        return i;
    }

    void union(int i, int j) {
        int a = find(i);
        int b = find(j);
        parent[a] = b;
    }

    void kruskal_main(int v) {
        int min_cost = 0;
        int ne = 0;
        while (ne < v - 1) {
            int min = infinity;
            int v1 = -1, v2 = -1;
            for (int i = 0; i < v; i++) {
                for (int j = 0; j < v; j++) {
                    if (find(i) != find(j) && adjmat[i][j] < min) {
                        min = adjmat[i][j];
                        v1 = i;
                        v2 = j;
                    }
                }
            }
            union(v1, v2);
            ne = ne + 1;
            System.out.println("Edge " + ne + "\t" + "(" + v1 + " , " + v2 + ")\tCost:" + min);
            min_cost = min_cost + min;
        }
        System.out.println("Minimum Cost: " + min_cost);
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");
        int ver = sc.nextInt();
        kruskal ob = new kruskal(ver);
        ob.kruskal_main(ver);
    }
}
