
-- Create Branch table
CREATE TABLE Branch (
    BranchID INT PRIMARY KEY,
    Street VARCHAR(255),
    City VARCHAR(255),
    Postcode VARCHAR(10)
);

-- Create Employee table
CREATE TABLE Employee (
    EmployeeID INT PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    Gender CHAR(1),
    DateOfBirth DATE,
    Position VARCHAR(255),
    Salary DECIMAL(10, 2),
    BranchID INT,
    FOREIGN KEY (BranchID) REFERENCES Branch(BranchID)
);

-- Create Client table
CREATE TABLE Client (
    ClientID INT PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    TelephoneNumber VARCHAR(20),
    Email VARCHAR(255),
    PreferredAccommodationType VARCHAR(255),
    MaxRentAmount DECIMAL(10, 2)
);

-- Create PropertyOwner table
CREATE TABLE PropertyOwner (
    OwnerID INT PRIMARY KEY,
    FirstName VARCHAR(255),
    LastName VARCHAR(255),
    TelephoneNumber VARCHAR(20),
    Email VARCHAR(255),
    Password VARCHAR(255)
);

-- Create Property table
CREATE TABLE Property (
    PropertyID INT PRIMARY KEY,
    Street VARCHAR(255),
    City VARCHAR(255),
    Postcode VARCHAR(10),
    Type VARCHAR(255),
    NumAvailableRooms INT,
    Rent DECIMAL(10, 2),
    OwnerID INT,
    ContactPersonEmployeeID INT,
    BranchID INT,
    FOREIGN KEY (OwnerID) REFERENCES PropertyOwner(OwnerID),
    FOREIGN KEY (ContactPersonEmployeeID) REFERENCES Employee(EmployeeID),
    FOREIGN KEY (BranchID) REFERENCES Branch(BranchID)
);

-- Create Visit table
CREATE TABLE Visit (
    VisitID INT PRIMARY KEY,
    DateOfVisit DATE,
    ClientID INT,
    PropertyID INT,
    UNIQUE (DateOfVisit, ClientID), -- Ensures a client can't visit twice in a day
    FOREIGN KEY (ClientID) REFERENCES Client(ClientID),
    FOREIGN KEY (PropertyID) REFERENCES Property(PropertyID)
);

-- Create Comment table
CREATE TABLE Comment (
    CommentID INT PRIMARY KEY,
    VisitID INT,
    CommentText TEXT,
    FOREIGN KEY (VisitID) REFERENCES Visit(VisitID)
);