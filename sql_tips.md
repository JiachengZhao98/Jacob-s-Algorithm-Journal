# Tips when I solve database problems on leetcode

## LC 180. Consecutive Numbers

- we can SELECT multiple datasets to use

```
SELECT DISTINCT
    l1.num AS ConsecutiveNums
FROM
    Logs l1, Logs l2, Logs l3
```


## LC 196. Delete Duplicate Emails

- When we need to delete one whole query in a table, we simply write:

```
DELETE
    p1 -- delete the whole query in this table
FROM
    Person p1, Person p2
WHERE
    p1.id != p2.id
    AND p1.email = p2.email
```
