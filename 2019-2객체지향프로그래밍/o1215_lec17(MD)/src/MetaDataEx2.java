// File ResultSetEx3.java
import java.sql.*;
public class MetaDataEx2 {
  public static void main (String args[ ]) {
	try {
		//Step 2: load driver
		Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
		//Step 3: define the connection URL
		String url = "jdbc:ucanaccess://C:/Users/tjddl/Desktop/PersonInfo.accdb";
		//Step 4: establish the connection
		Connection con = DriverManager.getConnection(url);
		DatabaseMetaData dbMetaData = con.getMetaData();
		// printing database product name
		String pName = dbMetaData.getDatabaseProductName();
		System.out.println("DataBase: " + pName);
		// printing database product version
		String pVer = dbMetaData.getDatabaseProductVersion();
		System.out.println("Version: " + pVer);
		// printing driver name used to establish connection &
		// to retrieve data
		String dName = dbMetaData.getDriverName(); 
		System.out.println("Driver: " + dName);
		// printing whether database is read-only or not
		boolean rOnly = dbMetaData.isReadOnly();
		System.out.println("Read-Only: " + rOnly); 
		//Step 8: close the connection
		con.close();
	 	}
	catch(Exception sqlEx){
		System.out.println(sqlEx);
		}
 } // end main
} // end class