import java.util.*;
import java.lang.*;
import java.io.*;

class FW {
    final int Infinity = 9999;
    int adjmat[][];

    FW(int n) {
        Scanner sc = new Scanner(System.in);
        // Random r= new Random();
        adjmat = new int[n][n];
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++) {
                System.out.print("Vertex " + (i+1) + "th to " + (j+1) + "th vertex-->");
                adjmat[i][j] = sc.nextInt();
                // adjmat[j][i] = adjmat[i][j];
                // adjmat[i][i] = 0;
            }
        System.out.println("\nThe matrix is\n");
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                System.out.print(adjmat[i][j] + "\t");
                if (adjmat[i][j] == 0 && i != j)
                    adjmat[i][j] = Infinity;
            }
            System.out.println("\n");
        }
    }

    void FloydWarshall(int V) {
        int dist[][] = new int[V][V];
        int i, j, k;
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++)
                dist[i][j] = adjmat[i][j];
        for (k = 0; k < V; k++) {
            for (i = 0; i < V; i++) {
                for (j = 0; j < V; j++) {
                    if (dist[i][k] + dist[k][j] < dist[i][j])
                        dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
        printSolution(dist, V);
    }

    void printSolution(int dist[][], int V) {
        System.out.println("The final matrix which shows that the shortest distance between vertex. ");
        for (int i = 0; i < V; ++i) {
            for (int j = 0; j < V; ++j) {
                if (dist[i][j] == Infinity)
                    System.out.print("INF ");
                else
                    System.out.print(dist[i][j] + " ");
            }
            System.out.println();
        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");
        int ver = sc.nextInt();
        FW ob = new FW(ver);
        ob.FloydWarshall(ver);
    }
}
