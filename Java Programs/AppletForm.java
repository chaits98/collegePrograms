import java.awt.*;
import java.awt.event.*;
import java.applet.*;
import javax.swing.*;

public class AppletForm extends Applet implements ActionListener
{
    String msg;
    Panel panel1, panel2, panel3, panel4, panel5, panel6, panel7, panel8, panelMain;
    Label name, form;
    CheckboxGroup cbg;
    Choice choice;
    Checkbox cb[], cb2[];
    TextArea address;
    TextField fName, mName, lName;
    Button submit, menu1;
    GridBagConstraints gbc;
    Frame frame;
    Scrollbar sbh, sbv;
    Image im;

    public void init()
    {
        im = getImage(getCodeBase(), "D:\\Chaitanya Anand\\img.jpeg");
        choice = new Choice();
        cb = new Checkbox[3];
        cb2 = new Checkbox[3];
        gbc = new GridBagConstraints();
        panel1 = new Panel();
        panel1.setBackground(Color.green);
        panel2 = new Panel();
        panel2.setBackground(Color.blue);
        panel3 = new Panel();
        panel3.setBackground(Color.yellow);
        panel4 = new Panel();
        panel4.setBackground(Color.red);
        panel5 = new Panel();
        panel5.setBackground(Color.pink);
        panel6 = new Panel();
        panel6.setBackground(Color.orange);
        panel7 = new Panel();
        panel7.setBackground(Color.magenta);
        // panel8 = new Panel();
        panelMain = new Panel();
        panelMain.setBackground(Color.lightGray);
        panelMain.setLayout(new GridBagLayout());
        JScrollPane scrollableArea = new JScrollPane(panelMain);  
        scrollableArea.setHorizontalScrollBarPolicy(JScrollPane.HORIZONTAL_SCROLLBAR_ALWAYS);  
        scrollableArea.setVerticalScrollBarPolicy(JScrollPane.VERTICAL_SCROLLBAR_ALWAYS);
        add(scrollableArea);

        // panel8.add(im);
        // gbc.fill = GridBagConstraints.VERTICAL;
        // gbc.gridx = 0;
        // gbc.gridy = 0;
        // panelMain.add(panel8, gbc);

        form = new Label("Form");
        form.setFont(new Font("Arial", Font.PLAIN, 30));
        panel5.add(form);
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 1;
        panelMain.add(panel5, gbc);

        name = new Label("Name: ");
        address =  new TextArea("");
        fName = new TextField("John", 20);
        mName = new TextField("Wait for it", 20);
        lName = new TextField("Doe", 20);

        submit = new Button("Submit");
        submit.addActionListener(this);

        panel1.add(name);
        panel1.add(fName);
        panel1.add(mName);
        panel1.add(lName);
        gbc.anchor = GridBagConstraints.WEST;
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 2;
        panelMain.add(panel1, gbc);

        cbg = new CheckboxGroup();
        cb[0] = new Checkbox("Male", cbg, false);
        cb[1] = new Checkbox("Female", cbg, false);
        cb[2] = new Checkbox("Other", cbg, false);
        panel2.add(new Label("Gender: "));
        panel2.add(cb[0]);
        panel2.add(cb[1]);
        panel2.add(cb[2]);
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 3;
        panelMain.add(panel2, gbc);

        cb2[0] = new Checkbox("Parantha");
        cb2[1] = new Checkbox("Chole Bhature");
        cb2[2] = new Checkbox("Poha");
        panel6.add(new Label("Dishes: "));
        panel6.add(cb2[0]);
        panel6.add(cb2[1]);
        panel6.add(cb2[2]);
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 4;
        panelMain.add(panel6, gbc);

        choice.add("B. Tech");
        choice.add("BBA");
        choice.add("BCA");
        choice.add("LLB");
        choice.add("B. Arch");
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 5;
        panel4.add(new Label("Degree: "));
        panel4.add(choice);
        panelMain.add(panel4, gbc);
        
        panel3.setLayout(new GridBagLayout());
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 0;
        gbc.weightx = 1.0;
        panel3.add(new Label("Address: "), gbc);
        gbc.gridx = 1;
        gbc.gridy = 0;
        gbc.weightx = 1.0;
        panel3.add(address, gbc);
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 1;
        panel3.add(submit, gbc);
        gbc.fill = GridBagConstraints.VERTICAL;
        gbc.gridx = 0;
        gbc.gridy = 6;
        panelMain.add(panel3, gbc);
        add(panelMain);
        repaint();
    }

    public void paint(Graphics g)
    {
        g.drawString("wdshcb", 0, 1000);
        g.drawImage(im, 0, 0, (int)getBounds().getWidth(), (int)getBounds().getHeight(), this);
    }

    @Override
    public void actionPerformed(ActionEvent e)
    {
        msg = null;
        if(e.getSource() == submit)
        {
            if(fName.getText() != "John")
            {
                msg = "Hello " + fName.getText() + " ";
            }
            if(mName.getText() != "Wait for it")
            {
                msg += " " + mName.getText();
            }
            if(lName.getText() != "Doe")
            {
                msg += " " + lName.getText();
            }

            for(Checkbox c : cb)
            {
                if(c.getState())
                {
                    msg += ".\nGender: " + c.getLabel() + "\n";
                    break;
                }
            }

            msg += "You like ";

            for(Checkbox c : cb2)
            {
                if(c.getState())
                {
                    msg += c.getLabel();
                    break;
                }
            }

            msg += ".\nYou are currently pursuing " + choice.getSelectedItem() + ".";

            msg += "\nYou stay at " + address.getText();
            
            frame = new Frame("Output");
            frame.add(new TextArea(msg));
            frame.setSize(300, 300);
            frame.setVisible(true);
        }
    }
}