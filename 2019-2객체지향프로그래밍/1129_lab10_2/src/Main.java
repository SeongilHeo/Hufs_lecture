import java.sql.*;
public class Main {

	public static void main (String args[ ]) {
		try {
			Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
			//Step 3: define the connection URL
			String url = "jdbc:ucanaccess://C:/Users/tjddl/Desktop/bookdb.accdb";
			//Step 4: establish the connection
			Connection con = DriverManager.getConnection(url);
			String sql = "SELECT * FROM book";
			PreparedStatement ps = con.prepareStatement(sql);
			//Step 6: preapare & execute the query
			ResultSet rs = ps.executeQuery();
			//Step 7: process the results
			while(rs.next()){
				//hence specified in the getString() method.
				int id = rs.getInt("id");
				String title = rs.getString("title");
				String publisher = rs.getString("publisher");
				String author = rs.getString("author");
				System.out.println(id + " | " + title + " | " + publisher + " | " + author);
			}
			
			System.out.println("");
			sql = "UPDATE book SET title = 'Hi Harry'  WHERE author = 'J. K. Rowling'";
			ps=con.prepareStatement(sql);
			ps.executeUpdate();
			sql = "SELECT * FROM book";
			ps=con.prepareStatement(sql);
			rs = ps.executeQuery();
			while(rs.next()){
				//hence specified in the getString() method.
				int id = rs.getInt("id");
				String title = rs.getString("title");
				String publisher = rs.getString("publisher");
				String author = rs.getString("author");
				System.out.println(id + " | " + title + " | " + publisher + " | " + author);
			}			
			
			//Step 8: close the connection
			con.close();
		}catch(Exception sqlEx){
			System.out.println(sqlEx);
		}
	} // end main
} // end class 