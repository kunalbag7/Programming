import java.net.*;
import java.io.*;
import java.util.*;

public class calc_client {
    public static void main(String[] args) throws Exception {

        Socket s = new Socket("localhost", 11111);

        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        DataInputStream dis = new DataInputStream(s.getInputStream());

        String n1, n2, operator;

        Scanner sc = new Scanner(System.in);

        System.out.println("Enter the two numbers: ");
        n1 = sc.nextLine();
        n2 = sc.nextLine();

        System.out.println("Enter the operator (+, -, *, /)");
        operator = sc.nextLine();

        dos.writeUTF(n1);
        dos.flush();
        dos.writeUTF(n2);
        dos.flush();
        dos.writeUTF(operator);
        dos.flush();

        String output = dis.readUTF();

        if (output.equals("Division by 0 error.") || output.equals("This is an invalid operator")) {
            System.out.println(output);
        }

        else {
            Double Result = Double.parseDouble(output);
            System.out.println("Result: " + Result);
        }

        dos.close();
        dis.close();

        s.close();
        sc.close();

    }

}
