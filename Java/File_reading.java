import java.io.FileInputStream;

class File_reading {

    String file_content(String fileName)throws Exception 
    { 
        try{
            FileInputStream fr = new FileInputStream(fileName);
            int m;
            String data="";
            while ((m=fr.read()) != -1)
                data=data+ (char)m;

            fr.close();

            return data;
        }
        catch(Exception e)
        {
            String data="The file not found";
            return data;
        }
        
      
    }
}