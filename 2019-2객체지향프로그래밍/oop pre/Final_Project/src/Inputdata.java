import java.sql.*;
import java.awt.event.*;
import java.awt.*;
import javax.swing.*;

class Inputdata {
   JFrame frameInput;
   JPanel panel;
   JLabel jl1,jl2,jl3;
   JTextField tf1,tf2;
   JButton btnsave;
   JComboBox<String> cb;
   
   static Connection con = null; 
   static String Participant = "";
   static String url = "jdbc:mysql://localhost:3306/Participant?serverTimezone=UTC";
   static String username = "root";
   static String password = "cy7166xl";

   Inputdata(){
      frameInput = new JFrame("Input data");
      Container c = frameInput.getContentPane();
      String Concur[]= {"Dance","Ballet","Hiphop","Poppin"}; //JCombobox menu
      jl1 = new JLabel("Name");
      tf1 = new JTextField(20);
      jl2 = new JLabel("Field");
      cb = new JComboBox<String>(Concur);
      cb.setSelectedIndex(-1); //JCombobox not selected by default
      jl3 = new JLabel("Score");
      tf2 = new JTextField(20);
      btnsave = new JButton("Save");
      btnsave.setPreferredSize(new Dimension(50,50)); //to press the button better

      panel = new JPanel();
      panel.setLayout(new GridLayout(3,2,40,40)); //set margin for layout placement
      panel.setSize(200,100);
      panel.add(jl1);
      panel.add(tf1);
      panel.add(jl2);
      panel.add(cb);
      panel.add(jl3);
      panel.add(tf2);      

      btnsave.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            try {
               Class.forName("com.mysql.cj.jdbc.Driver");
                 con = DriverManager.getConnection(url,username,password);
               String sql = "INSERT INTO participant(name,field,score) VALUES(?,?,?)";
               PreparedStatement ps = con.prepareStatement(sql); //for continue use
               ps.setString(1,tf1.getText()); //bring text from first TextField
               ps.setString(2,cb.getSelectedItem().toString()); //bring text from JComboBox
               ps.setString(3, tf2.getText()); //bring text from second TextField
               ps.executeUpdate();
               JOptionPane.showMessageDialog(null, "Inserted Data"); //when data is stored, this message appear
               }catch(Exception ex){
                  System.out.print(ex);
                  }
            }
         });

      c.add(panel,BorderLayout.NORTH); //to maintain layout
      c.add(btnsave,BorderLayout.SOUTH);
      panel.setBorder(BorderFactory.createEmptyBorder(50,50,50,50)); //for the margin between swing components
      frameInput.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE); //to not close all the windows(not window operation system)
      frameInput.setSize(700,700);
      frameInput.setVisible(true);
      frameInput.pack(); //used to adjust windows to swing components
   }
}