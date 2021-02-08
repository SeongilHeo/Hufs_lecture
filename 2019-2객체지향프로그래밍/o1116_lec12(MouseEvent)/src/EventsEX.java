import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class EventsEX implements MouseMotionListener, WindowListener{
	JFrame frame;
	JLabel coord;
	public void initGUI() {
		//creating event generator
		frame = new JFrame();
		Container cont = frame.getContentPane();
		cont.setLayout(new BorderLayout());
		coord = new JLabel();
		cont.add(coord,BorderLayout.NORTH);
		
		//registring mouse event handler with generator
		frame.addMouseMotionListener(this);
		//registring widow handler with generator
		frame.addWindowListener(this);
		
		frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		frame.setSize(350,350);
		frame.setVisible(true);
	}
	public EventsEX() {
		initGUI();
	}
	//MouseMotionListener event handler handling dragging
	public void mouseDragged(MouseEvent me) {
		int x = me.getX();
		int y = me.getY();
		coord.setText("Dragged at ["+x+","+y+"]");
		
	}
	//mosemotionListener event handler handling motion
	public void mouseMoved(MouseEvent me) {
		int x = me.getX();
		int y = me.getY();
		coord.setText("Moved at["+x+","+y+"]");
	}
	public void windowActivated(WindowEvent we) {}
	public void windowClosed(WindowEvent we) {}
	public void windowClosing(WindowEvent we) {
		JOptionPane.showMessageDialog(null,"Good Bye");
		System.exit(0);
	}
	public void windowDeactivated(WindowEvent we) {}
	public void windowDeiconified(WindowEvent we) {}
	public void windowIconified(WindowEvent we) {}
	public void windowOpened(WindowEvent we) {}
	public static void main(String args[]) {
	//	EventsEX ex = new EventsEX();
	}
}
