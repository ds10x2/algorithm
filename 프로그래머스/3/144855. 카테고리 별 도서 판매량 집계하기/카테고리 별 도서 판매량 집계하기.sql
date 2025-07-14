-- 코드를 입력하세요
SELECT b.category, SUM(s.sales) as "TOTAL_SALES"
FROM Book b, book_sales s
WHERE b.book_id = s.book_id
and year(s.sales_date) = "2022" and month(s.sales_date) = '01'
GROUP BY b.category
ORDER BY b.category