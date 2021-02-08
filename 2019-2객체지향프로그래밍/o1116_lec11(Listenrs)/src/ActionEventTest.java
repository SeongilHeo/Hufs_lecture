import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class ActionEventTest implements ActionListener{
	JFrame frame;
	JButton bHello;
	public void initGUI() {
		frame = new JFrame();
		bHello = new JButton("Hello");//event generator
		
		Container con = frame.getContentPane();
		con.add(bHello);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(200,200);
		frame.setVisible(true);
		
		bHello.addActionListener(this);//event registration
	}
	public ActionEventTest() {
		initGUI();
	}
	public void actionPerformed(ActionEvent ae) {
		JOptionPane.showMessageDialog(null,"Hello is pressed");
	}
	public static void main(String args[]) {
		//ActionEventTest aeTest = new ActionEventTest();
	} 

}
