// File JdbcDmlEx.java
//step 1: import package
import java.sql.*;
public class JdbcDmlEx {
public static void main (String args[ ]) {
	try {
		//Step 2: load driver
		Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
		//Step 3: define the connection URL
		String url = "jdbc:ucanaccess://C:/Users/MBILAL/Documents/PersonInfo.accdb";
		//Step 4: establish the connection
		Connection con = DriverManager.getConnection(url);
		// make query and place ? where values are to be inserted later
		String sql = "UPDATE Person SET Address = ? WHERE PersonName = ? ";
		// Step 5: creating statement using Connection object 
		PreparedStatement pStmt = con.prepareStatement(sql);
		// assigning first command line argument value
		String addVar = args[0];
		// assigning second command line argument value
		String nameVar = args[1];
		// setting first marked parameter (?) by using setString()
		pStmt.setString(1 , addVar);
		// setting second marked parameter(?) by using setString()
		pStmt.setString(2 , nameVar);		
		
		// suppose address is "Daejeon" & name is "Alice"
		// by setting both marked parameters, the query will look
		// like:
		// sql = "UPDATE Person SET address = "Daejeon WHERE name = "Alice";
		
		//Step 6: executing update statemnt	
		int num = pStmt.executeUpdate();
		//Step 7: process the results of the query
				System.out.println(num + " records updated");
		//Step 8: close the connection
		con.close();
	}catch(Exception sqlEx){
	System.out.println(sqlEx);
}
} // end main
} // end class 