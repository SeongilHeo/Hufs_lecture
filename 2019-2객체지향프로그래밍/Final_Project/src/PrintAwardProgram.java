import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class PrintAwardProgram {
   JFrame frame;
   JButton btnInput,btnRead,btnDesign,btnPrint;

   public void initGUI() {
      frame = new JFrame("Award Print Program"); 
      Container c = frame.getContentPane();
      c.setLayout(new GridLayout(2,2));

      btnInput = new JButton("Input Data");
      btnRead = new JButton("Reading Data");
      btnDesign = new JButton("Design");
      btnPrint = new JButton("Print Award");

      c.add(btnInput);
      c.add(btnRead);
      c.add(btnDesign);
      c.add(btnPrint);

      frame.setSize(600,600);
      frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
      frame.setVisible(true);
      
      btnDesign.addActionListener(new ActionListener() {
          @Override
          public void actionPerformed(ActionEvent e) {
             new Design();
          }
       });
      btnInput.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            new Inputdata();
         }
      });
      btnRead.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            new Readingdata();
         }
      });
      btnPrint.addActionListener(new ActionListener() {
         @Override
         public void actionPerformed(ActionEvent e) {
            new PrintAward();
         }
      });
   }
   public PrintAwardProgram() { //constructor
      initGUI();
   }
   public static void main(String args[]) {
      new PrintAwardProgram();
   }
}