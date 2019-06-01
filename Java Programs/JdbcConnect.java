import java.sql.*;

class JdbcConnect{
    public static void main(String args[]){
        try
        {
            Class.forName("oracle.jdbc.OracleDriver");
            Connection con = DriverManager.getConnection("jdbc:oracle:thin:@localhost:1521:orc1","war_mach","aj9ccsfsc");
            Statement stmt = con.createStatement();
            ResultSet rs = stmt.executeQuery("select * from employees");
            while(rs.next())
            {
                System.out.format("|%14s|%5d|%5d|\n", rs.getString(1), rs.getInt(2), rs.getInt(3));
            }
            con.close();
        }
        catch(Exception e)
        {
            System.out.println(e);
        }
        
    }
}
