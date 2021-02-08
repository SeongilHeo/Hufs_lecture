// File ResultSetEx3.java
import java.sql.*;
public class MetaDataEx1 {
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
		 // get ResultSetMetaData object from rs
		ResultSetMetaData rsmd = rs.getMetaData( );
		// printing no. of column contained by rs
		int numColumns = rsmd.getColumnCount();
		System.out.println("Number of Columns:" + numColumns);
		// printing all column names by using for loop
		String cName;
		for(int i=1; i<= numColumns; i++) {
			cName = rsmd.getColumnName(i);
			System.out.print(cName);	
			System.out.print("\t\t");	
		}
		// changing line or printing an empty string
		System.out.println("\n");
		// printing all values of ResultSet by iterating over it
		String id, name, add, ph;
		while( rs.next() ) {
			id = rs.getString(1);
			name = rs.getString(2);
			add = rs.getString(3);
			ph = rs.getString(4);
			System.out.print(id);
			System.out.print("\t\t");
			System.out.print(name);
			System.out.print("\t\t");
			System.out.print(add);
			System.out.print("\t\t");
			System.out.print(ph);
			System.out.print("\n");
		} 
		System.out.println(rsmd.getColumnName(1));
		System.out.println(rsmd.getColumnType(2));
		//Step 8: close the connection
		con.close();
	 	}
	catch(Exception sqlEx){
		System.out.println(sqlEx);
		}
 } // end main
} // end class