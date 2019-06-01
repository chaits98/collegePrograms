import java.sql.*;

class JdbcAccessConnect
{
    public static void main(String ar[])
    {
        try
        {
            String database = "D:\\NetBeansProjects\\Database1.accdb";
            String url = "jdbc:ucanaccess://" + database;
            Class.forName("net.ucanaccess.jdbc.UcanaccessDriver");
            Connection c = DriverManager.getConnection(url);
            Statement st = c.createStatement();
            ResultSet rs = st.executeQuery("select * from employees");
            while(rs.next())
            {
                System.out.format("|%5d|%14s|%5d|%5d|\n", rs.getInt(1), rs.getString(4), rs.getInt(2), rs.getInt(3));
            }
        }
        catch(Exception e)
        {
            System.out.println(e);
        }  
    }
}  
