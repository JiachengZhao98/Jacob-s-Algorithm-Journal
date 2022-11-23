-- LC 180. Consecutive Numbers
SELECT DISTINCT
    l1.num AS ConsecutiveNums
FROM
    Logs l1, Logs l2, Logs l3
WHERE
    l1.Id = l2.Id - 1
    AND l2.id = l3.id - 1
    AND l1.num = l2.num
    AND l2.num = l3.num


-- LC 177. Nth Highest Salary
CREATE FUNCTION getNthHighestSalary(N INT) RETURNS INT
BEGIN
  set N = N - 1;
  RETURN (
      -- Write your MySQL query statement below.
      SELECT
    (SELECT DISTINCT
            salary
        FROM
            Employee
        ORDER BY salary DESC
        LIMIT 1 OFFSET N) AS 'getNthHighestSalary(n)'
  );
END

-- LC 175. Combine Two Tables
select firstName, lastName, city, state from Person
left join Address on Person.personId = Address.personId
ORDER by Person.personId


-- LC 181. Employees Earning More Than Their Managers
SELECT
    e1.name AS Employee
FROM
    Employee e1, Employee e2
WHERE
    e1.managerId = e2.id
    AND e1.salary > e2.salary


-- LC 182. Duplicate Emails
SELECT DISTINCT
    p1.email AS Email
FROM
    Person p1, Person p2
where
    p1.id != p2.id
    AND p1.email == p2.email


-- 183. Customers Who Never Order
SELECT
    Customers.name AS Customers
FROM
    Customers
WHERE
    Customers.id not in
    (
        SELECT customerId FROM Orders
    )


-- 184. Department Highest Salary
SELECT
    d1.name AS Department,
    e1.name AS Employee,
    e1.salary AS Salary
FROM
    Department d1, Employee e1
WHERE
    d1.id = e1.departmentId
    AND e1.salary = (SELECT max(salary) FROM Employee e2 WHERE e2.departmentId = e1.departmentId)


-- 185. Department Top Three Salaries
SELECT
    d1.name AS Department,
    e1.name AS Employee,
    e1.salary AS Salary
FROM
    Employee e1
JOIN
    Department d1
ON
    d1.id = e1.departmentId
WHERE
    3 > (
        SELECT
            COUNT(DISTINCT(e2.salary))
        FROM
            Employee e2
        WHERE
            e1.salary < e2.salary
            AND e1.departmentId = e2.departmentId  -- this query is to find the salary in Table Employee that has less
                                                   -- than 3 elements which are greater than itself, i.e., the 3 largest ones in the table
    )


-- 196. Delete Duplicate Emails
DELETE
    p1
FROM
    Person p1, Person p2
WHERE
    p1.id != p2.id
    AND p1.email = p2.email
