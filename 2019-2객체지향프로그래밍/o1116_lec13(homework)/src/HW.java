import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class HW {
	JFrame f;
	JButton A,U,D,S;
	JLabel N,As,P;
	JTextField n,a,p;
	JPanel P1, P2, P3;
	public void initGUI() {
		f = new JFrame();
		
	/*	GroupLayout L = new GroupLayout(P2);
		L.setAutoCreateGaps(true);
		L.setAutoCreateContainerGaps(true);*/
		
		
		
		P1 = new JPanel(new GridLayout(1,4));
		P2 = new JPanel(new GridLayout(3,1));
		P3 = new JPanel(new GridLayout(3,1));
		
		A = new JButton("Add");
		U = new JButton("Update");
		D = new JButton("Delete");
		S = new JButton("Search");
		
		N = new JLabel("Name:");
		As = new JLabel("Address:");
		P = new JLabel("Phone No.:");
		
		n = new JTextField(10);
		a = new JTextField(15);
		p = new JTextField(15);
		
/*		L.setHorizontalGroup(L.createSequentialGroup()
				.addComponent(N)
				.addComponent(U)
				.addComponent(D)
				.addComponent(S));
				*/
		P1.setBounds(10	, 10, 10, 20);
		P2.setSize(80,200);
		P3.setSize(200, 200);
		
		/*P1.setSize(P1.getPreferredSize().width,P1.getPreferredSize().height);
		P2.setSize(P2.getPreferredSize().width,P2.getPreferredSize().height);
		P3.setSize(P3.getPreferredSize().width,P3.getPreferredSize().height);*/
		
		P1.add(A);
		P1.add(U);
		P1.add(D);
		P1.add(S);
		
		P2.add(N);
		P2.add(As);
		P2.add(P);
		
		P3.add(n);
		P3.add(a);
		P3.add(p);

		Container cont = f.getContentPane();
		cont.setLayout(new BorderLayout());
		cont.add(P1,BorderLayout.NORTH);
		cont.add(P2,BorderLayout.WEST);
		cont.add(P3,BorderLayout.CENTER);
		
		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(530,300);
		f.setVisible(true);
		
		A.addActionListener(newne);
	}
	public HW() {
		initGUI();
	}
	public static void main (String args[]) {
		HW hw = new HW();
	}

}
