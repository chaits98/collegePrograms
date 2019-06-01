import java.awt.*;
import javax.swing.*;
import java.awt.event.*;

public class MenuBarExample extends JFrame
{
    MenuBar myMenuBar;
    Menu dishes;
    MenuItem item[];
    JFrame frame;

    MenuBarExample()
    {
        myMenuBar = new MenuBar();
        setMenuBar(myMenuBar);
        dishes = new Menu("Tasty Dishes");
        item = new MenuItem[4];
        dishes.add(item[0] = new MenuItem("Dosa"));
        dishes.add(item[1] = new MenuItem("Idli"));
        dishes.add(item[2] = new MenuItem("Vada"));
        dishes.add(item[3] = new MenuItem("Uttapam"));

        item[0].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame = new JFrame("Dosa");
                frame.add(new TextArea("Dosa khalo frands"));
                frame.setSize(300, 100);
                frame.setDefaultCloseOperation(1);
                frame.setVisible(true);
            }
        });
        item[1].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame = new JFrame("Idli");
                frame.add(new TextArea("Idli khalo frands"));
                frame.setSize(300, 100);
                frame.setVisible(true);
                frame.setDefaultCloseOperation(1);
            }
        });
        item[2].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame = new JFrame("Vada");
                frame.add(new TextArea("Vada khalo frands"));
                frame.setSize(300, 100);
                frame.setVisible(true);
                frame.setDefaultCloseOperation(1);
            }
        });
        item[3].addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent e) {
                frame = new JFrame("Uttapam");
                frame.add(new TextArea("Uttapam khalo frands"));
                frame.setSize(300, 100);
                frame.setVisible(true);
                frame.setDefaultCloseOperation(1);
            }
        });
        myMenuBar.add(dishes);
        setSize(300, 300);
        setVisible(true);
        setDefaultCloseOperation(1);
    }

    public static void main(String[] args)
    {
        new MenuBarExample();
    }
}
