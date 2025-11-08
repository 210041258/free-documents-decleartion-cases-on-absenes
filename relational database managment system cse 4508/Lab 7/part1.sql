-- Retrieve and display the name and salary of the employee with ID 101
SELECT name, salary 
FROM employees 
WHERE employee_id = 101;

-- Create a function called get_employee_count that returns the total number of employees in a given department
CREATE FUNCTION get_employee_count(p_department_id INT)
RETURNS INT
BEGIN
    DECLARE v_count INT;
    SELECT COUNT(*) INTO v_count 
    FROM employees 
    WHERE department_id = p_department_id;

    RETURN v_count;
END;

-- Create a trigger named update_hire_date_trg that automatically updates the last_hire_date in the departments table
CREATE TRIGGER update_hire_date_trg
AFTER INSERT OR UPDATE ON employees
FOR EACH ROW
BEGIN
    DECLARE v_last_hire_date DATE;
    SELECT last_hire_date INTO v_last_hire_date 
    FROM departments 
    WHERE department_id = NEW.department_id;

    IF v_last_hire_date IS NULL OR NEW.hire_date > v_last_hire_date THEN
        UPDATE departments
        SET last_hire_date = NEW.hire_date
        WHERE department_id = NEW.department_id;
    END IF;
END;

-- Display the names of all employees in department_id
DECLARE v_name VARCHAR(255);
DECLARE emp_cursor CURSOR FOR 
    SELECT name FROM employees WHERE department_id = 2;

OPEN emp_cursor;
LOOP
    FETCH emp_cursor INTO v_name;
    IF done THEN
        LEAVE;
    END IF;
    SELECT v_name;
END LOOP;
CLOSE emp_cursor;
    v_last_hire_date DATE;
BEGIN
    SELECT last_hire_date INTO v_last_hire_date 
    FROM departments 
    WHERE department_id = :NEW.department_id;

    IF v_last_hire_date IS NULL OR :NEW.hire_date > v_last_hire_date THEN
        UPDATE departments
        SET last_hire_date = :NEW.hire_date
        WHERE department_id = :NEW.department_id;
    END IF;
END;
/




/*Write a PL/SQL block using a cursor to display the names of all employees in department_id*/

DECLARE 
    v_name employees.name%TYPE;
    CURSOR emp_cursor IS 
        SELECT name FROM employees WHERE department_id = 2;
BEGIN
    OPEN emp_cursor;
    LOOP
        FETCH emp_cursor INTO v_name;
        EXIT WHEN emp_cursor%NOTFOUND;
        DBMS_OUTPUT.PUT_LINE('Employee Name: ' || v_name);
    END LOOP;
    CLOSE emp_cursor;
END;
/









