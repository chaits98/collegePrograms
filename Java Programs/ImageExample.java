import java.awt.*;  
import javax.swing.*;  
  
public class ImageExample extends JFrame{  
      
    ImageExample() 
    {  
        ImageIcon ic = new ImageIcon("D:\\Chaitanya Anand\\img.jpeg");
        JLabel l = new JLabel(ic);
        l.setBounds(250, 560, 200, 200);
        add(l);
        pack();
        setVisible(true);
    }  

    public static void main(String[] args) 
    {
        ImageExample m = new ImageExample();  
    }  
  
}  