import java.io.*;
import java.net.*;

class Host {
    public static void main(String[] args) {
        try {
            // IP Address
            InetAddress addr = InetAddress.getByName("www.amazon.com");

            // Host name
            System.out.println("Host name is: " + addr.getHostName());

            // Host Address
            System.out.println("Ip address is: " + addr.getHostAddress());
        } catch (UnknownHostException e) {
            System.out.println(e);
        }
    }
}