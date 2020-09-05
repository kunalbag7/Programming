import java.net.*;
import java.io.*;

class ServerFact {

    public static void main(final String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(11111);
        System.out.println("Server Waiting....");
        Socket s = ss.accept();

        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());

        String str = dis.readUTF();
        System.out.println("Client Sent this string ->" + str);

        palindrome ob = new palindrome();
        int r = ob.palindrome_check(str);

        if (r == 1)
            dos.writeUTF("This string is palindrome");
        else
            dos.writeUTF("This string is not palindrome");

        dos.flush();

        dos.close();
        dis.close();
        ss.close();

    }

}
