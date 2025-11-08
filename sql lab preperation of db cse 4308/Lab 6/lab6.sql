
CREATE VIEW Advisor_Selection AS
SELECT i.ID, i.name, i.dept_name
FROM instructor i;



CREATE VIEW Student_Count AS
SELECT a.name AS instructor_name, COUNT(*) AS student_count
FROM Advisor_Selection a
JOIN advisor adv ON a.ID = adv.i_ID
GROUP BY a.name;



--- Create roles for each of (student , teacher , heads , admins ) info
CREATE ROLE Student;
CREATE ROLE CourseTeacher;
CREATE ROLE DepartmentHead;
CREATE ROLE Administrator;
--- giving the access to the student to each of (advisor info and course info )
GRANT SELECT ON Advisor_Selection TO Student;
GRANT SELECT ON course TO Student;
-- Grant privileges to the CourseTeacher role
GRANT SELECT ON takes TO CourseTeacher;
GRANT SELECT ON course TO CourseTeacher;
-- Grant privileges to the DepartmentHead role
GRANT SELECT ON takes TO DepartmentHead;
GRANT SELECT ON course TO DepartmentHead;
-- Add privilege to add new instructors
GRANT INSERT, SELECT ON instructor TO DepartmentHead;
-- Grant privileges to the Administrator role
GRANT SELECT ON department TO Administrator;
GRANT SELECT ON instructor TO Administrator;
-- Add privilege to update department budget
GRANT UPDATE (budget) ON department TO Administrator;
-- Assign users to roles
GRANT Student TO students;
GRANT CourseTeacher TO teachers;
GRANT DepartmentHead TO heads;
GRANT Administrator TO admins;



-- Create sample users
CREATE USER students PASSWORD EXPIRE IDENTIFIED BY SYSTEM;
CREATE USER teachers PASSWORD EXPIRE IDENTIFIED BY SYSTEM;
CREATE USER heads PASSWORD EXPIRE IDENTIFIED BY SYSTEM;
CREATE USER admins PASSWORD EXPIRE IDENTIFIED BY SYSTEM;

-- Assign users to roles
GRANT Student TO students;
GRANT CourseTeacher TO teachers;
GRANT DepartmentHead TO heads;
GRANT Administrator TO admins;

-- Login as the student user
SET ROLE Student;

-- Query to view advisors
SELECT * FROM Advisor_Selection;

-- Query to view courses
SELECT * FROM course;
-- Login as the course teacher user
SET ROLE CourseTeacher;

-- Query to view students (takes table)
SELECT * FROM takes;

-- Query to view courses
SELECT * FROM course;

-- Login as the department head user
SET ROLE DepartmentHead;

-- Query to view students (takes table)
SELECT * FROM takes;

-- Query to view courses
SELECT * FROM course;

-- Query to add a new instructor
INSERT INTO instructor (ID, name, dept_name, salary) VALUES ('99999', 'New Instructor', 'Comp. Sci.', 80000);

-- Login as the administrator user
SET ROLE Administrator;

-- Query to view departments
SELECT * FROM department;

-- Query to view instructors
SELECT * FROM instructor;

-- Query to update department budget (example)
UPDATE department SET budget = 95000 WHERE dept_name = 'Comp. Sci.';
