import java.util.*;
import java.io.*;

class prims {
    int adjmat[][];
    boolean status[];

    prims(int n) {
        Scanner sc = new Scanner(System.in);
        adjmat = new int[n][n];
        status = new boolean[n];
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
            status[i] = false;
        }

    }

    void prims_main(int vertex, int vstart) {
        int ne = 0, v1 = -1, v2 = -1;
        int max_cost = 0;
        status[vstart] = true;
        System.out.println("Edge\t:\tWeight");

        while (ne < vertex - 1) {

            int min = 9999;
            for (int i = 0; i < vertex; i++) {
                if (status[i])
                    for (int j = 0; j < vertex; j++) {
                        if (adjmat[i][j] != 0 && !status[j]) {
                            if (min > adjmat[i][j]) {
                                min = adjmat[i][j];
                                v1 = i;
                                v2 = j;
                            }
                        }
                    }
            }
            System.out.println(v1 + "-" + v2 + "\t:\t" + adjmat[v1][v2]);
            ne = ne + 1;
            status[v2] = true;

        }
    }

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the number of vertices: ");
        int ver = sc.nextInt();
        prims ob = new prims(ver);
        System.out.println("Enter the starting vertices: ");
        System.out.println("Enter vertices between 0 and " + (ver - 1) + ": ");
        int vstart = sc.nextInt();
        ob.prims_main(ver, vstart);
    }

}
