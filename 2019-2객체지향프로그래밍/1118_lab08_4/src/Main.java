import javax.swing.*;
import java.awt.*;
import java.awt.event.*;

public class Main implements ActionListener {
	JFrame f;
	JButton b0,b1,b2,b3,b4,b5,b6,b7,b8,b9;
	public void initGUI() {
		f = new JFrame("Ten Color Buttons Frame");

		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		Container c = f.getContentPane();
		c.setLayout(new GridLayout(1,10));

		b0 = new JButton("0");
		b1 = new JButton("1");
		b2 = new JButton("2");
		b3 = new JButton("3");
		b4 = new JButton("4");
		b5 = new JButton("5");
		b6 = new JButton("6");
		b7 = new JButton("7");
		b8 = new JButton("8");
		b9 = new JButton("9");

		c.add(b0);
		c.add(b1);
		c.add(b2);
		c.add(b3);
		c.add(b4);
		c.add(b5);
		c.add(b6);
		c.add(b7);
		c.add(b8);
		c.add(b9);

		b0.setBackground(Color.RED);
		b1.setBackground(Color.ORANGE);
		b2.setBackground(Color.YELLOW);
		b3.setBackground(Color.GREEN);
		b4.setBackground(Color.CYAN);
		b5.setBackground(Color.BLUE);
		b6.setBackground(Color.MAGENTA);
		b7.setBackground(Color.darkGray);
		b8.setBackground(Color.PINK);
		b9.setBackground(Color.lightGray);
		
		b0.addActionListener(this);
		b1.addActionListener(this);
		b2.addActionListener(this);
		b3.addActionListener(this);
		b4.addActionListener(this);
		b5.addActionListener(this);
		b6.addActionListener(this);
		b7.addActionListener(this);
		b8.addActionListener(this);
		b9.addActionListener(this);

		f.setSize(475,150);
		f.setVisible(true);

	}
	public Main() {
		initGUI();
	}
	public void actionPerformed(ActionEvent e) {
		Component c = (Component)e.getSource();
		if(c==b0) {
			JOptionPane.showMessageDialog(null, "RED");
		}		
		if(c==b1) {
			JOptionPane.showMessageDialog(null, "ORANGE");
		}		
		if(c==b2) {
			JOptionPane.showMessageDialog(null, "YELLOW");
		}	
		if(c==b3) {
			JOptionPane.showMessageDialog(null, "GREEN");
		}	
		if(c==b4) {
			JOptionPane.showMessageDialog(null, "CYAN");
		}		
		if(c==b5) {
			JOptionPane.showMessageDialog(null, "BLUE");
		}		
		if(c==b6) {
			JOptionPane.showMessageDialog(null, "MAGENTA");
		}		
		if(c==b7) {
			JOptionPane.showMessageDialog(null, "darkGray");
		}		
		if(c==b8) {
			JOptionPane.showMessageDialog(null, "PINK");
		}		
		if(c==b9) {
			JOptionPane.showMessageDialog(null, "lightGray");
		}		


	}
	public static void main(String[] args) {
		//Main m = new Main();
	}
}