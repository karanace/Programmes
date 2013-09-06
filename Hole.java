import java.io.*;
import java.util.*;
public class Main
{
	public static int main(String[] args) 
	{
			Set<Character> hole1 = new HashSet<Character>();
		     Set<Character> hole2 = new HashSet<Character>();
		     hole1.add('A');
		     hole1.add('D');
		     hole1.add('O');
		     hole1.add('P');
		     hole1.add('R');
		     hole1.add('Q');
		     hole2.add('B');
		     Console c = System.console();
		     int n  = Integer.parseInt(c.readLine());
		     for(int i=0;i<n;i++)
		     {
		     	int count =0;
		     	String s = c.readLine();
		     	for(int j=0;j<s.length();j++)
		     	{
		     		if(hole1.contains(s.charAt(j)))
		     		count++;
		     		else if(hole2.contains(s.charAt(j)) )
		     			count+=2;
		     	}
		     	System.out.println(count+"");
		     }
		     return 0;
	
	}	
}
