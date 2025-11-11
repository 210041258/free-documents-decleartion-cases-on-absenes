
 
CREATE TABLE Addresses (
    Address_ID NUMBER PRIMARY KEY,
    Division VARCHAR2(50),
    District VARCHAR2(50)
);
 
CREATE TABLE Subscriptions (
    Subscription_ID NUMBER PRIMARY KEY,
    Subscriber_Type VARCHAR2(10),
    Subscriber_Level VARCHAR2(10),
    Lifetime_Usage NUMBER
);


CREATE TABLE Customers (
    Customer_ID NUMBER PRIMARY KEY,
    Customer_Name VARCHAR2(100),
    Date_of_Birth DATE,
    Address_ID NUMBER,
    Subscription_ID NUMBER,
    FOREIGN KEY (Address_ID) REFERENCES Addresses(Address_ID),
    FOREIGN KEY (Subscription_ID) REFERENCES Subscriptions(Subscription_ID)
);

 
INSERT INTO Addresses 
VALUES (1, 'Dhaka', 'Dhaka');
 
INSERT INTO Addresses 
VALUES (2, 'Khulna', 'Jessore');
 
INSERT INTO Addresses 
VALUES (3, 'Chittagong', 'Comilla');
 
INSERT INTO Addresses 
VALUES (4, 'Dhaka', 'Gazipur');
 
INSERT INTO Addresses 
VALUES (5, 'Sylhet', 'Sylhet');
 
INSERT INTO Subscriptions 
VALUES (1, 'Prepaid', 'Silver', 5000);
 
INSERT INTO Subscriptions 
VALUES (2, 'Postpaid', 'Gold', 20000);
 
INSERT INTO Subscriptions 
VALUES (3, 'Prepaid', 'Bronze', 3000);
 
INSERT INTO Subscriptions 
VALUES (4, 'Postpaid', 'Platinum', 40000);
 
INSERT INTO Subscriptions 
VALUES (5, 'Prepaid', 'Silver', 7000);
 
INSERT INTO Customers 
VALUES (1, '  john Doe', TO_DATE('1990-05-10', 'YYYY-MM-DD'), 1, 1);
 
INSERT INTO Customers 
VALUES (2, 'Jane smith  ', TO_DATE('1985-12-25', 'YYYY-MM-DD'), 2, 2);
 
INSERT INTO Customers 
VALUES (3, 'ahmed khan', TO_DATE('1975-07-15', 'YYYY-MM-DD'), 3, 3);
 
INSERT INTO Customers 
VALUES (4, 'lisa Rahman',TO_DATE('1992-03-09', 'YYYY-MM-DD'), 4, 4);
 
INSERT INTO Customers 
VALUES (5, 'Samiul Islam',TO_DATE('1988-11-19', 'YYYY-MM-DD'), 5, 5);










SELECT Customer_Name, Customer_ID, Lifetime_Usage
FROM (
    SELECT *
    FROM Customers
    NATURAL JOIN Subscriptions
) AS SubQueryAlias
ORDER BY Lifetime_Usage DESC
FETCH FIRST 5 ROWS ONLY;






SELECT Customer_Name,Customer_ID,Lifetime_Usage
FROM (
    SELECT *
    FROM Customers
    NATURAL JOIN Subscriptions
) AS SubQueryAlias
ORDER BY Lifetime_Usage DESC
FETCH FIRST 5 ROWS ONLY;




SELECT Customer_Name,Date_of_Birth, District, Division
FROM (
    SELECT *
    FROM Customers
    NATURAL JOIN Addresses
) AS SubQueryAlias
WHERE Lifetime_Usage > (
    SELECT AVG(Lifetime_Usage)
    FROM Customers
    WHERE Subscriber_Type = 'Prepaid' AND Subscriber_Level = 'Silver'
);





SELECT COUNT(*)
FROM (
    SELECT *
    FROM Customers
    NATURAL JOIN Addresses
) AS SubQueryAlias
WHERE District = 'Dhaka'
AND Lifetime_Usage > (
    SELECT AVG(Lifetime_Usage)
    FROM (
    SELECT *
    FROM Customers
    NATURAL JOIN Subscriptions
) AS SubQuery
    WHERE Subscriber_Type = 'Prepaid' AND Subscriber_Level = 'Silver'
);





SELECT CONCAT('Mr./Ms.', Customer_Name) AS FULL_NAME
FROM Customers;




SELECT INITCAP(Customer_Name) AS PROPER_CASE_NAME
FROM Customers;





SELECT Customer_Name, INSTR(Customer_Name, 'an') AS POSITION
FROM Customers
WHERE INSTR(Customer_Name, 'an') > 0;





SELECT LOWER(Customer_Name) AS LOWERCASE_NAME
FROM CUSTOMER;




SELECT UPPER(Customer_Name) AS UPPERCASE_NAME
FROM Customers;




SELECT NAME, LENGTH(Customer_Name) AS NAME_LENGTH
FROM Customers;





SELECT LPAD(Customer_Name, 15, '*') AS PADDED_NAME
FROM Customers;





SELECT LTRIM(Customer_Name) AS TRIMMED_NAME
FROM Customers;





SELECT SUBSTR(Customer_Name, 1, 5) AS FIRST_FIVE_CHARACTERS
FROM Customers;





SELECT Division, COUNT(*) AS CUSTOMER_COUNT
FROM (
    SELECT *
    FROM Customers
    NATURAL JOIN Addresses
) AS SubQueryAlias
GROUP BY Division;



