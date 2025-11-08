

-- Create Division table
CREATE TABLE Division (
    division_id INT PRIMARY KEY,
    division_name VARCHAR(255) NOT NULL
);

-- Create District table
CREATE TABLE District (
    district_id INT PRIMARY KEY,
    district_name VARCHAR(255) NOT NULL,
    division_id INT,
    FOREIGN KEY (division_id) REFERENCES Division(division_id)
);

-- Create Branch table
CREATE TABLE Branch (
    branch_id INT PRIMARY KEY,
    branch_name VARCHAR(255) NOT NULL,
    district_id INT,
    FOREIGN KEY (district_id) REFERENCES District(district_id)
);

-- Create Department table
CREATE TABLE Department (
    department_id INT PRIMARY KEY,
    department_name VARCHAR(255) NOT NULL
);

-- Create Employee table
CREATE TABLE Employee (
    employee_id INT PRIMARY KEY,
    employee_name VARCHAR(255) NOT NULL,
    dob DATE NOT NULL,
    contact_no VARCHAR(20) NOT NULL,
    branch_id INT,
    department_id INT,
    FOREIGN KEY (branch_id) REFERENCES Branch(branch_id),
    FOREIGN KEY (department_id) REFERENCES Department(department_id)
);

-- Create Customer table
CREATE TABLE Customer (
    customer_id INT PRIMARY KEY,
    customer_name VARCHAR(255) NOT NULL,
    contact_no VARCHAR(20) NOT NULL,
    address VARCHAR(255) NOT NULL
);

-- Create Item table
CREATE TABLE Item (
    item_id INT PRIMARY KEY,
    item_name VARCHAR(255) NOT NULL,
    description VARCHAR(255)NOT NULL,
    unit_price DECIMAL(10, 2) NOT NULL
);

-- Create ItemRental table
CREATE TABLE ItemRental (
    rental_id INT PRIMARY KEY,
    employee_id INT,
    item_id INT,
    start_date DATE NOT NULL,
    end_date DATE NOT NULL,
    FOREIGN KEY (employee_id) REFERENCES Employee(employee_id),
    FOREIGN KEY (item_id) REFERENCES Item(item_id)
);

-- Create Purchase table
CREATE TABLE Purchase (
    purchase_id INT PRIMARY KEY,
    customer_id INT,
    item_id INT,
    purchase_date DATE NOT NULL,
    FOREIGN KEY (customer_id) REFERENCES Customer(customer_id),
    FOREIGN KEY (item_id) REFERENCES Item(item_id)
);


--Find the list of divisions along with the total number of districts.
SELECT D.division_name, COUNT(DISTINCT D.district_id) AS total_districts
FROM Division D
LEFT JOIN District Di ON D.division_id = Di.division_id
GROUP BY D.division_name;


--Find the list of districts having at least 200 customers living there:

SELECT D.district_name
FROM District D
JOIN Customer C ON D.district_id = C.district_id
GROUP BY D.district_name
HAVING COUNT(C.customer_id) >= 200;

-- c) Find the number of items bought by a customer named "Alfred":

SELECT C.customer_name, COUNT(P.item_id) AS total_items_bought
FROM Customer C
LEFT JOIN Purchase P ON C.customer_id = P.customer_id
WHERE C.customer_name = 'Alfred'
GROUP BY C.customer_name;


-- (d) Find the list of employees based on the number of items they have rented so far:

SELECT E.employee_name, COUNT(IR.item_id) AS total_items_rented
FROM Employee E
LEFT JOIN ItemRental IR ON E.employee_id = IR.employee_id
GROUP BY E.employee_name
ORDER BY total_items_rented DESC;


--(e) Find the employee who had rented items for the longest period of time:

SELECT E.employee_name, MAX(DATEDIFF(end_date, start_date)) AS max_rental_duration
FROM Employee E
JOIN ItemRental IR ON E.employee_id = IR.employee_id
GROUP BY E.employee_name
ORDER BY max_rental_duration DESC
LIMIT 1;
