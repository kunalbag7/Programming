import java.net.*;
import java.io.*;
import java.util.*;
class file_client {

    public static void main(String[] args)throws Exception {
        Socket s= new Socket("localhost",11111);
        Scanner sc= new Scanner(System.in);
        DataInputStream dis= new DataInputStream(s.getInputStream());
        DataOutputStream dos= new DataOutputStream(s.getOutputStream());

        System.out.println("Enter File Name: ");
        String data=sc.nextLine();
        dos.writeUTF(data);
        dos.flush();
        String output=dis.readUTF();
        System.out.println(output);
        s.close();
        sc.close();
        dis.close();
        dos.close();


    }
    
}
