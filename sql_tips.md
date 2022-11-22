# Tips when I solve database problems on leetcode

## LC 180. Consecutive Numbers

- we can SELECT multiple datasets to use

```
SELECT DISTINCT
    l1.num AS ConsecutiveNums
FROM
    Logs l1, Logs l2, Logs l3
```


