-- Drop existing tables if they exist
DROP TABLE IF EXISTS OrderProducts;
DROP TABLE IF EXISTS SalesRecords;
DROP TABLE IF EXISTS Products;
DROP TABLE IF EXISTS Salesagent;
DROP TABLE IF EXISTS Customers;

-- Create database and use it
CREATE DATABASE c;
USE c;

-- Create Customers table
CREATE TABLE Customers (
    CustomerID INT AUTO_INCREMENT PRIMARY KEY,
    CustomerName VARCHAR(255) UNIQUE
);

-- Create Salesagent table
CREATE TABLE Salesagent (
    SalesID VARCHAR(10) PRIMARY KEY,
    SalespersonName VARCHAR(255),
    Location VARCHAR(255)
);

-- Create SalesRecords table
CREATE TABLE SalesRecords (
    OrderID VARCHAR(10) PRIMARY KEY,
    CustomerID INT,
    OrderDate DATE,
    SalesID VARCHAR(10),
    FOREIGN KEY (CustomerID) REFERENCES Customers(CustomerID),
    FOREIGN KEY (SalesID) REFERENCES Salesagent(SalesID)
);

-- Create Products table
CREATE TABLE Products (
    ProductID VARCHAR(10) PRIMARY KEY,
    ProductName VARCHAR(255)
);

-- Create OrderProducts table
CREATE TABLE OrderProducts (
    OrderID VARCHAR(10),
    ProductID VARCHAR(10),
    Quantity INT DEFAULT 1,
    PRIMARY KEY (OrderID, ProductID),
    FOREIGN KEY (OrderID) REFERENCES SalesRecords(OrderID),
    FOREIGN KEY (ProductID) REFERENCES Products(ProductID)
);