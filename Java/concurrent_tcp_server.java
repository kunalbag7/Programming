import java.net.*;
import java.io.*; 
public class concurrent_tcp_server {
    public static void main(String[] args)throws Exception {
        ServerSocket ss = new ServerSocket(12345);
        System.out.println("Server is waiting..........");
        while(true)
        {
            Socket s = ss.accept();
            //System.out.println("4585");
            Thread t = new Thread(){
                public void run()
                {
                    try{
                        //System.out.println("4585");
                        BufferedReader br = new BufferedReader(new InputStreamReader(s.getInputStream()));
                        String c_name = br.readLine();
                        System.out.println("Client's name is: "+c_name);
                        String str = br.readLine();
                        System.out.println(c_name+" sent this string: "+str);
                        palindrome ob= new palindrome();
                        int r= ob.palindrome_check(str);
                        if(r==1){
                            System.out.println("This string is palindrome");
                            PrintWriter pw= new PrintWriter(s.getOutputStream(),true);
                            pw.println("Palindrome");
                        }
                        else
                        {
                            System.out.println("This string is not palindrome");
                            PrintWriter pw= new PrintWriter(s.getOutputStream(),true);
                            pw.println("not Palindrome");
                        }

                    }catch(Exception e){}
                }
            };
            t.start();
        }
    }
    
}
