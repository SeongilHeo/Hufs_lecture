// File ResultSetEx4.java
import java.sql.*;
public class ResultSetEx4 {
  public static void main (String args[ ]) {
	try {
		//Step 2: load driver
		Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
		//Step 3: define the connection URL
		String url = "jdbc:ucanaccess://C:/Users/MBILAL/Documents/PersonInfo.accdb";
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
		// moves to last row of the resultset
		rs.last();
		// retrieving the current row number
		int rNo = rs.getRow();
		System.out.println("Moved to row number" + rNo);
		// delete current row from rs & db i.e. 4 because
		// previously we have called last() method
		rs.deleteRow( );
		System.out.println("Removed the row number" + rNo);
		//Step 8: close the connection
		con.close();
	 	}
	catch(Exception sqlEx){
		System.out.println(sqlEx);
		}
 } // end main
} // end class