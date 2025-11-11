-- task1



/*
Creates a table named Account with columns: Ac_id (Primary Key), acc_code (Foreign Key referencing AccountProperty), and opendate.
*/
CREATE TABLE Account (
    Ac_id VARCHAR(20) PRIMARY KEY,
    acc_code VARCHAR(4) REFERENCES AccountProperty(acc_code),
    opendate DATE
);


/*
Creates a table named Balance with columns: Ac_id (Primary Key), pca, and profit.
*/
CREATE TABLE Balance (
    Ac_id VARCHAR(20) PRIMARY KEY,
    pca DECIMAL(10, 2),
    profit DECIMAL(10, 2)
);


/*
Creates a table named AccountProperty with columns: acc_code (Primary Key), Name, rate, and period.
*/
CREATE TABLE AccountProperty (
    acc_code VARCHAR(4) PRIMARY KEY,
    Name VARCHAR(255),
    rate DECIMAL(5, 2),
    period INT
);


/* Defines a function generate_Ac_id that takes p_Name, p_acc_code, and p_opendate as parameters and returns a formatted Ac_id.
It concatenates p_acc_code, formatted p_opendate, first three characters of p_Name, and the next value from the sequence named account_sequence. */
-- task2

CREATE OR REPLACE FUNCTION generate_Ac_id(
    p_Name VARCHAR(255),
    p_acc_code VARCHAR(4),
    p_opendate DATE
) RETURNS VARCHAR(20)
AS $$
BEGIN
RETURN p_acc_code || TO_CHAR(p_opendate, 'YYYYMMDD') || '.' || LEFT(p_Name, 3) || '.' || NEXTVAL('account_sequence');
END;
$$ LANGUAGE plpgsql;

CREATE SEQUENCE account_sequence START 1;

-- task 3
/*
Adds a new column named Ac_id to the Account table.
Updates the Ac_id column in the Account table using the generate_Ac_id function.
Drops the acc_code column from the Account table.
*/
ALTER TABLE Account ADD COLUMN Ac_id VARCHAR(20);
UPDATE Account SET Ac_id = generate_Ac_id(Name, acc_code, opendate);
ALTER TABLE Account DROP COLUMN acc_code;

-- group of trigger commands
-- task 1
-- trigger for before each insert in table account
-- for each row
/*
Defines a function assign_Ac_id that sets the Ac_id before an insert operation on the Account table.
Creates a trigger named trigger_assign_Ac_id that executes the assign_Ac_id function before each insert on the Account table.
*/
CREATE OR REPLACE FUNCTION assign_Ac_id()
RETURNS TRIGGER AS $$
BEGIN
NEW.Ac_id = generate_Ac_id(NEW.Name, OLD.acc_code, NEW.opendate);
-- here the account will be generate for him account id
RETURN NEW;
END;
$$ LANGUAGE plpgsql;
-- normal format for trigger part
CREATE TRIGGER trigger_assign_Ac_id
BEFORE INSERT ON Account
FOR EACH ROW
EXECUTE FUNCTION assign_Ac_id();

-- task 2
-- trigger for after each insert in table account
/*
Defines a function initialize_balance that inserts an initial balance after an insert operation on the Account table.
Creates a trigger named trigger_initialize_balance that executes the initialize_balance function after each insert on the Account table.
*/
CREATE OR REPLACE FUNCTION initialize_balance()
RETURNS TRIGGER AS $$
BEGIN
INSERT INTO Balance (Ac_id, pca, profit)
VALUES (NEW.Ac_id, 5000, 0);
-- here each insert will have 5000 with in it's account
RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_initialize_balance
AFTER INSERT ON Account
FOR EACH ROW
EXECUTE FUNCTION initialize_balance();

-- task 3
-- trigger for AFTER each insert in table TransactionTable
/*
Defines a function update_principal_amount that updates the pca in the Balance table after an insert operation on the TransactionTable.
Creates a trigger named trigger_update_principal_amount that executes the update_principal_amount function after each insert on the TransactionTable.
*/
CREATE OR REPLACE FUNCTION update_principal_amount()
RETURNS TRIGGER AS $$
BEGIN
UPDATE Balance
-- new value will be new = new+ pca
SET pca = pca + NEW.amount
WHERE Ac_id = NEW.Ac_id;

RETURN NEW;
END;
$$ LANGUAGE plpgsql;

CREATE TRIGGER trigger_update_principal_amount
AFTER INSERT ON TransactionTable -- Replace with your actual transaction table name
FOR EACH ROW
EXECUTE FUNCTION update_principal_amount();

