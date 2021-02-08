import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Design extends MouseAdapter {

   JFrame myf;
   JButton b1;
   JButton b2;
   JButton b3;
   JButton b4;
   JButton b5;
   JButton b6;
   JButton b7;
   JButton b8;
   JButton b9;
   Container c;
   public static int image = 0; //want to use other class(POI.class) if didn't create this class

   public Design() {
      try {

         myf = new JFrame("Design");
         b1 = new JButton();
         b2 = new JButton();
         b3 = new JButton();
         b4 = new JButton();
         b5 = new JButton();
         b6 = new JButton();
         b7 = new JButton();
         b8 = new JButton();
         b9 = new JButton();

         ImageIcon [] images = {//load image icon
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img1.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img2.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img3.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img4.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img5.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img6.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img7.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img8.png"),
               new ImageIcon("/C://Users//tjddl/eclipse-workspace/Final_Project/img/img9.png"),
         };
         Image [] img = {//get image
               images[0].getImage(),
               images[1].getImage(),
               images[2].getImage(),
               images[3].getImage(),
               images[4].getImage(),
               images[5].getImage(),
               images[6].getImage(),
               images[7].getImage(),
               images[8].getImage(),
         };
         Image [] rimg = {//set as A4 ratio
               img[0].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[1].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[2].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[3].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[4].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[5].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[6].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[7].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
               img[8].getScaledInstance(210, 297, Image.SCALE_SMOOTH),
         };
         ImageIcon [] icon = {//Re-Iconize the set image
               new ImageIcon(rimg[0]),
               new ImageIcon(rimg[1]),
               new ImageIcon(rimg[2]),
               new ImageIcon(rimg[3]),
               new ImageIcon(rimg[4]),
               new ImageIcon(rimg[5]),
               new ImageIcon(rimg[6]),
               new ImageIcon(rimg[7]),
               new ImageIcon(rimg[8]),
         };
         b1.setIcon(icon[0]);//add button icon
         b2.setIcon(icon[1]);
         b3.setIcon(icon[2]);
         b4.setIcon(icon[3]);
         b5.setIcon(icon[4]);
         b6.setIcon(icon[5]);
         b7.setIcon(icon[6]);
         b8.setIcon(icon[7]);
         b9.setIcon(icon[8]);

         b1.addMouseListener(this);
         b2.addMouseListener(this);
         b3.addMouseListener(this);
         b4.addMouseListener(this);
         b5.addMouseListener(this);
         b6.addMouseListener(this);
         b7.addMouseListener(this);
         b8.addMouseListener(this);
         b9.addMouseListener(this);

         c = myf.getContentPane();
         c.setLayout(new GridLayout(3,3));

         c.add(b1);//add button to panel
         c.add(b2);
         c.add(b3);
         c.add(b4);
         c.add(b5);
         c.add(b6);
         c.add(b7);
         c.add(b8);
         c.add(b9);

         myf.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
         myf.setSize(900, 900);
         myf.setVisible(true);
      }catch(Exception e) {
         e.printStackTrace();
      }
   }
   public void mouseClicked (MouseEvent e)  {
      if (e.getSource().equals(b1))      {   
         image = 1;    
         JOptionPane.showMessageDialog(null,"Selected image1");
         myf.dispose();
      }
      else if (e.getSource().equals(b2)) {    
         image = 2;    
         JOptionPane.showMessageDialog(null,"Selected image2");
         myf.dispose();
      }
      else if (e.getSource().equals(b3)) {   
         image = 3;    
         JOptionPane.showMessageDialog(null,"Selected image3");
         myf.dispose();
      }
      else if (e.getSource().equals(b4)) {   
         image = 4; 
         JOptionPane.showMessageDialog(null,"Selected image4");
         myf.dispose();
      }
      else if (e.getSource().equals(b5)) {   
         image = 5;    
         JOptionPane.showMessageDialog(null,"Selected image5");
         myf.dispose();
      }
      else if (e.getSource().equals(b6)) {   
         image = 6;
         JOptionPane.showMessageDialog(null,"Selected image6");
         myf.dispose();
      }
      else if (e.getSource().equals(b7)) {   
         image = 7;    
         JOptionPane.showMessageDialog(null,"Selected image7");
         myf.dispose();
      }
      else if (e.getSource().equals(b8)) {   
         image = 8;    
         JOptionPane.showMessageDialog(null,"Selected image8");
         myf.dispose();
      }
      else if (e.getSource().equals(b9)) {   
         image = 9;    
         JOptionPane.showMessageDialog(null,"Selected image9");
         myf.dispose();
      }
   }
}