import java.awt.*;
import javax.swing.*;

public class Flow {
    JFrame f;

    Flow() {
        f = new JFrame();
        JButton[] buttons = new JButton[9];

        for (int i = 0; i < 9; i++) {
            buttons[i] = new JButton("Button " + i);
            f.add(buttons[i]);
        }

        f.setLayout(new FlowLayout(FlowLayout.CENTER));

        f.setSize(500, 500);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        new Flow();
    }
}