import java.sql.*;
import java.util.Scanner;

public class Main {

	public static void main (String args[ ]) {
		Scanner scan = new Scanner(System.in);
		try {
			//Step 2: load driver
			Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
			//Step 3: define the connection URL
			String url = "jdbc:ucanaccess://C:/Users/tjddl/Desktop/bookdb.accdb";
			//Step 4: establish the connection
			Connection con = DriverManager.getConnection(url);
			//Step 5: create Statement
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
			
			sql = "DELETE FROM book WHERE id = ?";
			System.out.print("\nWhich data do you want to delete? ");
			String num = scan.next();
			ps = con.prepareStatement(sql);
			ps.setString(1, num);
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