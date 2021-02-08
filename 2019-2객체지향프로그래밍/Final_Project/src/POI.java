import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;

import javax.swing.JOptionPane;

import org.apache.poi.xwpf.usermodel.ParagraphAlignment;
import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFParagraph;
import org.apache.poi.xwpf.usermodel.XWPFRun;

public class POI  {
	static int outcount =0;//want to use other class(PrintAward.class) to chehck problem in this class

	public POI(String a,String b,String c) throws Exception {	
		try {//check selected image, and load docx file.
			String wpath = null;
			if(Design.image == 1) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile1.docx";
			}
			else if(Design.image == 2) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile2.docx";
			}
			else if(Design.image == 3) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile3.docx";
			}
			else if(Design.image == 4) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile4.docx";
			}
			else if(Design.image == 5) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile5.docx";
			}
			else if(Design.image == 6) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile6.docx";
			}
			else if(Design.image == 7) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile7.docx";
			}
			else if(Design.image == 8) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile8.docx";
			}
			else if(Design.image == 9) {
				wpath= "C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\wfile\\wfile9.docx";
			}
			else {//if didn't select show and go to disign page
				JOptionPane.showMessageDialog(null,"The image is not selected.");
				new Design();
				return;
			}
			FileInputStream fis = new FileInputStream(new File(wpath));

			//extrart the content
			XWPFDocument document = new XWPFDocument(fis);
			FileOutputStream out = null;

			outcount++;// increase file number, set output address
			String out_add ="C:\\Users\\tjddl\\eclipse-workspace\\Final_Project\\goal\\Complete" + Integer.toString(outcount)+".docx";
			out = new FileOutputStream(new File(out_add));

			XWPFParagraph paragraph0 = document.createParagraph();
			XWPFRun run0 = paragraph0.createRun();

			paragraph0.setSpacingBefore(1000);//spacing before 
			paragraph0.setAlignment(ParagraphAlignment.CENTER);//align center
			run0.setFontFamily("Arial Black");//set fond
			run0.setFontSize(25);
			run0.setText("Certification");//text
			paragraph0.setSpacingAfter(1000);//spacing after



			//name, field, rank
			XWPFParagraph paragraph1 = document.createParagraph();
			XWPFRun run1 = paragraph1.createRun();

			//align right
			paragraph1.setAlignment(ParagraphAlignment.RIGHT);
			paragraph1.setIndentFromRight(10);

			//set font
			run1.setFontFamily("Arial Black");
			run1.setFontSize(15);
			//set name data
			run1.setText("Name : " + a);
			run1.addBreak();//줄바꿈
			//set field data
			run1.setText("Field :  " + b);
			run1.addBreak();//줄바꿈
			//set rank
			run1.setText("Rank : " + c);
			run1.addBreak();//줄바꿈
			//spacing after
			paragraph1.setSpacingAfter(2000);



			//main 
			XWPFParagraph paragraph2 = document.createParagraph();
			XWPFRun run2 = paragraph2.createRun();

			paragraph2.setAlignment(ParagraphAlignment.CENTER);
			run2.setFontFamily("Arial Black");
			run2.setFontSize(15);
			//spacing front,in all of this paragraph
			paragraph2.setIndentFromLeft(500);
			paragraph2.setIndentFromRight(500);
			run2.setText("This award is presented because of your excellent grades at the 32nd 2019 World Dance Competition hosted by Yun Bone.");
			paragraph2.setSpacingAfter(3000);



			//master name text
			XWPFParagraph paragraph3 = document.createParagraph();
			XWPFRun run3 = paragraph3.createRun();
			//align center
			paragraph3.setAlignment(ParagraphAlignment.CENTER);
			run3.setFontFamily("Arial Black");
			run3.setFontSize(20);//set font size
			run3.setText("World Dance Competition ChairMan");
			run3.addBreak();//line break
			run3.setText("Mr. Sim");

			System.out.println(a+b+c);

			document.write(out);
			out.close();	
			document.close();
			System.out.println("createcuces");//문서 생성성공 메세지
		}catch(IOException I) {
			JOptionPane.showMessageDialog(null, "There is a problem with the output ");
			I.printStackTrace();
		}catch(Exception e) {
			System.out.println(e);
			e.printStackTrace();
		}

	}

}