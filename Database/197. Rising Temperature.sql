# Write your MySQL query statement below
select w2.Id
from Weather w1, Weather w2
where w1.RecordDate = DATE_ADD(w2.RecordDate, INTERVAL -1 DAY) and w1.Temperature < w2.Temperature