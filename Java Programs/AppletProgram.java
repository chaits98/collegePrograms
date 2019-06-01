import java.applet.*;
import java.awt.*;

public class AppletProgram extends Applet
{
    String msg;
    
    @Override
    public void init()
    {
        msg = "\n\t***Init begins***";
        setBackground(Color.BLUE);
        setForeground(Color.WHITE);
    }
    
    @Override
    public void start()
    {
        msg += "\n\tStart begins";
    }
    
    @Override
    public void stop()
    {
        msg += "\n\tStop begins";
    }
    
    @Override
    public void destroy()
    {
        msg += "\n\tDestroy begins";
    }
    
    @Override
    public void paint(Graphics g)
    {
        msg += "\n\tPaint Begins";
        g.drawString(msg, 10, 30);
        showStatus("Status Paint");
    }
}