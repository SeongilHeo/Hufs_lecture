import javax.swing.*;

public class TestAddBook{//메인 클래스
	public static void main(String args[]){
		AddressBook ad = new AddressBook();//메인 클래스 주소책 ad로 생성
		String input, s;//입력받을 거,
		int ch;//메뉴 번호
		while(true){
			try {
				input=JOptionPane.showInputDialog("Enter 1 to add"+"\nEnter 2 to Search \nEnter 3 to Delete"+"\nEnter 4 to Exit");//1추가, 2 검색, 3삭제, 4종료 입력받기

				ch=Integer.parseInt(input);//ch에 입력받은거 wrapper된 정수로 바꿔서 저장

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