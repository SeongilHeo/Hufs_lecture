import java.io.*;

public class WriteEx{
	public static void main(String args[ ]){
		PersonInfo pWrite = new PersonInfo("Alice", "Seoul", "1089201211");
		try {           
			FileOutputStream fos   = new FileOutputStream("Alice.dat");
			ObjectOutputStream out = new ObjectOutputStream(fos);

			
			//Socket s = new Socket("10.10.0.248",9999);
			
			//OutputStream os = s.getOutputStream();
			//ObjectOutputStream oos = new ObjectOutputStream(os);
			//oos.writeObject(pWrite);
			//serialization 
			out.writeObject(pWrite);  
			
			//oos.close();
			//os.close();
			out.close(); 
			fos.close();
		} catch (Exception ex){ 
			System.out.println(ex); 
		}
	}
}
