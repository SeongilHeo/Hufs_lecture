import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
public class Main {

	public static void main (String args[ ]) {
		String [] str = {"Harry Poter", "Bloomsbury", "J. K. Rowling",
				"The Lord of the Rings", "Allen & Unwin", "J. R. R. Tolkein",
				"Pride and Prejudice","T. Egerton Kingdom","Jane Austen",
				"The Twilight Saga","Little, Brown and Company","Stephenie Meyer"};
		try {
			//Step 2: load driver
			Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
			//Step 3: define the connection URL
			String url = "jdbc:ucanaccess://C:/Users/tjddl/Desktop/bookdb.accdb";
			//Step 4: establish the connection
			Connection con = DriverManager.getConnection(url);
			//Step 5: create Statement
			String sql = "SELECT * FROM book";
			PreparedStatement ps = con.prepareStatement(sql, ResultSet.TYPE_SCROLL_INSENSITIVE, ResultSet.CONCUR_UPDATABLE);
			//Step 6: preapare & execute the query
			ResultSet rs = ps.executeQuery();			//Step 7: process the results
			int i = 0;
			while(i <10) {
				rs.next();
				sql = "INSERT INTO book(title, publisher, author)Values(?,?,?)";
				ps = con.prepareStatement(sql);
				ps.setString(1, str[i]);
				ps.setString(2, str[i+1]);
				ps.setString(3, str[i+2]);
				i = i+3;
				ps.executeUpdate();
			}
			sql = "SELECT * FROM book";
			ps=con.prepareStatement(sql);
			rs = ps.executeQuery();			//Step 7: process the results
			while(rs.next()){
				//hence specified in the getString() method.2
				int id = rs.getInt("id");
				String title = rs.getString("title");
				String publisher = rs.getString("publisher");
				String author = rs.getString("author");
				System.out.println(id + " | " + title + " | " + publisher + " | " + author);
			}
			con.close();
			//Step 8: close the connection
		}catch(Exception e){
			System.out.println(e);
		}
	} // end main
} // end class 