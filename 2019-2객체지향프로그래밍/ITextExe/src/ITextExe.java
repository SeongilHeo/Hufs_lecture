import java.io.File;
import java.io.BufferedWriter;
import java.io.FileOutputStream;
import java.io.FileWriter;
 
import javax.swing.JFileChooser;
 
public class ITextExe {
             
    public ITextExe() {
        JFileChooser jfc = new JFileChooser();
        int returnVal = jfc.showSaveDialog(null);
        if(returnVal == 0) {
            File file = jfc.getSelectedFile();
            System.out.println("����� ������ ������ " + file.getName() + " �Դϴ�.");
             
            String str = "�ȳ��ϼ���. �ڹ��Դϴ�.";
            try {
                BufferedWriter bw = new BufferedWriter(new FileWriter(file));
                bw.write(str);
                bw.flush();
                bw.close();
                 
            }catch(Exception e) {e.printStackTrace();}
             
        }
         
    }
    public static void main(String[] args) {
        new ITextExe();
    }
}