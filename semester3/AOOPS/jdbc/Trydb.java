import java.sql.*;
public class Trydb {
    public static void main(String args[]){
        try{
            // Class.forName("com.mysql.jdbc.Driver");
            // i am using mysql  -  so i have to use this string -
            // you can see same order inside connector jar file.

            Connection con=DriverManager.getConnection("jdbc:mysql://localhost:3306/try_aoop","aoop","aoop");
			/* connection specifies what rdbms - i.e. jdbc:mysql
						system - localhost
						port - 3306
						db - yasodb
						username and password - root, root 	*/

            Statement stmt=con.createStatement();  // statement created to execute query
            ResultSet rs=stmt.executeQuery("select * from student");    // executeQuery() - to execute sql
            while(rs.next())    // iterate through resultset -
                System.out.println(rs.getString(1)+"  "+rs.getInt(2));
            //NOTE:  First field is int, second and third are string.
            con.close();
        }
        catch(Exception e){ System.out.println(e);}
    }
}