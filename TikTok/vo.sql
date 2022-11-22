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

