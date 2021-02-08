import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;
import java.sql.PreparedStatement;


public class ConnectDB {
	

	// DB connection variable
	
	static Connection connection=null;
	static String databaseName= "";
	static String url= "jdbc:mysql://localhost:3306/"+databaseName;
	//static String url= "jdbc:odbc:SQLDSN2://localhost:3306/";
	static String username ="root";
	static String password ="13264590_Mysql";
	

	
	public static void main(String[] args) throws InstantiationException, IllegalAccessException, ClassNotFoundException, SQLException   {
		
			Class.forName("com.msql.jdbc.Driver");
			connection= DriverManager.getConnection(url,username, password);
			PreparedStatement ps= connection.prepareStatement("INSERT INTO 'studentdatabase'.'studentinfo'('student_name') VALUES('Ali Khan');");
			//we didn't insert the id record as i licked on auto update 
			
			//PreparedStatement ps = connection.prepareStatement("CREATE DATABASE databasename");
			int status = ps.executeUpdate(); //If execution is successful the return vaue will be >0
			if(status!=0) {
				System.out.println("Database was connected  and record was Insterted");				
			}
			
	}
			
	
}
