import javax.swing.*;
import java.io.*;


public class PersonInfo implements Serializable{
	String name;
	String address;
	transient String  phoneNum;
	
	public PersonInfo(String n, String a, String p){
		name =n;
		address = a;
		phoneNum = p;
	}
	public void print(){
		JOptionPane.showMessageDialog(null,"name: "+name+"address:"+address+"phone no :" + phoneNum);
	}
}//end PersonInfo