import javax.swing.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


class AddressBook{
	ArrayList<PersonInfo>persons;//personinfo class�� �ٿ�ĳ�����ؼ� persons��� ����Ʈ ����
	//������
	public AddressBook(){
		persons = new ArrayList<PersonInfo>();
		loadPersons();

	}//end construct
	//�Է¹����� list�� �߰�
	public void addPerson(){
		String name = JOptionPane.showInputDialog("Enter name");//�Է�â ����
		String add = JOptionPane.showInputDialog("sEnter address");
		String pNum = JOptionPane.showInputDialog("Enter phone no");

		PersonInfo p = new PersonInfo(name, add, pNum);//�ԷµȰɷ� p ��ü ���� personinfo Ÿ������
		persons.add(p);//list�� �߰�

	}//end add
	//�ݺ��ϸ鼭 ��� �˻�

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
			FileWriter fw = new FileWriter("persons1.txt");//����� ����
			PrintWriter pw = new PrintWriter(fw);  //�ֿܼ��� ��¹޴´� �޴´�?
			for(int i=0; i<persons.size(); i++)  { 
				p = (PersonInfo)persons.get(i);//����Ʈ���� ��� �޾Ƽ�
				line = p.name +", "+ p.address +", "+ p.phoneNum;//��¹����� �ٷ� �޾Ƽ� ����
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

	public void binarySearch(PersonInfo p, String I) {

		int first = 0;
		int end = p.name2.length-1;
		int mid = (first + end)/2;
		while(first<=end ) {
			if(p.name2[mid] > I.charAt(0)){
				end = mid-1;
				mid = (first + end)/2;
			}
			else if(p.name2[mid] < I.charAt(0)) {
				first = mid+1;
				mid = (first + end)/2;
			}
			else {break;}
		}
		int Index = p.name.indexOf(p.name2[mid]);
		for(int i=0; i<I.length();i++){
			if(p.name.charAt(Index+i)==I.charAt(i)) {}
			else {
				return;
				}
		}
		p.print();
	}
	public void searchPerson(String n){
		for(int i=0; i<persons.size();i++){//0 ���� person�� ũ�� ����
			PersonInfo p = (PersonInfo)persons.get(i);//�ε����� p�� �־
			if(n.equals(p.name)){//p�� �Էµ� n�̶� ������ ���
				p.print();
			}
			else{binarySearch(p,n);}
		}//end for
		
	}//end search
	public void deletePerson (String n) {
		for (int i=0; i< persons.size(); i++) {
			PersonInfo p = (PersonInfo)persons.get(i);
			if ( n.equals(p.name)) {
				persons.remove(i);
			}
		}
	}
}
// end class 