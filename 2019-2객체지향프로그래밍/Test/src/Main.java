import javax.swing.*;
import java.awt.*;

public class Main {
	  public static void main(String[] args) {
			JFrame myFrame;
			myFrame = new JFrame("Layout Practice");
			
			myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
				
			Container c = myFrame.getContentPane();
			c.setLayout(new BorderLayout());
			JPanel pa = new JPanel();
			pa.setLayout(null);
				
			JButton b0 = new JButton("North");
			JButton b1 = new JButton("West");
			JButton b2 = new JButton("East");
			JButton b3 = new JButton("South");
			
			int q = (int)(200*Math.random());
			int w = (int)(150*Math.random());
			int e =	(int)(200*Math.random());
			int r =	(int)(150*Math.random());
			int t =	(int)(200*Math.random());
			int y =	(int)(150*Math.random());
				
			JLabel mylabel1 = new JLabel();
			mylabel1.setText("java");
			mylabel1.setForeground(Color.magenta);
			mylabel1.setLocation(q,w);
			mylabel1.setSize(mylabel1.getPreferredSize().width,mylabel1.getPreferredSize().height);
			
			JLabel mylabel2 = new JLabel();
			mylabel2.setText("java");
			mylabel2.setForeground(Color.magenta);
			mylabel2.setLocation(e,r);
			mylabel2.setSize(mylabel2.getPreferredSize().width,mylabel2.getPreferredSize().height);
			
			JLabel mylabel3 = new JLabel();
			mylabel3.setText("java");
			mylabel3.setForeground(Color.magenta);
			mylabel3.setLocation(t,y);
			mylabel3.setSize(mylabel3.getPreferredSize().width,mylabel3.getPreferredSize().height);

			int horigap = 5;
			int vertgap = 7; 
				
			c.setLayout(new BorderLayout(horigap, vertgap));
				
			pa.add(mylabel1);
			pa.add(mylabel2);
			pa.add(mylabel3);

				
			c.add(b0, BorderLayout.NORTH);
			c.add(b1,BorderLayout.WEST);
			c.add(b2,BorderLayout.EAST);
			c.add(b3,BorderLayout.SOUTH);
			c.add(pa, BorderLayout.CENTER);

			
			
			myFrame.setSize(470,200);
			myFrame.setVisible(true);
			System.out.println(pa
					.getSize());
			System.out.println(mylabel3.getPreferredSize().width);
			System.out.println(mylabel3.getPreferredSize().height);


		  }
		}