import javax.swing.*;

public class TestAddBook{//���� Ŭ����
	public static void main(String args[]){
		AddressBook ad = new AddressBook();//���� Ŭ���� �ּ�å ad�� ����
		String input, s;//�Է¹��� ��,
		int ch;//�޴� ��ȣ
		while(true){
			try {
				input=JOptionPane.showInputDialog("Enter 1 to add"+"\nEnter 2 to Search \nEnter 3 to Delete"+"\nEnter 4 to Exit");//1�߰�, 2 �˻�, 3����, 4���� �Է¹ޱ�

				ch=Integer.parseInt(input);//ch�� �Է¹����� wrapper�� ������ �ٲ㼭 ����

				switch(ch){
				case 1:
					ad.addPerson();
					break;
				case 2:
					s = JOptionPane.showInputDialog("Enter name to search");
					ad.searchPerson(s);
					break;
				case 3:
					s = JOptionPane.showInputDialog("Enter name to delete");
					ad.deletePerson(s);
					break;
				case 4:
					ad.savePersons();
					System.exit(0);
				default:
					JOptionPane.showMessageDialog(null,"Chose from 1,2,3,4");
					break;
				}
			}catch(NumberFormatException nfe) {
				JOptionPane.showMessageDialog(null, "Don't do that");
				continue;
			}//end Switch	
		}//end while
	}//end main
}//end TestAddBookclass