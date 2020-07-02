# Write your MySQL query statement below
SELECT e.Name as Employee
FROM Employee e
INNER JOIN Employee m ON e.ManagerId = m.Id AND e.Salary > m.Salary;