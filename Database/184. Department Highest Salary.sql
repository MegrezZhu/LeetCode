# Write your MySQL query statement below
SELECT d.Name AS Department, e.Name As Employee, e.Salary
FROM (
    SELECT d.Id, d.Name, MAX(e.Salary) as max_salary
    FROM Employee e
        INNER JOIN Department d
        ON e.DepartmentId=d.Id
    GROUP BY d.Id
) d, Employee e
WHERE d.Id=e.DepartmentId AND e.Salary=d.max_salary