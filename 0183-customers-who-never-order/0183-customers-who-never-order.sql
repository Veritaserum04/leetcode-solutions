# Write your MySQL query statement below
SELECT C.name as Customers
FROM Customers AS C LEFT JOIN Orders as O
ON C.id=O.customerId
WHERE O.customerId IS NULL;