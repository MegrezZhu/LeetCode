# Write your MySQL query statement below
SELECT Name AS Customers
FROM Customers
WHERE Id NOT IN (
    SELECT c.id
    FROM Customers c
    INNER JOIN Orders o
    ON o.CustomerId = c.id
)
