import javax.swing.*;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;


class AddressBook{
	ArrayList<PersonInfo>persons;//personinfo class로 다운캐스팅해서 persons라는 리스트 만듦
	//생성자
	public AddressBook(){
		persons = new ArrayList<PersonInfo>();
		loadPersons();

	}//end construct
	//입력받은거 list에 추가
	public void addPerson(){
		String name = JOptionPane.showInputDialog("Enter name");//입력창 띄우기
		String add = JOptionPane.showInputDialog("sEnter address");
		String pNum = JOptionPane.showInputDialog("Enter phone no");

		PersonInfo p = new PersonInfo(name, add, pNum);//입력된걸로 p 객체 생성 personinfo 타입으로
		persons.add(p);//list에 추가

	}//end add
	//반복하면서 사람 검색

	public void loadPersons(){ 
		String tokens[] = null; 

		String name, add, ph;

		try { 
			FileReader fr = new FileReader("persons.txt");//파일 읽어오기
			BufferedReader br = new BufferedReader(fr);//버퍼 읽기 
			String line = br.readLine();//한줄씩 읽어서 line변수에 입력
			while ( line != null ) { //안끝낫으면
				tokens = line.split(",");//랑 입력받은걸 ,을 기준으로 끊어서 token이라는 배열에 넣음
				name = tokens[0];//첫번째에 들어간거 이름으로
				add = tokens[1];//두번쨰에 들어간거 주소로
				ph = tokens[2]; //세번째에 들어간거 전화번호
				PersonInfo p =  new PersonInfo(name, add, ph);//personinfo라는 구조체에 생성
				persons.add(p); //배열에 추가
				line = br.readLine(); 
			} //새로운 줄 읽고// while back
			br.close();  //끝나면 버퍼 그만 받고
			fr.close(); //파일 그만 받고
		} catch(IOException ioEx){//예외 처리 입출력예외 
			System.out.println(ioEx);//결과 출력출력
		}
	}
	public void savePersons (){//사람 저장
		try {  
			PersonInfo p;//자료형 personinfo
			String line;//줄
			FileWriter fw = new FileWriter("persons1.txt");//출력할 파일
			PrintWriter pw = new PrintWriter(fw);  //콘솔에서 출력받는다 받는다?
			for(int i=0; i<persons.size(); i++)  { 
				p = (PersonInfo)persons.get(i);//리스트에서 요소 받아서
				line = p.name +", "+ p.address +", "+ p.phoneNum;//출력받을거 줄로 받아서 연결
				// writes line to file (persons.txt)  
				pw.println(line); //줄바꿈
			}  
			pw.flush(); 
			pw.close();//끝내기
			fw.close();  //끝내기
		} catch(IOException ioEx){//예외처리
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
		for(int i=0; i<persons.size();i++){//0 부터 person의 크기 까지
			PersonInfo p = (PersonInfo)persons.get(i);//인덱스꺼 p에 넣어서
			if(n.equals(p.name)){//p랑 입력된 n이랑 같은면 출력
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