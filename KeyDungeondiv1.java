public class KeyDungeonDiv2
{
	public static void main(String[] args) 
	{
			int[] r = {2,0,5,3};
			int[] g = {1,4,0,2};
			int[] keys = {2,3,1};
			System.out.println(countDoors(r,g,keys));
	}	
	public static int countDoors(int red[],int green[],int key[])
	{
		int count =0;
		for(int i=0;i<red.length;i++)
		{
			if(red[i] <= key[0] && green[i] <=key[1])
			count++;
			else if(red[i] <= key[0] && green[i] >key[1])
			{
				if(green[i] <= key[1] + key[2])
				count++	 ;
			}
			else if(red[i] > key[0] && green[i] <=key[1])	
			{	
				if(red[i] <= key[0] + key[2])
				count++	 ;
			}
			else
			{
				if(red[i] - key[0] + green[i] -key[1] >= key[2] )
				count++;				
			}
						
			
		}
		}
			}

