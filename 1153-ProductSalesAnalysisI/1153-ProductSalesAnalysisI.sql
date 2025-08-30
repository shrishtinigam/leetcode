-- Last updated: 8/30/2025, 8:18:22 PM
# Write your MySQL query statement below
SELECT Product.product_name, Sales.year, Sales.price FROM Sales 
LEFT JOIN Product
ON Sales.product_id = Product.product_id