import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Main {
	JFrame f;
	JLabel l;

	public void initGUI() {
		f = new JFrame("moving");
		l = new JLabel("HELLO WORLD ");
		
		Container cont = f.getContentPane();
		l.setHorizontalAlignment(JLabel.CENTER);
		cont.add(l,BorderLayout.NORTH);

		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300,200);
		f.setVisible(true);
		
		cont.setFocusable(true);//Ű �̺����� ��Ŀ���� ���� �� �ִ� ������Ʈ�� ������ ���� �� �켱������ �Է¹ޱ� ���� ����
		cont.requestFocus();//Ű �̺�Ʈ�� ���� ������Ʈ�� ������ ����
		
		cont.addKeyListener(new KeyAdapter( ) {
			public void keyPressed(KeyEvent ke) {
				if(ke.getKeyCode() == KeyEvent.VK_LEFT) {
					String str = l.getText();
					
					StringBuffer sb = new StringBuffer(str);
					sb.append(sb.charAt(0));
					sb.deleteCharAt(0);
					l.setText(sb.toString());
				}
			}
		});
	}
	public Main() {
		initGUI();
	}
	public static void main(String args[]) {
		//Main eht = new Main();
	}

}
