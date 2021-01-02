import java.net.*;
import java.io.*; 
import java.util.*;
public class concurrent_tcp_client_1 {
    public static void main(String[] args)throws Exception {
        Socket s= new Socket("localhost",12345);
        DataInputStream dis =  new DataInputStream(s.getInputStream());
        DataOutputStream dos=new DataOutputStream(s.getOutputStream());
        System.out.println("Enetr a string: ");
        String str="";
        Scanner sc= new Scanner(System.in);
        str=sc.nextLine();
        PrintWriter pw= new PrintWriter(s.getOutputStream(),true);
        pw.println("Client 1");
        pw.println(str);

        String o= dis.readUTF();
        System.out.println("The string is: "+o);

        dos.close();
        dis.close();
        s.close();
        sc.close();

    }
}
