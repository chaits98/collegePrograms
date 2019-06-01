import java.awt.*;
import javax.swing.*;

public class Grid {
    JFrame f;

    Grid() {
        f = new JFrame();
        JButton[] buttons = new JButton[9];

        for (int i = 0; i < 9; i++) {
            buttons[i] = new JButton("Button " + i);
            f.add(buttons[i]);
        }

        f.setLayout(new GridLayout(3, 3));

        f.setSize(500, 500);
        f.setVisible(true);
    }

    public static void main(String[] args) {
        new Grid();
    }
}