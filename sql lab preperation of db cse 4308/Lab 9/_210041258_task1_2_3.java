import java.sql.Connection; // Import the necessary Java SQL library to work with the database.
import java.sql.DriverManager; // Import the JDBC driver manager to establish a database connection.
import java.sql.PreparedStatement; // Import PreparedStatement for using prepared statements.
import java.sql.ResultSet; // Import ResultSet to handle database query results.
import java.sql.ResultSetMetaData; // Import SQLException for handling database-related exceptions.
import java.sql.SQLException; // Import ResultSetMetaData for retrieving metadata about query results.
import java.text.SimpleDateFormat; // Import SimpleDateFormat to parse date strings.
import java.util.Date; // Import Date to work with date values.

/* my host & port  http://127.0.0.1:8080  */
/* the code for task 1 & 2 & 3  */
public class _210041258_task1_2_3 {
    public static void main(String[] args) {
        // Database connection parameters jdbc:mysql://localhost:4950/
        String jdbcUrl = "jdbc:mysql://127.0.0.1:8080/"; // Set the JDBC URL to connect to your specific database.
        String username = "dbms"; // Set the database username.
        String password = "dbms"; // Set the database password.

        try {
            // Establish a database connection
            Connection connection = DriverManager.getConnection(jdbcUrl, username, password); // Create a database
                                                                                              // connection.

            // Task 3: Retrieve and print metadata information for ACCOUNT and TRANSACTIONS
            // tables
            printTableMetadata(connection, "ACCOUNT"); // Call the function to print metadata for the ACCOUNT table.
            printTableMetadata(connection, "TRANSACTIONS"); // Call the function to print metadata for the TRANSACTIONS
                                                            // table.

            // Task 1: Fetch data from the TRANSACTIONS table and categorize accounts
            String selectQuery = "SELECT A_ID, AMOUNT, TYPE FROM TRANSACTIONS"; // Define the SQL query to
                                                                                // retrieve data.
            PreparedStatement selectStatement = connection.prepareStatement(selectQuery); // Create a prepared
                                                                                          // statement.
            ResultSet resultSet = selectStatement.executeQuery(); // Execute the query and get the result set.

            int cipCount = 0; // Initialize counters for CIP accounts.
            int vipCount = 0; // Initialize counters for VIP accounts.
            int ordinaryCount = 0; // Initialize counters for Ordinary accounts.
            int uncategorizedCount = 0; // Initialize counters for uncategorized accounts.

            while (resultSet.next()) {
                int accountId = resultSet.getInt("A_ID"); // Get the account ID from the result set.
                double amount = resultSet.getDouble("AMOUNT"); // Get the transaction amount from the result set.
                int transactionType = resultSet.getInt("TYPE"); // Get the transaction type from the result set.

                // Account categorization logic (adjust as needed)
                if (amount > 1000000) {
                    cipCount++; // Increment the count for CIP accounts.
                } else if (amount > 500000 && amount < 900000) {
                    vipCount++; // Increment the count for VIP accounts.
                } else if (amount < 100000) {
                    ordinaryCount++; // Increment the count for Ordinary accounts.
                } else {
                    uncategorizedCount++; // Increment the count for uncategorized accounts.
                }
            }

            resultSet.close(); // Close the result set.
            selectStatement.close(); // Close the prepared statement.

            // Print Task 1 results
            System.out.println("Task 1 Results:");
            System.out.println(
                    "Total Number of Accounts : " + (cipCount + vipCount + ordinaryCount + uncategorizedCount));
            System.out.println("CIP count : " + cipCount);
            System.out.println("VIP count : " + vipCount);
            System.out.println("Ordinary count : " + ordinaryCount);
            System.out.println("Uncategorized : " + uncategorizedCount);

            // Task 2: Insert two new records using a single prepared statement
            String insertQuery = "INSERT INTO TRANSACTIONS (T_ID,DTM,A_ID,AMOUNT,TYPE) VALUES (?, ?, ?, ?, ?)"; // Define
                                                                                                                // the
                                                                                                                // SQL
                                                                                                                // query
                                                                                                                // for
                                                                                                                // inserting
                                                                                                                // records.
            PreparedStatement insertStatement = connection.prepareStatement(insertQuery); // Create a prepared statement
                                                                                          // for insertion.
            // Set values for the first record
            insertStatement.setInt(1, 10001); // Set the value for the T_ID.
            Date date1 = new SimpleDateFormat("yyyy-MM-dd").parse("2022-02-12"); // Parse the date.
            insertStatement.setDate(2, new java.sql.Date(date1.getTime())); // Set the date value.
            insertStatement.setInt(3, 2); // Set the A_ID.
            insertStatement.setDouble(4, 5000); // Set the transaction amount.
            insertStatement.setInt(5, 1); // Set the transaction type (1 for debit).
            insertStatement.executeUpdate(); // Execute the insert statement.

            // Set values for the second record
            insertStatement.setInt(1, 10005); // Set the value for the T_ID.
            Date date2 = new SimpleDateFormat("yyyy-MM-dd").parse("2022-10-15"); // Parse the date.
            insertStatement.setDate(2, new java.sql.Date(date2.getTime())); // Set the date value.
            insertStatement.setInt(3, 4); // Set the A_ID.
            insertStatement.setDouble(4, 10000); // Set the transaction amount.
            insertStatement.setInt(5, 0); // Set the transaction type (0 for credit).
            insertStatement.executeUpdate(); // Execute the insert statement.

            insertStatement.close(); // Close the insert statement.

            // Close the database connection
            connection.close();

            System.out.println("Task 2 Results: Two records inserted successfully.");
        } catch (SQLException | java.text.ParseException e) { // Exception part
            e.printStackTrace();
        }
    }

    // Function to print table metadata information
    private static void printTableMetadata(Connection connection, String tableName) {
        try {
            String query = "SELECT * FROM " + tableName + " WHERE 1 = 0"; // Define a query to retrieve metadata.
            PreparedStatement statement = connection.prepareStatement(query); // Create a prepared statement for
                                                                              // metadata retrieval.
            ResultSet resultSet = statement.executeQuery(); // Execute the metadata query.
            ResultSetMetaData rsmd = resultSet.getMetaData(); // Get the metadata about the result set.

            System.out.println("Metadata information for table: " + tableName);
            int columnCount = rsmd.getColumnCount(); // Get the number of columns.
            System.out.println("Number of columns: " + columnCount);

            for (int i = 1; i <= columnCount; i++) {
                System.out.println("Column Name: " + rsmd.getColumnName(i)); // Print column names.
                System.out.println("Column Data Type: " + rsmd.getColumnTypeName(i)); // Print column data types.
            }
            System.out.println();
            resultSet.close(); // Close the result set.
            statement.close(); // Close the prepared statement.
        } catch (SQLException e) { // Exception part
            e.printStackTrace();
        }
    }
}
