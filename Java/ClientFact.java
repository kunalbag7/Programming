import java.net.*;
import java.io.*;
import java.util.*;

class ClientFact {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("localhost", 11111);
        
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        DataInputStream dis = new DataInputStream(s.getInputStream());
        System.out.println("Enter A string: ");
        Scanner s1 = new Scanner(System.in);

        String str = "";
        str = s1.nextLine();
        dos.writeUTF(str);
        dos.flush();

        String output = dis.readUTF();
        System.out.println(output);
        dos.close();
        dis.close();

        s.close();
        s1.close();

        // fuck u

    }

}
