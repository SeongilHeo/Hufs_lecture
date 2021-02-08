import java.io.File;
import java.io.FileInputStream;
import java.io.FileOutputStream;

import org.apache.poi.xwpf.usermodel.ParagraphAlignment;
import org.apache.poi.xwpf.usermodel.XWPFDocument;
import org.apache.poi.xwpf.usermodel.XWPFParagraph;
import org.apache.poi.xwpf.usermodel.XWPFRun;


public class makefile{
	public static void main(String[] args) {	
		String [] a = {"df","dfd","ddf"};
		try {
			String ad ="C:\\Users\\tjddl\\Downloads\\b.docx";
			FileInputStream fis = new FileInputStream(ad);
			//extrart the content에 사용
			XWPFDocument document = new XWPFDocument(fis);
			
			//저장할 위치
			FileOutputStream out = new FileOutputStream(new File("C:\\Users\\tjddl\\Downloads\\c.docx"));

			XWPFParagraph paragraph0 = document.createParagraph();
			XWPFRun run0 = paragraph0.createRun();

			paragraph0.setSpacingBefore(1000);//앞에 공간 비우기
			paragraph0.setAlignment(ParagraphAlignment.CENTER);//가운데 정렬
			run0.setFontFamily("Arial Black");//글자체
			run0.setFontSize(25);
			run0.setText("Certification");//text
			paragraph0.setSpacingAfter(1000);//뒤에 공간 비우기



			//이름,분야,등수
			XWPFParagraph paragraph1 = document.createParagraph();
			XWPFRun run1 = paragraph1.createRun();

			//오른쪽 정렬
			paragraph1.setAlignment(ParagraphAlignment.RIGHT);
			paragraph1.setIndentFromRight(10);

			//폰트 변경
			run1.setFontFamily("Arial Black");
			run1.setFontSize(15);
			//이름
			run1.setText("Name : " + a[0]);
			run1.addBreak();//줄바꿈
			//분야
			run1.setText("Field :  " + a[1]);
			run1.addBreak();//줄바꿈
			//등수
			run1.setText("Rank : " + a[2]);
			run1.addBreak();//줄바꿈
			//뒤에 공간
			paragraph1.setSpacingAfter(2000);



			//설명글
			XWPFParagraph paragraph2 = document.createParagraph();
			XWPFRun run2 = paragraph2.createRun();

			paragraph2.setAlignment(ParagraphAlignment.CENTER);
			run2.setFontFamily("Arial Black");
			run2.setFontSize(15);
			//앞에 1000뛰기 다움줄 부터 쭉
			paragraph2.setIndentFromLeft(500);
			paragraph2.setIndentFromRight(500);
			run2.setText("This award is presented because of your excellent grades at the 32nd 2019 World Dance Competition hosted by Yun Bone.");
			paragraph2.setSpacingAfter(3000);



			//수상단체
			XWPFParagraph paragraph3 = document.createParagraph();
			XWPFRun run3 = paragraph3.createRun();
			//가운데 정렬

			paragraph3.setAlignment(ParagraphAlignment.CENTER);
			run3.setFontFamily("Arial Black");
			run3.setFontSize(20);
			run3.setText("World Dance Competition ChairMan");
			run3.addBreak();
			run3.setText("Mr. Sim");



			document.write(out);
			out.close();	
			document.close();
			System.out.println("createcuces");//문서 생성성공 메세지
		}catch(Exception e) {
			System.out.println(e);

			e.printStackTrace();
		}

	}

}