package excass;
import java.awt.*; 
import javax.swing.*;

public class jung  {
	JFrame fCalc; JButton b1, b2, b3, b4, b5, b6, b7, b8, b9, b0; JButton bPlus, bMinus, bMul, bPoint, bEqual, bClear;
	JPanel pButtons;
	JTextField tfAnswer;
	JLabel lMyCalc;

	public void initGUI( ) {  //used for setting layout of calculator
		fCalc = new JFrame();
		b0  =  new JButton("0"); 
		b1  =  new JButton("1"); 
		b2  =  new JButton("2"); 
		b3  =  new JButton("3"); 
		b4  =  new JButton("4"); 
		b5  =  new JButton("5"); 
		b6  =  new JButton("6"); 
		b7  =  new JButton("7"); 
		b8  =  new JButton("8"); 
		b9  =  new JButton("9");
		bPlus =  new JButton("+"); 
		bMinus =  new JButton("-"); 
		bMul =  new JButton("*"); 
		bPoint =  new JButton("."); 
		bEqual =  new JButton("="); 
		bClear =  new JButton("C");

		tfAnswer= new JTextField();
		lMyCalc = new JLabel("My Clacualator");
		//creating panel object and setting its layout this will go in center of borderlayout 
		pButtons = new JPanel(new GridLayout(4,4));
		//adding components (buttons) to panel 
		pButtons.add(b1); 
		pButtons.add(b2); 
		pButtons.add(b3);        
		pButtons.add(bClear); 
		pButtons.add(b4); 
		pButtons.add(b5); 
		pButtons.add(b6);        
		pButtons.add(bMul);

		pButtons.add(b7); pButtons.add(b8); pButtons.add(b9);        pButtons.add(bMinus);
		pButtons.add(b0); pButtons.add(bPoint); pButtons.add(bPlus);        pButtons.add(bEqual); 
		Container con = fCalc.getContentPane(); 
		con.setLayout(new BorderLayout());
		//adding components to container 
		con.add(tfAnswer, BorderLayout.NORTH); 
		con.add(lMyCalc, BorderLayout.SOUTH); 
		con.add(pButtons, BorderLayout.CENTER);
		fCalc.setSize(300, 300); fCalc.setVisible(true);  
	} // end of initGUImetho
	//default constructor 
	public jung ( ) { initGUI(); }
	//main method 
	public static void main(String args[ ]) {
		jung calGUI = new jung();
	}
} //end of class