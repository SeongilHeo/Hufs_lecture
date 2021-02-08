import java.net.*;
import java.io.*;

public class Server {
	public static void main(String[] args){
		try{
			// 1. 10001�� ��Ʈ���� �����ϴ� ServerSocket�� ����
			ServerSocket server = new ServerSocket(9999);
			BufferedReader keyboard =new BufferedReader(new InputStreamReader(System.in));
			System.out.println("Wating for connection.");
			// 2. ServerSocket�� accept() �޼ҵ带 �����ؼ� Ŭ���̾�Ʈ�� ������ ���
			// : Ŭ���̾�Ʈ�� ������ ��� accept() �޼ҵ�� Socket ��ü�� ��ȯ
			Socket sock = server.accept();
			System.out.println("We are connected!");
			// 3. ��ȯ���� Socket���κ��� InputStream�� OutputStream�� ����
			OutputStream out = sock.getOutputStream();
			InputStream in = sock.getInputStream();
			// 4. InputStream�� BufferedReader �������� ��ȯ
			//    OutputStream�� PrintWriter �������� ��ȯ
			PrintWriter pw = new PrintWriter(new OutputStreamWriter(out));
			BufferedReader br = new BufferedReader(new InputStreamReader(in));
			String line = null;
			//5. BufferedReader�� readLine() �޼ҵ带 �̿���
			//   Ŭ���̾�Ʈ�� ������ ���ڿ� �� ���� �о����
			while((line = br.readLine()) != null){
				if(line.equals("Bye")) break;          
				System.out.println("Client : "+line);
				System.out.print("Sending>>");
				line = keyboard.readLine();
				// 6. PrintWriter�� println�� �̿��� �ٽ� Ŭ���̾�Ʈ�� ����
				pw.println(line);
				pw.flush();
			}
			System.out.println("Client said Bye!");
			// 6. IO ��ü�� ������ close() �޼ҵ� ȣ��
			pw.close();
			br.close();
			sock.close();

		} catch(Exception e){
			System.out.println(e);
		}
	}
}
