import java.awt.*;
import java.sql.*;
import javax.swing.*;
import javax.swing.table.DefaultTableModel;
import java.awt.event.*;

class PrintAward {
   JFrame framePrint;
   JButton btnPrint;
   JPanel panel;
   JRadioButton rb1,rb2,rb3,rb4;
   JTable t1;
   JScrollPane jsp;
   DefaultTableModel dfm = new DefaultTableModel(new String[]{"id","name","field","score"},0) {
      private static final long serialVersionUID = 1L;
      public boolean isCellEditable(int r,int c) {
         return false;
      }
   };
   int checked = 0;

   static Connection con = null;
   static String Participant = "";
   static String url = "jdbc:mysql://localhost:3306/Participant?serverTimezone=UTC";
   static String username = "root";
   static String password = "cy7166xl";

   ButtonHandler bhandler = new ButtonHandler();

   public PrintAward(){
      framePrint = new JFrame("Print Award");
      panel = new JPanel();
      panel.setLayout(new GridLayout(1,4));

      Container c = framePrint.getContentPane();

      rb1 = new JRadioButton("Ballet");//create Jradio Button
      rb2 = new JRadioButton("Dance");
      rb3 = new JRadioButton("Poppin");
      rb4 = new JRadioButton("Hiphop");

      rb1.addActionListener(bhandler);//addActionListener
      rb2.addActionListener(bhandler);
      rb3.addActionListener(bhandler);
      rb4.addActionListener(bhandler);

      ButtonGroup group = new ButtonGroup(); //use grouping to select only one button

      group.add(rb1);
      group.add(rb2);
      group.add(rb3);
      group.add(rb4);

      panel.add(rb1);
      panel.add(rb2);
      panel.add(rb3);
      panel.add(rb4);


      btnPrint = new JButton("print");
      btnPrint.setPreferredSize(new Dimension(100,100));

      btnPrint.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            print_output(checked);
         }
      });
      t1 = new JTable(dfm);
      t1.setRowHeight(40);
      t1.setFont(new Font("",Font.PLAIN, 15));
      jsp = new JScrollPane(t1);
      jsp.setSize(100,50);
      c.add(panel,BorderLayout.CENTER);
      c.add(btnPrint,BorderLayout.EAST);
      c.add(jsp,BorderLayout.SOUTH);
      panel.setBorder(BorderFactory.createEmptyBorder(50,50,50,50));
      framePrint.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
      framePrint.setSize(700,700);
      framePrint.setVisible(true);
      framePrint.pack();
   }
   public void print_output(int checked) {// to call POI class, to print 
      try {
         Class.forName("com.mysql.cj.jdbc.Driver");
         con = DriverManager.getConnection(url,username,password);
         dfm.setRowCount(0);
         dfm.setColumnCount(4);
         String sql = "SELECT * FROM participant WHERE field=? ORDER BY score DESC";// data of ? field , top to buttom
         PreparedStatement ps = con.prepareStatement(sql);
         if(checked == 1) {//check checked value, and set field
            ps.setString(1, "Ballet");
         }
         if(checked == 2) {
            ps.setString(1, "Dance");
         }
         if(checked == 3) {
            ps.setString(1, "Poppin");
         }
         if(checked == 4) {
            ps.setString(1, "Hiphop");
         }
         System.out.println(ps);
         ResultSet rs = ps.executeQuery();
         int rank =0;
         while(rs.next()) {// want to top 3 data
            rank ++;
            if(rank >3) {//finish 3 times
               break; 
            }
            String name = rs.getString("name");
            String field = rs.getString("field");
            new POI(name,field, Integer.toString(rank));
            if(POI.outcount==0) {//if first rank didn't print, break
               break;
            }
         }
         ps.close();
         con.close();
      }catch(Exception e) {
         e.printStackTrace();
      }
   }//end select output for print
   public void output(String field) {//show each field datas
      try {
         Class.forName("com.mysql.cj.jdbc.Driver");
         con = DriverManager.getConnection(url,username,password);
         dfm.setRowCount(0);
         dfm.setColumnCount(4);
         String sql = "SELECT * FROM participant WHERE field=? ORDER BY score DESC";//data of ? field, top to buttom
         PreparedStatement ps = con.prepareStatement(sql);
         ps.setString(1, field);
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
      }catch(Exception e) {
         e.printStackTrace();
      }
   }//end select output

   class ButtonHandler implements ActionListener{ //using handler class
      @Override
      public void actionPerformed(ActionEvent e) {
         try {

            if(e.getSource()==rb1) {
               checked = 1; //each radio button set 'checked'value
               output("Ballet");//and call 'output'method
            }//end if b1
            else if(e.getSource()==rb2) {
               checked = 2;
               output("Dance");
            }
            else if(e.getSource()==rb3) {
               checked = 3; 
               output("Poppin");
            }
            else if(e.getSource()==rb4) {
               checked = 4; 
               output("Hiphop");
            }
         }catch(Exception ex) {
            System.out.print(ex);
         }
      }//end actionper
   }//end butclass
}