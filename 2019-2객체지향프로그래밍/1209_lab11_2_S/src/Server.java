import java.net.*;
import java.util.StringTokenizer;
import java.io.*;

public class Server {
	public static int plus(int a,int c) {
		return a + c;
	}//end plus
	public static int minus(int a,int c) {
		return a - c;
	}
	public static int multi(int a,int c) {
		return a * c;
	}
	public static void main(String[] args){
		try{
			// 1. 10001�� ��Ʈ���� �����ϴ� ServerSocket�� ����
			ServerSocket server = new ServerSocket(9939);
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
				System.out.println(line);
				StringTokenizer st = new StringTokenizer(line," ");
				int a = Integer.parseInt(st.nextToken());
				String b = st.nextToken();
				int c = Integer.parseInt(st.nextToken());
				int d =0;
				if (b.equals("+")) {
					d = plus(a,c);
				}
				else if (b.equals("-")){
					d = minus(a,c);
				}
				else {
					d = multi(a,c);
				}				// 6. PrintWriter�� println�� �̿��� �ٽ� Ŭ���̾�Ʈ�� ����
				pw.println(d);
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
		
	}//end main
}
