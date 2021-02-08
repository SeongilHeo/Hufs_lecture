// File ResultSetEx3.java
import java.sql.*;
public class ResultSetEx3 {
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
		 // moving cursor to insert row
		rs.moveToInsertRow();
		// updating values in insert row
		rs.updateString( "PersonName" , "Charlie" );
		rs.updateString( "Address" , "Busan" );
		rs.updateString( "phoneNumber" , "1079201211" );
		// inserting row in resultset & into database
		rs.insertRow( );
		//Step 8: close the connection
		con.close();
	 	}
	catch(Exception sqlEx){
		System.out.println(sqlEx);
		}
 } // end main
} // end class