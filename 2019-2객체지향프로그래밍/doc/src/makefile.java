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
			//extrart the content�� ���
			XWPFDocument document = new XWPFDocument(fis);
			
			//������ ��ġ
			FileOutputStream out = new FileOutputStream(new File("C:\\Users\\tjddl\\Downloads\\c.docx"));

			XWPFParagraph paragraph0 = document.createParagraph();
			XWPFRun run0 = paragraph0.createRun();

			paragraph0.setSpacingBefore(1000);//�տ� ���� ����
			paragraph0.setAlignment(ParagraphAlignment.CENTER);//��� ����
			run0.setFontFamily("Arial Black");//����ü
			run0.setFontSize(25);
			run0.setText("Certification");//text
			paragraph0.setSpacingAfter(1000);//�ڿ� ���� ����



			//�̸�,�о�,���
			XWPFParagraph paragraph1 = document.createParagraph();
			XWPFRun run1 = paragraph1.createRun();

			//������ ����
			paragraph1.setAlignment(ParagraphAlignment.RIGHT);
			paragraph1.setIndentFromRight(10);

			//��Ʈ ����
			run1.setFontFamily("Arial Black");
			run1.setFontSize(15);
			//�̸�
			run1.setText("Name : " + a[0]);
			run1.addBreak();//�ٹٲ�
			//�о�
			run1.setText("Field :  " + a[1]);
			run1.addBreak();//�ٹٲ�
			//���
			run1.setText("Rank : " + a[2]);
			run1.addBreak();//�ٹٲ�
			//�ڿ� ����
			paragraph1.setSpacingAfter(2000);



			//�����
			XWPFParagraph paragraph2 = document.createParagraph();
			XWPFRun run2 = paragraph2.createRun();

			paragraph2.setAlignment(ParagraphAlignment.CENTER);
			run2.setFontFamily("Arial Black");
			run2.setFontSize(15);
			//�տ� 1000�ٱ� �ٿ��� ���� ��
			paragraph2.setIndentFromLeft(500);
			paragraph2.setIndentFromRight(500);
			run2.setText("This award is presented because of your excellent grades at the 32nd 2019 World Dance Competition hosted by Yun Bone.");
			paragraph2.setSpacingAfter(3000);



			//�����ü
			XWPFParagraph paragraph3 = document.createParagraph();
			XWPFRun run3 = paragraph3.createRun();
			//��� ����

			paragraph3.setAlignment(ParagraphAlignment.CENTER);
			run3.setFontFamily("Arial Black");
			run3.setFontSize(20);
			run3.setText("World Dance Competition ChairMan");
			run3.addBreak();
			run3.setText("Mr. Sim");



			document.write(out);
			out.close();	
			document.close();
			System.out.println("createcuces");//���� �������� �޼���
		}catch(Exception e) {
			System.out.println(e);

			e.printStackTrace();
		}

	}

}