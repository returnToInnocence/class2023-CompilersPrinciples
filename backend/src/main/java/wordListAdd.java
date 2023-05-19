import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@WebServlet("/wordListAdd")
public class wordListAdd extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        String JDBC_URL = "jdbc:mysql://124.222.87.124:3306/bianyi?serverTimezone=UTC&useSSL=false&allowPublicKeyRetrieval=true";
        String JDBC_USER = "BianYi";
        String JDBC_PASSWORD = "TD5KHXf37sKJcW8L";
        String str = request.getParameter("keyWordName");
        if (str.equals(" ")){
            str = "+";
        }
        System.out.println("用户添加："+str);
        try (Connection conn = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD)) {
            try (PreparedStatement ps = conn.prepareStatement(
                    "INSERT INTO another (keyWordName,class) VALUES (?,0)")) {
                ps.setObject(1, str); // 注意：索引从1开始
                int n = ps.executeUpdate(); // 1
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
        // 1. 通过response获取字符输出流
        PrintWriter pw = response.getWriter();
        // 2. 通过字符输出输出文本
        pw.write("good!");
    }
}
