import javax.swing.*;
import java.awt.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.*;
import java.sql.*;

class Readingdata {
   JFrame frameRead;
   JPanel panel;
   JButton btnSearch,btnRank,btnDelete;
   JTable t1;
   JLabel jl1;
   JTextField tf;
   JScrollPane jsp;

   DefaultTableModel dfm = new DefaultTableModel(new String[]{"id","name","field","score"},0){ //for using JTable, we referred to the blog
      private static final long serialVersionUID = 1L; //this part has the default serial version id added because the yellow line appears
      public boolean isCellEditable(int r,int c) { //use to keep JTable data unchanged, referred to the blog
         return false;
      }
   };

   static Connection con = null;
   static String Participant = "";
   static String url = "jdbc:mysql://localhost:3306/Participant?serverTimezone=UTC";
   static String username = "root";
   static String password = "cy7166xl";

   Readingdata(){
      frameRead = new JFrame("Reading data");
      tf = new JTextField(10);
      btnSearch = new JButton("Search");
      btnRank = new JButton("Rank");
      btnDelete = new JButton("Delete");

      panel = new JPanel();
      panel.setLayout(new GridLayout(1,4));
      panel.setSize(200,100);
      panel.add(tf);
      panel.add(btnSearch);
      panel.add(btnRank);
      panel.add(btnDelete);

      Container c = frameRead.getContentPane();      

      btnSearch.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            try {
               dfm.setRowCount(0); //JTable default value of row and column
               dfm.setColumnCount(4);
               Class.forName("com.mysql.cj.jdbc.Driver");
               con = DriverManager.getConnection(url,username,password);
               String sql = "SELECT * FROM participant WHERE field=? OR name=?"; //use where(condition statement) to use select query
               PreparedStatement ps = con.prepareStatement(sql);
               ps.setString(1,tf.getText());
               ps.setString(2,tf.getText());
               ResultSet rs = ps.executeQuery();
               t1.setModel(dfm); //put values in JTable
               while(rs.next()) { 
                  dfm.addRow(new Object[]{ //we use int,string data, so use Object[] array
                        rs.getInt("id"),
                        rs.getString("name"),
                        rs.getString("field"),
                        rs.getString("score")
                  });
               }
               ps.close();
               con.close();

            }catch(Exception ex) {
               System.out.print(ex);
            }
         }
      });
      btnRank.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            try {
               dfm.setRowCount(0);
               dfm.setColumnCount(4);
               Class.forName("com.mysql.cj.jdbc.Driver");
               con = DriverManager.getConnection(url,username,password);
               //search results loaded in descending order
               String sql = "SELECT * FROM participant WHERE field=? OR name=? ORDER BY score DESC";
               PreparedStatement ps = con.prepareStatement(sql);
               ps.setString(1,tf.getText());
               ps.setString(2,tf.getText());
               ResultSet rs = ps.executeQuery();
               t1.setModel(dfm);
               while(rs.next()) {
                  dfm.addRow(new Object[]{
                        rs.getInt("id"),
                        rs.getString("name"),
                        rs.getString("field"),
                        rs.getString("score")
                  });
               }
               ps.close();
               con.close();

            }catch(Exception ex) {
               System.out.print(ex);
            }
         }
      });
      btnDelete.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            int row = t1.getSelectedRow(); //select a row
            String selected = t1.getModel().getValueAt(row, 0).toString(); //bring the 'id' of the selected row
            try {
               Class.forName("com.mysql.cj.jdbc.Driver");
               con = DriverManager.getConnection(url,username,password);
               if(row != -1) { //if you select a row
                  dfm.removeRow(t1.getSelectedRow());//selected row data remove in the table
                  String sql = "DELETE FROM participant WHERE id="+selected; //remove in the database too
                  PreparedStatement ps = con.prepareStatement(sql);
                  ps.executeUpdate();
                  t1.setModel(dfm);
               }
               con.close();
            }catch(Exception ex) {
               System.out.print(ex);
            }
         }
      });

      t1 = new JTable(dfm);
      jsp = new JScrollPane(t1); //put the table in the scrollPane
      jsp.setSize(100,50);

      c.add(panel,BorderLayout.NORTH);
      c.add(jsp,BorderLayout.CENTER);
      panel.setBorder(BorderFactory.createEmptyBorder(50,50,50,50));

      frameRead.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      frameRead.setSize(700,700);
      frameRead.setVisible(true);
      frameRead.pack();
   }
}