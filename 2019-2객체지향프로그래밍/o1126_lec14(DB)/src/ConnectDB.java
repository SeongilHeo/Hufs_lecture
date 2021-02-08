import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.PreparedStatement;
//step1

public class ConnectDB {


	static Connection connection=null;
	static String url= "jdbc:mysql://localhost:3306/studentdatabase?serverTimezone = UTC";
	//step3
	static String username ="root";
	static String password ="cy7166xl";

	public static void main(String[] args) throws InstantiationException, IllegalAccessException, SQLException, ClassNotFoundException   {
		Class.forName("com.mysql.cj.jdbc.Driver");
		//step2
		connection= DriverManager.getConnection(url,username, password);
		//step4
		PreparedStatement ps = connection.prepareStatement("INSERT INTO studentdatabase.studentinfo(name)value('Ali Khan')");
		//step5
		int status = ps.executeUpdate();
		//step6
		if(status !=0) {
			System.out.println("Okay");
		}
		//step7
		connection.close();
		//step8

	}


}
