import java.io.*;

public class ReadEx{ 
	public static void main(String args[ ]){

		try {           
			FileInputStream fis   = new FileInputStream("Alice.dat");
			ObjectInputStream in = new ObjectInputStream(fis);
			//de - serialization 
			PersonInfo pRead = (PersonInfo) in.readObject( );  
			pRead.print();
			in.close();
			fis.close();
		} catch (Exception ex){
			System.out.println(ex) ;
		}
	}
}