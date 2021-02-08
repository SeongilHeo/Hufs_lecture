//step0
import java.awt.*;
import javax.swing.*;
public class GUITest {
	//step1
	JFrame myFrame;
	JTextField tf;
	JButton b1;

	public void initGUI() {
		//step2
		myFrame = new JFrame();//프래임 생성
		//step3
		Container c = myFrame.getContentPane();
		//step4
		c.setLayout(new FlowLayout());
		//step5
		tf = new JTextField(10);
		b1 = new JButton("My Button");
		
		c.add(tf);
		c.add(b1);
		
		myFrame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		myFrame.setSize(200,150);
		myFrame.setVisible(true);
	}
	public GUITest() {
		initGUI();
	}
}
