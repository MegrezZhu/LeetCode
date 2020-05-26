# Write your MySQL query statement below
SELECT c.class
FROM courses c
GROUP BY c.class
HAVING count(DISTINCT c.student) >= 5