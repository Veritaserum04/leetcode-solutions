# Write your MySQL query statement below
SELECT D.name as Department,E.name as Employee ,E.salary as Salary
FROM Employee as E JOIN Department as D
ON E.departmentId=D.id
WHERE E.salary = (
    SELECT MAX(salary)
    FROM Employee
    WHERE departmentid=E.departmentId
);