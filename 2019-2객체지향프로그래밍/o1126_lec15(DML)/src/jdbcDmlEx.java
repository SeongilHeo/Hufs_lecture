import java.sql.*;

public class jdbcDmlEx {
	public static void main(String args[]) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			String url = "jdbc:mysql://localhost:3306/studentdatabase?serverTimezone = UTC";
			Connection con =null;
			String usr = "root";
			String pwd ="cy7166xl";
			con = DriverManager.getConnection(url,usr,pwd);
			String sql = "UPDATE studentinfo SET addrress = ? WHERE name = ?";
			PreparedStatement pStmt = con.prepareStatement(sql);

			String addVar = args[0];
			String nameVar = args[1];

			pStmt.setString(1, addVar);
			pStmt.setString(2, nameVar);
			int num = pStmt.executeUpdate();
			System.out.println(num+"records updated");

			con.close();
		}catch(Exception sqlEx) {
			System.out.println(sqlEx);
		}//end catch
	}//end main
}//end class
