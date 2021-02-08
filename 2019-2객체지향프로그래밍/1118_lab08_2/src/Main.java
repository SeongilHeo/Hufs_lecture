import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class Main {
	JFrame f;
	JLabel l;

	public void initGUI() {
		f = new JFrame("Left");
		l = new JLabel("Left Key");
		
		Container cont = f.getContentPane();
		l.setHorizontalAlignment(JLabel.CENTER);
		cont.add(l,BorderLayout.NORTH);

		f.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
		f.setSize(300,200);
		f.setVisible(true);
		
		cont.setFocusable(true);//키 이벤ㅌ의 포커스를 받을 수 있는 컴포넌트가 여러개 있을 때 우선적으로 입력받기 위해 설정
		cont.requestFocus();//키 이벤트를 받을 컴포넌트를 강제로 설정
		
		cont.addKeyListener(new KeyAdapter( ) {
			public void keyPressed(KeyEvent ke) {
				if(ke.getKeyCode() == KeyEvent.VK_LEFT) {
					String str = l.getText();
					
					StringBuffer sb = new StringBuffer();
					sb.append(str);
					l.setText(sb.reverse().toString());
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
