import java.net.*;
import java.io.*;
import java.util.*;

public class Chat_client {
    public static void main(String[] args) throws Exception {
        Socket s = new Socket("localhost", 11111);

        DataOutputStream dos = new DataOutputStream(s.getOutputStream());
        DataInputStream dis = new DataInputStream(s.getInputStream());

        System.out.println("Say 'Hi' to start chatting...");
        System.out.print("Say 'Bye'to stop chatting...\nMe: ");
        Scanner s1 = new Scanner(System.in);
        String str = "";
        str = s1.nextLine();
        while (true) {
            dos.writeUTF(str);
            dos.flush();
            String output = dis.readUTF();
            System.out.println("Server: " + output);
            if(output.equals("Say 'Hi' to talk with me.."))
            {
                System.out.println("You should say 'Hi' to start conversation with server.");
                break;
            }
            str = "";
            System.out.print("Me: ");
            str = s1.nextLine();
            if (str.equalsIgnoreCase("Bye")) {
                dos.writeUTF(str);
                dos.flush();
                String output1 = dis.readUTF();
                System.out.println("Server: " +output1);
                break;
            }
        }
        System.out.println("End of Conversation here");
        dos.close();
        dis.close();

        s.close();
        s1.close();

    }
}
