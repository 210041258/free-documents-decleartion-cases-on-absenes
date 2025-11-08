SELECT customer_city
FROM customer
WHERE customer_customer_city LIKE '%f%' AND customer_city LIKE '%d';

SELECT customer_name, customer_city
FROM customer
WHERE customer_name IN (
    SELECT DISTINCT L.customer_name
    FROM loan L
    WHERE L.customer_name NOT IN (
        SELECT DISTINCT A.customer_name
        FROM account A
    )
);

SELECT *
FROM customer
WHERE customer_name IN (
    SELECT DISTINCT customer_name
    FROM account
    UNION
    SELECT DISTINCT customer_name
    FROM loan
);

SELECT SUM(assets) AS tot
FROM branch;

SELECT B.branch_name, COUNT(A.account_number) AS tot
FROM branch B
LEFT JOIN account A ON B.branch_name = A.branch_name
GROUP BY B.branch_name;

SELECT C.customer_name, A.account_number
FROM customer C
JOIN account A ON C.customer_name = A.customer_name
WHERE ROWNUM = 1
ORDER BY A.balance DESC;

SELECT B.branch_name, AVG(A.balance) AS Averagebalance
FROM branch B
JOIN account A ON B.branch_name = A.branch_name
GROUP BY B.branch_name
ORDER BY B.branch_name ASC, Averagebalance DESC;

SELECT customer_city, COUNT(customer_name) AS NumberOfcustomer
FROM customer
WHERE customer_name IN (
    SELECT DISTINCT C1.customer_name
    FROM customer C1
    JOIN depositor D ON C1.customer_name = D.customer_name
    JOIN loan L ON C1.customer_name = L.customer_name
)
GROUP BY customer_city;


SELECT B.branch_name, AVG(L.amount) AS Averageamount
FROM branch B
JOIN loan L ON B.branch_name = L.branch_name
WHERE B.branch_city NOT LIKE '%Horse%'
GROUP BY B.branch_name;

SELECT C.customer_name, C.customer_city, A.account_number, B.branch_city
FROM customer C
JOIN account A ON C.customer_name = A.customer_name
JOIN branch B ON A.branch_name = B.branch_name
WHERE C.customer_city = B.branch_city;


SELECT B.branch_name
FROM branch B
JOIN account A ON B.branch_name = A.branch_name
GROUP BY B.branch_name
HAVING SUM(A.balance) > (
    SELECT AVG(Totalbalance)
    FROM (
        SELECT SUM(A.balance) AS Totalbalance
        FROM branch B
        JOIN account A ON B.branch_name = A.branch_name
        GROUP BY B.branch_name
    ) AS tot
);

SELECT B.branch_name
FROM branch B
JOIN account A ON B.branch_name = A.branch_name
JOIN customer C ON A.customer_name = C.customer_name
GROUP BY B.branch_name
HAVING SUM(A.balance) > SUM(L.amount);

SELECT DISTINCT C.customer_name
FROM customer C
JOIN loan L ON C.customer_name = L.customer_name
WHERE L.amount <= (
    SELECT SUM(A.balance)
    FROM account A
    WHERE A.customer_name = C.customer_name
);

SELECT C.customer_name, A.balance, L.amount
FROM customer C
JOIN account A ON C.customer_name = A.customer_name
JOIN loan L ON C.customer_name = L.customer_name
JOIN branch B1 ON C.customer_city != B1.branch_city
JOIN branch B2 ON A.branch_name = B2.branch_name
WHERE B1.branch_name != B2.branch_name;

SELECT DISTINCT C.customer_name
FROM customer C
JOIN account A ON C.customer_name = A.customer_name
JOIN branch B ON A.branch_name = B.branch_name
WHERE B.assets = (
    SELECT MAX(assets)
    FROM branch
);
