import java.awt.*;
import java.awt.event.*;
import java.applet.*;

public class AppletKeyboard extends Applet implements KeyListener
{
    String msg = "";
    int x = 100, y = 100;

    public void init()
    {
        addKeyListener(this);
        requestFocus();
    }

    public void keyPressed(KeyEvent k)
    {
        showStatus("Key Pressed");
    }
    
    public void keyReleased(KeyEvent k)
    {
        showStatus("Key Released");
    }
    
    public void keyTyped(KeyEvent k)
    {
        msg += k.getKeyChar() + " ";
        repaint();
    }

    public void paint(Graphics g)
    {
        g.drawString(msg, x, y);
    }
}