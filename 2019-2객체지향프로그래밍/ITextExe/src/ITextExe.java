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
            System.out.println("당신이 저장할 파일은 " + file.getName() + " 입니다.");
             
            String str = "안녕하세요. 자바입니다.";
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