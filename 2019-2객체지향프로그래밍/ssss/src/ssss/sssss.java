package ssss;
import java.io.*;
import java.util.ArrayList;

public class sssss{
	ArrayList<PersonInfo>persons;//personinfo class�� �ٿ�ĳ�����ؼ� persons��� ����Ʈ ����

	public void loadPersons(){ 
		String tokens[] = null; 

		String name, add, ph;

		try { 
			FileReader fr = new FileReader("persons.txt");//���� �о����
			BufferedReader br = new BufferedReader(fr);//���� �б� 
			String line = br.readLine();//���پ� �о line������ �Է�
			while ( line != null ) { //�ȳ�������
				tokens = line.split(",");//�� �Է¹����� ,�� �������� ��� token�̶�� �迭�� ����
				name = tokens[0];//ù��°�� ���� �̸�����
				add = tokens[1];//�ι����� ���� �ּҷ�
				ph = tokens[2]; //����°�� ���� ��ȭ��ȣ
				PersonInfo p =  new PersonInfo(name, add, ph);//personinfo��� ����ü�� ����
				persons.add(p); //�迭�� �߰�
				line = br.readLine(); 
			} //���ο� �� �а�// while back
			br.close();  //������ ���� �׸� �ް�
			fr.close(); //���� �׸� �ް�
		} catch(IOException ioEx){//���� ó�� ����¿��� 
			System.out.println(ioEx);//��� ������
		}
	}
	public void savePersons (){//��� ����
		try {  
			PersonInfo p;//�ڷ��� personinfo
			String line;//��
			FileWriter fw = new FileWriter("persons.txt");//����� ����
			PrintWriter pw = new PrintWriter(fw);  //�ֿܼ��� ��¹޴´� �޴´�?
			for(int i=0; i<persons.size(); i++)  { 
				p = (PersonInfo)persons.get(i);//����Ʈ���� ��� �޾Ƽ�
				line = p.name +","+ p.address +","+ p.phoneNum;//��¹����� �ٷ� �޾Ƽ� ����
				// writes line to file (persons.txt)  
				pw.println(line); //�ٹٲ�
			}  
			pw.flush(); 
			pw.close();//������
			fw.close();  //������
		} catch(IOException ioEx){//����ó��
			System.out.println(ioEx);
		} 
	}
}
