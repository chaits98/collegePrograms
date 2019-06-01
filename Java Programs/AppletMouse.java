import java.applet.*;
import java.awt.*;
import static java.awt.MouseInfo.getPointerInfo;

public class AppletMouse extends Applet
{    
    @Override
    public void init()
    {
        setBackground(Color.WHITE);
        setForeground(Color.BLACK);
    }
    
    @Override
    public void paint(Graphics g)
    {
        Point p = getPointerInfo().getLocation();
        g.drawString("?jhcJH", (int) p.getX(), (int) p.getY());
        showStatus("Status Paint");
    }
}