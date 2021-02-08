// File ResultSetEx2.java
import java.sql.*;
public class ResultSetEx2 {
  public static void main (String args[ ]) {
	try {
		//Step 2: load driver
		Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
		//Step 3: define the connection URL
		String url = "jdbc:ucanaccess://C:/Users/tjddl/Desktop/PersonInfo.accdb";
		//Step 4: establish the connection
		Connection con = DriverManager.getConnection(url);
		//Step 5: creating PrepareStatement by passing sql and
		//ResultSet’s constants so that the ResultSet that will
		//produce as a result of executing query will be
		//scrollable & updatable
		String sql = "SELECT * FROM Person";
		PreparedStatement pStmt = con.prepareStatement(sql, ResultSet.TYPE_SCROLL_INSENSITIVE,ResultSet.CONCUR_UPDATABLE);
		//Step 6: execute the query
		ResultSet rs = pStmt.executeQuery();
		 // moving cursor to second row
		rs.absolute(-2);
		// update address column of 2nd row in rs
		rs.updateString("Address", "Mohut");
		 // update the row in database
		rs.updateRow( );
		//Step 8: close the connection
		con.close();
	}
	catch(Exception sqlEx){
		System.out.println(sqlEx);
	}
  } // end main
} // end class 