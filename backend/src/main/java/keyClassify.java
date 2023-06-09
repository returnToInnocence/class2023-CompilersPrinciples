import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import java.io.IOException;
import java.io.PrintWriter;
import java.sql.*;

@WebServlet("/keyClassify")
public class keyClassify  extends HttpServlet {
    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("begin get");
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        // JDBC连接的URL, 不同数据库有不同的格式:
        String JDBC_URL = "jdbc:mysql://xxxx:3306/bianyi?serverTimezone=UTC&useSSL=false&allowPublicKeyRetrieval=true";
        String JDBC_USER = "xxxx";
        String JDBC_PASSWORD = "xxx";
        String tmpResp = "";
        try (Connection conn = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD)) {
            try (Statement stmt = conn.createStatement()) {
                try (ResultSet rs = stmt.executeQuery("SELECT * FROM another where class=0")) {
                    while (rs.next()) {
                        String first = rs.getString(1);
                        tmpResp = tmpResp + first + "|";
                    }
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }

        // 1. 通过response获取字符输出流
        PrintWriter pw = response.getWriter();
        // 2. 通过字符输出输出文本
        pw.write(tmpResp);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        System.out.println("begin post");
        response.setContentType("text/html;charset=utf-8");
        request.setCharacterEncoding("utf-8");
        // JDBC连接的URL, 不同数据库有不同的格式:
        String JDBC_URL = "jdbc:mysql://xxxx:3306/bianyi?serverTimezone=UTC&useSSL=false&allowPublicKeyRetrieval=true";
        String JDBC_USER = "xxxx";
        String JDBC_PASSWORD = "xxx";
        String keyWordName = request.getParameter("keyWordName");
        if (keyWordName.equals(" ")){
            keyWordName = "+";
        }
        System.out.println("用户要删除的是" + keyWordName);
        try (Connection conn = DriverManager.getConnection(JDBC_URL, JDBC_USER, JDBC_PASSWORD)) {
            try (PreparedStatement ps = conn.prepareStatement("DELETE FROM another WHERE keyWordName=?")) {
                ps.setObject(1, keyWordName); // 注意：索引从1开始
                int n = ps.executeUpdate(); // 删除的行数
            }
        } catch (SQLException e) {
            e.printStackTrace();
        }
    }
}

