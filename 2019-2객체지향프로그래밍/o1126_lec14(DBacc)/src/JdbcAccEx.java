import java.sql.*;
//step1

public class JdbcAccEx {


	public static void main(String[] args) {
		try {
			Class.forName("com.mysql.cj.jdbc.Driver");
			//step2
			String url= "jdbc:mysql://localhost:3306/studentdatabase?serverTimezone = UTC";
			//step3
			Connection connection=null;
			String username ="root";
			String password ="cy7166xl";
			connection= DriverManager.getConnection(url,username, password);
			//step4
			Statement st = connection.createStatement();
			String sql = "SELECT*FROM studentinfo";
			ResultSet rs = st.executeQuery(sql);
			while(rs.next()) {
				int count = rs.getInt("idstudentinfo");
				String add = rs.getString("name");
				System.out.println(count+" : "+add+"");
			}

			connection.close();
		}catch(SQLException sqlEx) {
			System.out.println(sqlEx);
		}
		catch(Exception e) {
			System.out.println(e);
		}
	}
}
