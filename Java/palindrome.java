class palindrome 
{
    int palindrome_check(String str) {
        String temp="";
        int len= str.length();
        for(int i=len-1; i>=0; i--)
            temp=temp+str.charAt(i);
        
        if(str.equalsIgnoreCase(temp))
        return 1;
        else return 0;

    }
    
}
