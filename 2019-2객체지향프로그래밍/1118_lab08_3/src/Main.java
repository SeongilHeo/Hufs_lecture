import java.awt.*;
import javax.swing.*;
import java.awt.event.*;
public class Main {
	JFrame f;
	JLabel l;
	int x, y;
	public void initGUI() {
		x = 100; 
		y = 100;
		f = new JFrame("Let's practice clicking");
		l = new JLabel("J");
		Container cont = f.getContentPane();
		cont.setLayout(null);
		l.setBounds(100, 100, 10, 10);

		cont.add(l);

		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(200,200);
		f.setVisible(true);

		cont.setFocusable(true);//Ű �̺����� ��Ŀ���� ���� �� �ִ� ������Ʈ�� ������ ���� �� �켱������ �Է¹ޱ� ���� ����
		cont.requestFocus();//Ű �̺�Ʈ�� ���� ������Ʈ�� ������ ����

		cont.addMouseListener(new MouseAdapter( ) {
			public void mouseClicked(MouseEvent Me) {
				x=(int)(Math.random()*225)+1;
				y=(int)(Math.random()*200)+1;
				l.setBounds(175,150, 10, 10);
				System.out.println();
			}
		});
	}
	public Main() {
		initGUI();
	}
	public static void main(String args[]) {
	//	Main eht = new Main();


	}

}
