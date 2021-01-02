import java.net.*;
import java.io.*; 
import java.util.*;
public class concurrent_client_2 {
    public static void main(String[] args)throws Exception {
        Socket s= new Socket("localhost",12345);
        DataInputStream dis =  new DataInputStream(s.getInputStream());
        DataOutputStream dos=new DataOutputStream(s.getOutputStream());
        System.out.println("Enetr a string: ");
        String str="";
        Scanner sc= new Scanner(System.in);
        str=sc.nextLine();
        dos.writeUTF("Client 2");
        dos.flush();
        dos.writeUTF(str);
        dos.flush();

        String o= dis.readUTF();
        System.out.println("The string is: "+o);

        dos.close();
        dis.close();
        s.close();
        sc.close();

    }
}
