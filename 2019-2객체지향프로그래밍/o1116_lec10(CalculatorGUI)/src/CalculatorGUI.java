import java.awt.*;
import javax.swing.*;

public class CalculatorGUI {
	JFrame fCalc;
	JButton b1,b2,b3,b4,b5;

	public void initGUI() {
		fCalc = new JFrame();
		
		b5 = new JButton("5");
		b1 = new JButton("1");
		b2 = new JButton("2");
		b3 = new JButton("3");
		b4 = new JButton("4");
		
		b1.setBackground(Color.red);
		b3.setBackground(Color.yellow);
		b2.setBackground(Color.orange);
		b4.setBackground(Color.green);
		b5.setBackground(Color.blue);

		Container con = fCalc.getContentPane();
		//con.setLayout(new BorderLayout());
		
		con.add(b1);
		con.add(b2);
		//con.add(b3,BorderLayout.WEST);
		//con.add(b4,BorderLayout.NORTH);
		//con.add(b5,BorderLayout.SOUTH);

		
		fCalc.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);

		fCalc.setSize(300,300);
		fCalc.setVisible(true);
	}
	public CalculatorGUI() {
		initGUI();
	}
	public static void main(String args[]) {
		CalculatorGUI calGUI = new CalculatorGUI();
	}
}