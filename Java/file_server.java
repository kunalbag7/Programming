import java.net.*;
import java.io.*;

class file_server {

    public static void main(String[] args)throws Exception{
        ServerSocket ss= new ServerSocket(11111);
        System.out.println("Server is Waiting...");
        Socket s = ss.accept();
        DataInputStream dis= new DataInputStream(s.getInputStream());
        DataOutputStream dos= new DataOutputStream(s.getOutputStream());

        String file= dis.readUTF();
        System.out.println("Client sent this file: "+file);
        File_reading ob= new File_reading();
        String data=ob.file_content(file);
        dos.writeUTF(data);
        dos.flush();
        dis.close();
        dos.close();
        s.close();

        
    }
    
}
