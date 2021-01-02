import java.net.*;
import java.io.*;
import java.util.*;

public class Chat_server {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(11111);
        System.out.println("Server is Waiting for client....");
        Socket s = ss.accept();

        Scanner s1 = new Scanner(System.in);

        System.out.println("Welcome here...");
        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());

        String str1 = dis.readUTF();
        if (str1.equalsIgnoreCase("Hi")) {
            String str = "Hi";
            while (true) {

                System.out.println("client: " + str);
                str = "";
                System.out.print("Me: ");
                str = s1.nextLine();
                dos.writeUTF(str);
                dos.flush();
                str = dis.readUTF();
                if (str.equalsIgnoreCase("Bye")) {
                    str = "Nice to meet you..";
                    dos.writeUTF(str);
                    dos.flush();
                    System.out.println("client: Bye");
                    break;
                }
            }

        } else {
            String str = "Say 'Hi' to talk with me..";
            System.out.println("Error message.");
            dos.writeUTF(str);
            dos.flush();
        }
        System.out.println("End of the Conversation here");
        dos.close();
        dis.close();
        ss.close();
        s1.close();
        s.close();
    }
}
