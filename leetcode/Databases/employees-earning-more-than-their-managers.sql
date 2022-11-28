# Write your MySQL query statement below

SELECT first.name as Employee
FROM Employee as first
INNER JOIN Employee as second ON first.managerId = second.id
WHERE first.salary > second.salary
