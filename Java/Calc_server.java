import java.net.*;
import java.io.*;
import java.util.*;

public class Calc_server {
    public static void main(String[] args) throws Exception {
        ServerSocket ss = new ServerSocket(11111);
        System.out.println("Server is Waiting for client....");
        Socket s = ss.accept();

        DataInputStream dis = new DataInputStream(s.getInputStream());
        DataOutputStream dos = new DataOutputStream(s.getOutputStream());

        String n1 = dis.readUTF();
        String n2 = dis.readUTF();
        String opr = dis.readUTF();

        Double num1 = Double.parseDouble(n1);
        Double num2 = Double.parseDouble(n2);
        Double result=0.0;

        System.out.println("Client send: " + n1 + opr + n2);
        int flag=0;
        switch (opr) {
            case "+":
                result = num1 + num2;
                break;
            case "-":
                result = num1 - num2;
                break;
            case "*":
                result = num1 * num2;
                break;
            case "/":
                if (num2 == 0) {
                    System.out.println("Division by 0 error.");
                    dos.writeUTF("Division by 0 error.");
                    dos.flush();
                    flag=1;
                    break;
                } else {
                    result = num1 + num2;
                    break;
                }
            default:
                    System.out.println(opr+" is an invalid operator");
                    dos.writeUTF("This is an invalid operator");
                    dos.flush();
                    flag=1;

        }

        System.out.println("Result: "+result);
        if(flag==0)
        {
            dos.writeUTF(Double.toString(result));
            dos.flush();
        }
        dos.close();
        dis.close();
        ss.close();
        s.close();

    }
}
