import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Main {
	JFrame f;
	JLabel l,la;

	public void initGUI() {
		f = new JFrame("Say HI to JAVA");
		l = new JLabel("I'm JAVA");
		
		Container cont = f.getContentPane();
		l.setHorizontalAlignment(JLabel.CENTER);
		cont.add(l,BorderLayout.NORTH);

		cont.addMouseListener(new MouseAdapter() {
			public void mouseEntered(MouseEvent me) {
				l.setText("HI JAVA");
			}
		});
		cont.addMouseListener(new MouseAdapter( ) {
			public void mouseExited(MouseEvent me) {
				l.setText("I'm JAVA");				
			}
		});
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300,200);
		f.setVisible(true);
	}
	public Main() {
		initGUI();
	}
	public static void main(String args[]) {
		//Main eht = new Main();
	}

}
