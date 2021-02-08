package ssss;
import java.io.*;
import java.util.ArrayList;

public class sssss{
	ArrayList<PersonInfo>persons;//personinfo class로 다운캐스팅해서 persons라는 리스트 만듦

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
			FileWriter fw = new FileWriter("persons.txt");//출력할 파일
			PrintWriter pw = new PrintWriter(fw);  //콘솔에서 출력받는다 받는다?
			for(int i=0; i<persons.size(); i++)  { 
				p = (PersonInfo)persons.get(i);//리스트에서 요소 받아서
				line = p.name +","+ p.address +","+ p.phoneNum;//출력받을거 줄로 받아서 연결
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
}
