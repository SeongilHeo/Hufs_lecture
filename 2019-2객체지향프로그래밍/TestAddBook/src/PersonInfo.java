import javax.swing.*;
import java.util.Arrays;

class PersonInfo{
	String name;
	String address;
	String phoneNum;
	char[] name2;
	
	public PersonInfo(String n, String a, String p){
		name =n;
		address = a;
		phoneNum = p;
		name2 = n.toCharArray();
		Arrays.sort(name2);
	}
	public void print(){
		JOptionPane.showMessageDialog(null,"name: "+name+"address:"+address+"phone no :" + phoneNum);
	}
}//end PersonInfo