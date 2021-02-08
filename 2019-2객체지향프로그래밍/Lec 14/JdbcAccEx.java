// File JdbcEx.java
//Step 1: Import package
import java.sql.*;
public class JdbcAccEx {
public static void main (String args[ ]) {
try {
//Step 2: load driver
Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
//Step 3: define the connection URL
String url = "jdbc:ucanaccess://C:/Users/MBILAL/Documents/PersonInfo.accdb";
//Step 4: establish the connection
Connection con = DriverManager.getConnection(url);
//Step 5: create Statement
Statement st = con.createStatement();
//Step 6: preapare & execute the query
String sql = "SELECT * FROM Person";
ResultSet rs = st.executeQuery(sql);
//Step 7: process the results
while(rs.next()){
// The row name is “name” in database “PersonInfo,
// hence specified in the getString() method.
String name = rs.getString("Person Name");
String add = rs.getString("Address");
String pNum = rs.getString("PhoneNumber");
System.out.println(name + " " + add + " " + pNum);
}
//Step 8: close the connection
con.close();
}catch(Exception sqlEx){
System.out.println(sqlEx);
}
} // end main
} // end class 