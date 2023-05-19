import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.PreparedStatement;
import java.sql.SQLException;

@WebServlet("/keyWordAdd")
public class keyWordAdd extends HttpServlet {
    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        String JDBC_URL = "jdbc:mysql://124.222.87.124:3306/bianyi?serverTimezone=UTC&useSSL=false&allowPublicKeyRetrieval=true";
        String JDBC_USER = "BianYi";
        String JDBC_PASSWORD = "TD5KHXf37sKJcW8L";
        try (Connection conn = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD)) {
            try (PreparedStatement ps = conn.prepareStatement(
                    "INSERT INTO keyWord (keyWordName) VALUES (?)")) {
                ps.setObject(1, request.getParameter("keyWordName")); // 注意：索引从1开始
                int n = ps.executeUpdate(); // 1
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}
