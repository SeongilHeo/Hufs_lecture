import java.net.*;
import java.io.*;
import javax.swing.JOptionPane;

class Client {//CAl
	public static void main(String[] args){
		try{
			// 1. ������ IP�� ������ ���� ��Ʈ ��(10001)�� ���ڷ� �־� socket ����
			Socket sock = new Socket("10.10.2.16", 9939);
			// 2. ������ Socket���κ��� InputStream�� OutputStream�� ����
			OutputStream out = sock.getOutputStream();
			InputStream in = sock.getInputStream();
			// 3. InputStream�� BufferedReader �������� ��ȯ
			//    OutputStream�� PrintWriter �������� ��ȯ
			PrintWriter pw = new PrintWriter(new OutputStreamWriter(out));
			// 4. Ű����κ��� �� �پ� �Է¹޴� BufferedReader ��ü ����
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String line = null;
			// 5. Ű����κ��� �� ���� �Է¹���
			line =JOptionPane.showInputDialog("Note the format");
			pw.println(line);
			pw.flush();
			while((line = br.readLine()) != null){
				// 6. PrintWriter�� �ִ� println() �޼ҵ带 �̿��� �������� ����
				JOptionPane.showMessageDialog(null, line);
				pw.flush();
				line =JOptionPane.showInputDialog("Note the format");
				pw.println(line);
				pw.flush();
				// 7. ������ �ٽ� ��ȯ�ϴ� ���ڿ��� BufferedReader�� �ִ�
				//    readLine()�� �̿��ؼ� �о����
			}
			pw.close();
			br.close();
			sock.close();
		}catch(Exception e){
			System.out.println(e);
		}
	}
}
