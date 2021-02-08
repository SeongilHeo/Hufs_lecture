import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class EventsWin  {
	JFrame f;
	JLabel coord;
	//inner class
/*	private class WindowHandler extends WindowAdapter{
		//Event Handler for WindowListener
		public void windowClosing(WindowEvent we) {
			JOptionPane.showMessageDialog(null, "Good Bye");
			System.exit(0);
		}
	}//end of WindowHandler*/
	private class MouseHandler extends MouseMotionAdapter{
		public void mouseMoved(MouseEvent me) {
			int x = me.getX();
			int y = me.getY();
			coord.setText("Moved at ["+x+","+y+"]");
		}
	}
	public void initGUI() {
		f = new JFrame();
		Container cont =  f.getContentPane();
		cont.setLayout(new BorderLayout());
		coord = new JLabel();
		cont.add(coord,BorderLayout.NORTH);
		/* Creating an object of the class which is handling our
		window events and registering it with generator */
/*		WindowHandler whandler = new WindowHandler();
		f.addWindowListener(whandler);*/
		MouseHandler mhandler = new MouseHandler();
		f.addMouseMotionListener(mhandler);
		f.addWindowListener(new WindowAdapter(){
			public void windowClosing(WindowEvent we) {
				JOptionPane.showMessageDialog(null, "Good Bye");
				System.exit(0);
			}
		}
		);
		
		
		f.setSize(350,350);
		f.setVisible(true);
	}
	public EventsWin() {
		initGUI();
	}
	public static void main(String args[]) {
		//EventsWin winex= new EventsWin();
	}

}
