-- Create Branch table
CREATE TABLE Branch (
    BranchID INT PRIMARY KEY,
    Street VARCHAR(255) NOT NULL,
    City VARCHAR(255) NOT NULL,
    Postcode VARCHAR(10) NOT NULL
);

-- Create Employee table
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    Gender CHAR(1) NOT NULL,
    DateOfBirth DATE NOT NULL,
    Position VARCHAR(50) NOT NULL,
    Salary DECIMAL(10, 2) NOT NULL,
    BranchID INT NOT NULL,
    FOREIGN KEY (BranchID) REFERENCES Branch(BranchID)
);

-- Create Client table
CREATE TABLE Client (
    ClientID INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    TelephoneNumber VARCHAR(15) NOT NULL,
    Email VARCHAR(255) NOT NULL,
    AccommodationType VARCHAR(50) NOT NULL,
    MaxRent DECIMAL(10, 2) NOT NULL,
    ContactStaffID INT NOT NULL,
    FOREIGN KEY (ContactStaffID) REFERENCES Employee(EmployeeID)
);

-- Create Owner table
CREATE TABLE Owner (
    OwnerID INT PRIMARY KEY,
    FirstName VARCHAR(50) NOT NULL,
    LastName VARCHAR(50) NOT NULL,
    TelephoneNumber VARCHAR(15) NOT NULL,
    Email VARCHAR(255) NOT NULL,
    Password VARCHAR(255) NOT NULL
);

-- Create Property table
CREATE TABLE Property (
    PropertyID INT PRIMARY KEY,
    Street VARCHAR(255) NOT NULL,
    City VARCHAR(255) NOT NULL,
    Postcode VARCHAR(10) NOT NULL,
    Type VARCHAR(50) NOT NULL,
    NumRooms INT NOT NULL,
    Rent DECIMAL(10, 2) NOT NULL,
    OwnerID INT NOT NULL,
    ContactStaffID INT NOT NULL,
    BranchID INT NOT NULL,
    FOREIGN KEY (OwnerID) REFERENCES Owner(OwnerID),
    FOREIGN KEY (ContactStaffID) REFERENCES Employee(EmployeeID),
    FOREIGN KEY (BranchID) REFERENCES Branch(BranchID)
);

-- Create Visit table
CREATE TABLE Visit (
    VisitID INT PRIMARY KEY,
    VisitDate DATE NOT NULL,
    ClientID INT NOT NULL,
    PropertyID INT NOT NULL,
    CONSTRAINT UC_Visit UNIQUE (ClientID, VisitDate),
    FOREIGN KEY (ClientID) REFERENCES Client(ClientID),
    FOREIGN KEY (PropertyID) REFERENCES Property(PropertyID)
);

-- Create Comment table
CREATE TABLE Comment (
    CommentID INT PRIMARY KEY,
    CommentText TEXT,
    VisitID INT NOT NULL,
    FOREIGN KEY (VisitID) REFERENCES Visit(VisitID)
);
